#pragma once

#include <filesystem>

#include "common/config.hpp"

#include "server/resources.hpp"

#include "server/session.hpp"
#include "server/socket_server.hpp"

namespace fs = std::filesystem;

class PotatoDB {
public:
  PotatoDB()
    : resources_ (db_file_name())
  {}

  void shutdown(UNUSED int signal) {
    socket_server_.shutdown();
  }

  CRef<Session> make_session() {
    sessions_.emplace_back(resources_);
    return sessions_.back();
  }

private:

  MutString db_file_name() {
    fs::current_path(home_path());
    fs::create_directory(".potatodb");
    fs::current_path(home_path() / ".potatodb");

    if (!fs::exists(db_file_name())) {
      std::ofstream db_file(db_file_name());
      // TODO: Puts some header info here, like the version number
      db_file << "0.1.0";
      db_file.close();
    }
  }

  fs::path db_file_name() {
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
