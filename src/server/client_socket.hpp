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
               MutRef<Server> server);
  ~ClientSocket() = default;

  int file_desc() const;

  void shutdown();
  void write(Ref<string> data) const;
  string read() const;

  // No copy
  ClientSocket(Ref<ClientSocket>) = delete;
  // No copy assign
  MutRef<ClientSocket> operator=(Ref<ClientSocket>) = delete;
private:
  file_desc_t file_desc_ = -1;
  MutRef<Server> server_;
};
