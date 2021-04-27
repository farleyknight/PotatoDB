#include <iostream>

#include "common/types.hpp"

#include "server/client_socket.hpp"
#include "server/socket_server.hpp"
#include "server/potatodb.hpp"

PotatoDB potatodb;

void handle_exit(int signal) {
  potatodb.shutdown(signal);
}

const int port = 7878;

int main() {
  signal(SIGINT, handle_exit);

  potatodb.startup();

  return 0;
}
