#include <iostream>

#include "common/types.hpp"
#include "server/client_socket.hpp"
#include "server/server.hpp"

Server server;

void handle_exit(UNUSED int signal) {
  server.shutdown();
}

const int port = 7878;

int main() {
  signal(SIGINT, handle_exit);

  std::cout << "Start PotatoDB Server (0.1.0)" << std::endl;
  server.set_port(port);
  server.on_read([&](WPtr<ClientSocket> socket_ptr) {
    if (auto socket = socket_ptr.lock()) {
      auto data = socket->read();
      std::cout << "Socket got data " << data << std::endl;
      socket->write(data);
    }
  });

  // TODO Allow port customization
  std::cout << "Server listening on port 7878.." << std::endl;
  server.accept_connections();

  return 0;
}
