
#include "disk/file_handle.hpp"

FileHandle::FileHandle(fs::path file_path)
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


void FileHandle::write_buffer(buffer_offset_t offset, const Buffer& buffer) {
  std::cout << "WRITE WRITE WRITE WRITE WRITE: " << file_path() << std::endl;
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
  std::cout << "WRITE WRITE WRITE WRITE WRITE: " << file_path() << std::endl;
}

void FileHandle::print_status() const {
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

void FileHandle::read_buffer(buffer_offset_t offset, Buffer& buffer) {
  std::cout << "READ READ READ READ READ READ READ: " << file_path() << std::endl;
  std::cout << "Before seekg, what is file status?" << std::endl;
  print_status();

  handle_.seekg(offset);

  std::cout << "Before read, what is file status?" << std::endl;
  print_status();

  auto min_size = (1 + offset) * buffer.size();

  if (size() < min_size) {
    fs::resize_file(file_path_, min_size);
  }

  handle_.read(buffer.char_ptr(), buffer.size());

  std::cout << "File size is " << size() << std::endl;
  std::cout << "Buffer size is " << buffer.size() << std::endl;
  std::cout << "After read, what is file status?" << std::endl;
  print_status();
  std::cout << "READ READ READ READ READ READ READ: " << file_path() << std::endl;
}
