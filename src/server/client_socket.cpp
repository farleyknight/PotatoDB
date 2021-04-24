#include "common/types.hpp"

#include "server/client_socket.hpp"
#include "server/server.hpp"

#include "txns/potato_session.hpp"

ClientSocket::ClientSocket(file_desc_t file_desc,
                           MRef<Server> server)
  : file_desc_ (file_desc),
    server_    (server) {}

int ClientSocket::file_desc() const {
  return file_desc_;
}

void ClientSocket::shutdown() {
  server_.remove_socket(file_desc_);
}

void ClientSocket::write(CRef<String> data) const {
  auto result = send(file_desc_,
                     reinterpret_cast<const void*>(data.c_str()),
                     data.size(),
                     0);

  if (result == -1) {
    throw std::runtime_error(string(strerror(errno)));
  }
}

const size_t buffer_size = 256;

MutString ClientSocket::process_request(MutString message) const {
  // TODO: We should NOT be hard-coding the filename like this.
  // In the future, we have a way to create a session without
  // having to specify a file. Perhaps we default to a sub-directory
  // under the user's home directory? We can place any DB files
  // under ~/.potatodb and use that for the catalog, the table heaps
  // and whatnot?
  PotatoSession session("local_file.db", 32);

  return session.execute(message);
}

MutString ClientSocket::read() const {
  MutString message;

  char buffer[buffer_size] = {0};
  ssize_t bytes = recv(file_desc_, buffer, sizeof(buffer), MSG_DONTWAIT);

  while (bytes > 0) {
    buffer[bytes] = 0;
    message += buffer;

    bytes = recv(file_desc_, buffer, sizeof(buffer), MSG_DONTWAIT);
  }

  return process_request(message);
}
