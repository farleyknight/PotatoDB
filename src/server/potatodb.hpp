#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/resources.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

namespace fs = std::filesystem;

class PotatoDB {
public:
  PotatoDB() {
    setup_db_directory();
  }

  void shutdown(UNUSED int signal) {
    socket_server_.shutdown();
  }

  CRef<Session> make_session() {
    sessions_.emplace_back(this);
    return sessions_.back();
  }

  fs::path main_file_name() {
    return home_path() / ".potatodb" / "database.db";
  }

  fs::path config_file_name() {
    return home_path() / ".potatodb" / "potatodb.yml";
  }

  fs::path log_file_name() {
    return home_path() / ".potatodb" / "database.log";
  }

  fs::path home_path() {
    return std::getenv("HOME");
  }

private:

  MutString setup_db_directory() {
    fs::current_path(home_path());
    fs::create_directory(".potatodb");
    fs::current_path(home_path() / ".potatodb");

    if (!fs::exists(db_file_name())) {
      std::ofstream db_file(db_file_name());
      db_file << "";
      db_file.close();
    }
  }

  void startup() {
    // TODO: Add logging for this line
    std::cout << "Start PotatoDB Server (0.1.0)" << std::endl;
    socket_server_.set_port(port);
    socket_server_.on_read([&](WPtr<ClientSocket> socket_ptr) {
      if (auto client = socket_ptr.lock()) {
        auto query = client->read();
        std::cout << "Client Socket got query " << query << std::endl;

        try {
          auto result = client->session()->execute(query);
          client->write(result);
        } catch (std::runtime_exception &e) {
          // TODO: Send better error message
          client->write("Got an error! :(");
        }
      } else {
        // TODO: Logger
        std::cout << "Could not get lock!" << std::endl;
      }
    });

    // TODO: Allow port customization
    // TODO: Add logging for this line
    std::cout << "Server listening on port 7878.." << std::endl;
    socket_server.accept_connections();
  }

  SocketServer server_;
  Resource resources_;
  MutVec<Session> sessions_;
};
