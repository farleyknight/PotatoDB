#include <errno.h>
#include <string.h>
#include <iostream>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <unistd.h>

#include <algorithm>
#include <future>
#include <memory>
#include <stdexcept>
#include <string>

#include "server/client_socket.hpp"
#include "server/socket_server.hpp"
#include "server/potatodb.hpp"

SocketServer::SocketServer(PotatoDB* instance)
  : instance_ (instance)
{}

SocketServer::~SocketServer() {
  shutdown();
}

void SocketServer::set_backlog(int backlog) {
  backlog_ = backlog;
}

void SocketServer::set_port(int port) {
  port_ = port;
}

void SocketServer::shutdown() {
  if (main_socket_ != 0) {
    close(main_socket_);
  }

  for (auto socket : sockets_) {
    socket->shutdown();
  }

  sockets_.clear();
}

void SocketServer::reuse_main_socket() const {
  int option = 1;

  setsockopt(main_socket_,
             SOL_SOCKET,
             SO_REUSEADDR,
             reinterpret_cast<const void*>(&option),
             sizeof(option));
}

void SocketServer::bind_main_socket_to_port() {
  sockaddr_in socket_addr;

  std::fill(reinterpret_cast<char*>(&socket_addr),
            reinterpret_cast<char*>(&socket_addr) + sizeof(socket_addr),
            0);

  socket_addr.sin_family      = AF_INET;
  socket_addr.sin_addr.s_addr = htonl(INADDR_ANY);
  socket_addr.sin_port        = htons(port_);

  int result = bind(main_socket_,
                    reinterpret_cast<const sockaddr*>(&socket_addr),
                    sizeof(socket_addr));

  if (result == -1) {
    throw std::runtime_error(string(strerror(errno)));
  }
}

void SocketServer::begin_accepting_connections() const {
  int result = listen(main_socket_, backlog_);

  if (result == -1) {
    throw std::runtime_error(string(strerror(errno)));
  }
}

void SocketServer::accept_new_connection() {
  sockaddr_in client_addr;
  auto client_addr_length = sizeof(client_addr);

  auto addr = reinterpret_cast<sockaddr*>(&client_addr);
  auto len  = reinterpret_cast<socklen_t*>(&client_addr_length);

  file_desc_t client_fd = accept(main_socket_, addr, len);

  if (client_fd == -1) {
    return;
  }

  FD_SET(client_fd, &main_socket_set_);
  new_high_fd_ = max(curr_high_fd_, client_fd);

  auto client_socket = make_client_socket(client_fd);

  if (accept_func_) {
    auto task = std::async(std::launch::async,
                           accept_func_,
                           client_socket);
  }

  sockets_.push_back(client_socket);
}

shared_ptr<ClientSocket>
SocketServer::make_client_socket(file_desc_t client_fd) {
  return make_shared<ClientSocket>(client_fd,
                                   this,
                                   instance_->make_session());
}

void SocketServer::read_from_connection(file_desc_t fd) {
  char buffer[2] = {0,0};

  // Let's attempt to read at least one byte from the connection, but
  // without removing it from the queue. That way, the server can see
  // whether a client has closed the connection.
  int result = recv(fd, buffer, 1, MSG_PEEK);

  if( result <= 0 ) {
    // std::cout << "Stale socket FD : " << fd << std::endl;
    stale_fds_.push_back(fd);
  } else {
    // std::cout << "Read socket FD : " << fd << std::endl;
    if (read_func_) {
      fire_read_event(fd);
    }
  }
}

void SocketServer::prep_main_socket_set() {
  FD_ZERO(&main_socket_set_);
  FD_SET(main_socket_, &main_socket_set_);
  curr_high_fd_ = main_socket_;
}

const int one_second = 1;
UNUSED const int one_minute = 60;

bool SocketServer::update_socket_set() {
  struct timeval timeout = {one_second, 0};

  int fd_count = select(curr_high_fd_ + 1,
                        &client_socket_set_,
                        nullptr,  // no descriptors to write into
                        nullptr,  // no descriptors with exceptions
                        &timeout);

  // std::cout << "FD count: " << fd_count << std::endl;
  return (fd_count != -1);
}

void SocketServer::accept_connections() {
  main_socket_ = socket(AF_INET, SOCK_STREAM, 0);
  if (main_socket_ == -1) {
    throw std::runtime_error(string(strerror(errno)));
  }

  reuse_main_socket();
  bind_main_socket_to_port();
  begin_accepting_connections();
  prep_main_socket_set();

  // This set of IBM docs are really good for low-level networking stuff.
  // https://www.ibm.com/docs/en/i/7.2?topic=designs-example-nonblocking-io-select
  while(true) {
    client_socket_set_ = main_socket_set_;

    bool any_sockets_ready = update_socket_set();

    if (!any_sockets_ready) {
      break; // If no sockets are ready, try again
    }

    new_high_fd_ = curr_high_fd_;
    for (file_desc_t fd = 0; fd <= curr_high_fd_; ++fd) {
      // If the socket has no data, continue.
      if (!FD_ISSET(fd, &client_socket_set_)) {
        continue;
      }

      if (fd == main_socket_) {
        // Main server socket has data.
        // Read from it to connect a new client
        // std::cout << "Reading main socket" << std::endl;
        accept_new_connection();
      } else {
        // Known client socket sending request
        // Time to read!
        // std::cout << "Read from client" << std::endl;
        read_from_connection(fd);
      }
    }
    curr_high_fd_ = max(new_high_fd_, curr_high_fd_);

    // finish_tasks();
    stale_socket_cleanup();
  }
}

void SocketServer::finish_tasks() {
  std::for_each(tasks_.begin(), tasks_.end(), [](const Task& task) {
    task.wait();
  });
  tasks_.clear();
}

void SocketServer::fire_read_event(file_desc_t fd) {
  for (auto &socket : sockets_) {
    if (socket->file_desc() == fd) {
      // std::cout << "Reading from socket FD : " << fd << std::endl;
      // TODO: We may need to store the results (futures)
      // and `future.wait()` for them to finish. Otherwise
      // they might not be getting called?
      auto task = std::async(std::launch::async, read_func_, socket);
    }
  }
}

void SocketServer::stale_socket_cleanup() {
  std::lock_guard<mutex> lock(stale_fd_mutex_);

  for (auto fd : stale_fds_) {
    // std::cout << "Clearing FD : " << fd << std::endl;
    FD_CLR(fd, &main_socket_set_);
    close(fd);
  }

  stale_fds_.clear();
}

void SocketServer::remove_socket(file_desc_t fd) {
  // TODO: When we get a logging system working, add
  // the line below:
  // std::cout << "Closing socket FD : " << fd << std::endl;
  std::lock_guard<mutex> lock(stale_fd_mutex_);

  auto match_fd = [&](sptr<ClientSocket> socket) {
    return socket->file_desc() == fd;
  };

  sockets_.erase(std::remove_if(sockets_.begin(),
                                sockets_.end(),
                                match_fd),
                 sockets_.end());

  stale_fds_.push_back(fd);
}
