#pragma once

#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <stdexcept>

#include "common/types.hpp"

class Session;
class SocketServer;

class ClientSocket {
public:
  ClientSocket(file_desc_t file_desc,
               MRef<SocketServer> server,
               MRef<Session> session);
  ~ClientSocket() = default;

  int file_desc() const;
  void shutdown();
  void write(CRef<string> data) const;
  string read() const;
  MutString process_request(MutString message) const;

  // No copy
  ClientSocket(CRef<ClientSocket>) = delete;
  // No copy assign
  MRef<ClientSocket> operator=(CRef<ClientSocket>) = delete;

  MRef<Session> session() {
    return session_;
  }

private:
  file_desc_t file_desc_ = -1;
  MRef<SocketServer> server_;
  MRef<Session> session_;
};
