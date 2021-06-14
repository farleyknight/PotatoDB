#pragma once

#include <filesystem>
#include <fstream>

#include "common/config.hpp"
#include "buffer/buffer.hpp"

namespace fs = std::filesystem;

class FileHandle {
public:
  FileHandle(fs::path file_path)
    : file_path_ (file_path)
  {
    if (!fs::exists(file_path)) {
      std::cout << "Creating file " << file_path.string() << std::endl;
      create();
    }

    std::cout << "Just before open" << std::endl;
    print_status();
    open();
    std::cout << "Just after open" << std::endl;
    print_status();
  }

  void write_buffer(buffer_offset_t offset, const Buffer& buffer) {
    std::cout << "Before seekp, what is file status?" << std::endl;
    print_status();

    handle_.seekp(offset);

    std::cout << "Before write, what is file status?" << std::endl;

    print_status();

    handle_.write(buffer.char_ptr(), buffer.size());

    std::cout << "Buffer size is " << buffer.size() << std::endl;
    std::cout << "After write, file size is now: " << size() << std::endl;
    std::cout << std::endl;

    print_status();

    handle_.flush();
  }

  void print_status() const {
    if (handle_.is_open()) {
      std::cout << "File is open" << std::endl;
    }

    if (handle_.good()) {
      std::cout << "File is good" << std::endl;
    }

    if (handle_.bad()) {
      std::cout << "File is bad" << std::endl;
    }

    if (handle_.fail()) {
      std::cout << "File is fail" << std::endl;
    }
  }

  void read_buffer(buffer_offset_t offset, Buffer& buffer) {
    std::cout << "Before seekg, what is file status?" << std::endl;
    print_status();

    handle_.seekg(offset);

    std::cout << "Before read, what is file status?" << std::endl;
    print_status();

    handle_.read(buffer.char_ptr(), buffer.size());

    std::cout << "After read, what is file status?" << std::endl;
    print_status();
  }

  void create() {
    handle_.open(file_path_, fstream::out);
    handle_ << "";
    handle_.close();
  }

  void open() {
    handle_.open(file_path_, fstream::in | fstream::out | fstream::binary);
  }

  void close() {
    handle_.close();
  }

  ~FileHandle() {
    close();
  }

  int size() const {
    return fs::file_size(file_path_);
  }

  const string file_path() const {
    return file_path_.string();
  }

private:
  fs::path file_path_;
  fstream handle_;
};
