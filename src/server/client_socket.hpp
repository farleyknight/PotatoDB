#pragma once

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <stdexcept>

#include "common/types.hpp"

#include "server/socket_server.hpp"
#include "server/session.hpp"

class ClientSocket {
public:
  ClientSocket(file_desc_t file_desc,
               SocketServer* server,
               Session session);
  ~ClientSocket() = default;

  int file_desc() const;
  void shutdown();
  void write(CRef<string> data) const;
  string read() const;
  string process_request(string message) const;

  // No copy
  ClientSocket(CRef<ClientSocket>) = delete;
  // No copy assign
  ClientSocket& operator=(CRef<ClientSocket>) = delete;

  Session& session() {
    return session_;
  }

private:
  file_desc_t file_desc_ = -1;
  SocketServer* server_;
  Session session_;
};
