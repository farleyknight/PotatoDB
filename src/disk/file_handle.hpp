#pragma once

class FileHandle {
public:
  FileHandle(fs::path file_path)
    : file_path_ (file_path)
  {
    if (!fs::exists(file_path)) {
      create();
    }
    open();
  }

  void create() {
    handle_.open(file_path_,
                 std::ios::binary |
                 std::ios::trunc |
                 std::ios::app |
                 std::ios::out);

    handle_.close();
  }

  void open() {
    handle_.open(file_path_,
                 std::ios::binary |
                 std::ios::trunc |
                 std::ios::app |
                 std::ios::out);
  }

  void close() {
    handle_.close();
  }

  ~FileHandle() {
    close();
  }

private:
  fs::path file_path_;
  fstream handle_;
};
