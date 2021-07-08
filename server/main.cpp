#include <iostream>

#include "common/types.hpp"

#include "server/client_socket.hpp"
#include "server/socket_server.hpp"
#include "server/potatodb.hpp"


void handle_exit(int signal) {
  potatodb.shutdown(signal);
}

int main() {
  signal(SIGINT, handle_exit);

  potatodb.startup();
  potatodb.start_server();

  return 0;
}
