#include <errno.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <stdexcept>

#include "common/types.hpp"

class Server;

class ClientSocket {
public:
  ClientSocket(file_desc_t file_desc,
               MRef<Server> server);
  ~ClientSocket() = default;

  int file_desc() const;

  void shutdown();
  void write(CRef<string> data) const;
  string read() const;
  MutString parse_message(MutString message) const;

  // No copy
  ClientSocket(CRef<ClientSocket>) = delete;
  // No copy assign
  MRef<ClientSocket> operator=(CRef<ClientSocket>) = delete;
private:
  file_desc_t file_desc_ = -1;
  MRef<Server> server_;
};
