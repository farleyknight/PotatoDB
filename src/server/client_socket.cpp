#include "common/types.hpp"

#include "server/client_socket.hpp"
#include "server/socket_server.hpp"
#include "server/session.hpp"

ClientSocket::ClientSocket(file_desc_t file_desc,
                           SocketServer* server,
                           Session session)
  : file_desc_ (file_desc),
    server_    (server),
    session_   (session)
{}

int ClientSocket::file_desc() const {
  return file_desc_;
}

void ClientSocket::shutdown() {
  server_->remove_socket(file_desc_);
}

void ClientSocket::write(const String& data) const {
  auto result = send(file_desc_,
                     reinterpret_cast<const void*>(data.c_str()),
                     data.size(),
                     0);

  if (result == -1) {
    throw std::runtime_error(string(strerror(errno)));
  }
}

const size_t buffer_size = 256;

MutString ClientSocket::read() const {
  string message;

  char buffer[buffer_size] = {0};
  ssize_t bytes = recv(file_desc_, buffer, sizeof(buffer), MSG_DONTWAIT);

  while (bytes > 0) {
    buffer[bytes] = 0;
    message += buffer;

    bytes = recv(file_desc_, buffer, sizeof(buffer), MSG_DONTWAIT);
  }

  return message;
}
