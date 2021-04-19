#include <errno.h>
#include <string.h>

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
#include "server/server.hpp"

Server::~Server() {
  shutdown();
}

void Server::set_backlog(int backlog) {
  backlog_ = backlog;
}

void Server::set_port(int port) {
  port_ = port;
}

void Server::shutdown() {
  if (main_socket_ != 0) {
    close_socket(main_socket_);
  }

  for (auto socket : sockets_) {
    socket->shutdown();
  }

  sockets_.clear();
}

void Server::reuse_main_socket() const {
  int option = 1;

  setsockopt(main_socket_,
             SOL_SOCKET,
             SO_REUSEADDR,
             reinterpret_cast<const void*>(&option),
             sizeof(option));
}

void Server::bind_main_socket_to_port() {
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

void Server::begin_accepting_connections() const {
  int result = listen(main_socket_, backlog_);

  if (result == -1) {
    throw std::runtime_error(string(strerror(errno)));
  }
}

void Server::accept_new_connection() {
  sockaddr_in client_addr;
  auto client_addr_length = sizeof(client_addr);

  file_desc_t client_fd = accept(main_socket_,
                                 reinterpret_cast<sockaddr*>(&client_addr),
                                 reinterpret_cast<socklen_t*>(&client_addr_length));

  if (client_fd == -1) {
    return;
  }

  FD_SET(client_fd, &main_socket_set_);
  new_high_fd_ = max(curr_high_fd_, client_fd);

  auto client_socket = make_shared<ClientSocket>(client_fd, *this);

  if (accept_func_) {
    std::async(std::launch::async, accept_func_, client_socket);
  }

  sockets_.push_back(client_socket);
}

void Server::read_from_connection(file_desc_t fd) {
  char buffer[2] = {0,0};

  // Let's attempt to read at least one byte from the connection, but
  // without removing it from the queue. That way, the server can see
  // whether a client has closed the connection.
  int result = recv(fd, buffer, 1, MSG_PEEK);

  if( result <= 0 ) {
    // It would be easier to use erase-remove here, but this leads
    // to a deadlock. Instead, the current socket will be added to
    // the list of stale sockets and be closed later on.
    close_socket(fd);
  } else {
    if (read_func_) {
      fire_read_event(fd);
    }
  }
}

void Server::prep_main_socket_set() {
  FD_ZERO(&main_socket_set_);
  FD_SET(main_socket_, &main_socket_set_);
}

bool Server::update_socket_set() {
  int fd_count = select(curr_high_fd_ + 1,
                        &client_socket_set_,
                        nullptr,  // no descriptors to write into
                        nullptr,  // no descriptors with exceptions
                        nullptr); // no timeout
  
  return (fd_count == -1);
}

void Server::accept_connections() {
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
        accept_new_connection();
      } else {
        // Known client socket sending request
        // Time to read!
        read_from_connection(fd); 
      }
    }
    curr_high_fd_ = max(new_high_fd_, curr_high_fd_);

    stale_socket_cleanup();
  }
}

void Server::fire_read_event(file_desc_t fd) {
  for (auto &socket : sockets_) {
    if (socket->file_desc() == fd) {
      std::async(std::launch::async, read_func_, socket);
    }
  }
}

void Server::stale_socket_cleanup() {
  std::lock_guard<Mutex> lock(stale_fd_mutex_);

  for (auto fd : stale_fds_) {
    FD_CLR(fd, &main_socket_set_);
    close_socket(fd);
  }

  stale_fds_.clear();
}

void Server::close_socket(file_desc_t fd) {
  std::lock_guard<Mutex> lock(stale_fd_mutex_);

  auto match_fd = [&](SPtr<ClientSocket> socket) {
    return socket->file_desc() == fd;
  };

  sockets_.erase(std::remove_if(sockets_.begin(),
                                sockets_.end(),
                                match_fd),
                 sockets_.end());

  stale_fds_.push_back(fd);
}
