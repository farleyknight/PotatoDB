#pragma once

#include <functional>
#include <memory>
#include <mutex>
#include <vector>

#include "common/types.hpp"

class PotatoDB;
class ClientSocket;

class SocketServer {
public:
  using SocketFunc = function<void(weak_ptr<ClientSocket>)>;

  SocketServer(PotatoDB* instance);
  ~SocketServer();

  void set_backlog(int backlog);
  void set_port(int port);

  void shutdown();
  void accept_connections();
  void accept_new_connection();
  void remove_socket(file_desc_t fd);

  template<class F>
  void on_accept(Move<F> func) {
    accept_func_ = func;
  }

  template<class F>
  void on_read(Move<F> func) {
    read_func_ = func;
  }

private:
  void reuse_main_socket() const;
  void bind_main_socket_to_port();
  void begin_accepting_connections() const;
  void read_from_connection(file_desc_t fd);
  void fire_read_event(file_desc_t fd);
  void prep_main_socket_set();
  bool update_socket_set();
  void stale_socket_cleanup();
  void finish_tasks();

  sptr<ClientSocket> make_client_socket(file_desc_t client_fd);

  int         backlog_     =  5;
  int         port_        = -1;
  file_desc_t main_socket_ = -1;

  fd_set main_socket_set_, client_socket_set_;

  file_desc_t curr_high_fd_, new_high_fd_;

  SocketFunc accept_func_, read_func_;
  vector<shared_ptr<ClientSocket>> sockets_;

  vector<task> tasks_;

  // NOTE: Stale file descriptors are connections that can be dropped
  // Since another thread may be already accessing this vector, we
  // have a mutex, to ensure only one thread is accessing the vector
  // at a time.
  vector<file_desc_t> stale_fds_;
  mutex stale_fd_mutex_;
  PotatoDB* instance_;
};
