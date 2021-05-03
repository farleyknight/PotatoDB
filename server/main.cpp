#include <iostream>

#include "common/types.hpp"

#include "server/client_socket.hpp"
#include "server/socket_server.hpp"
#include "server/potatodb.hpp"

PotatoDB potatodb;

void handle_exit(int signal) {
  potatodb.shutdown(signal);
}

int main() {
  signal(SIGINT, handle_exit);

  potatodb.startup();

  return 0;
}
