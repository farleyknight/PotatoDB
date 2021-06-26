
#include "disk/file_handle.hpp"

FileHandle::FileHandle(fs::path file_path)
  : file_path_ (file_path)
{
  if (!fs::exists(file_path)) {
    logger->debug("Creating file " + file_path.string());
    create();
  }

  logger->debug("Just before open");
  print_status();
  open();
  logger->debug("Just after open");
  print_status();
}


void FileHandle::write_buffer(buffer_offset_t offset,
                              const Buffer& buffer)
{
  logger->debug("WRITE WRITE WRITE WRITE WRITE: " + file_path());
  logger->debug("Before seekp, what is file status?");
  print_status();

  handle_.seekp(offset);

  logger->debug("Before write, what is file status?");

  print_status();

  handle_.write(buffer.char_ptr(), buffer.size());

  logger->debug("Buffer size is " + std::to_string(buffer.size()));
  logger->debug("After write, file size is now: " + std::to_string(size()));

  print_status();

  handle_.flush();
  logger->debug("WRITE WRITE WRITE WRITE WRITE: " + file_path());
}

void FileHandle::print_status() const {
  if (handle_.is_open()) {
    logger->debug(">File is open");
  }

  if (handle_.bad()) {
    logger->debug(">File is bad");
  }

  if (handle_.good()) {
    logger->debug(">File is good");
  }

  if (handle_.fail()) {
    logger->debug(">File has failed");
  }
}

void FileHandle::read_buffer(buffer_offset_t offset,
                             Buffer& buffer)
{
  logger->debug("READ READ READ READ READ READ READ: " + file_path());
  logger->debug("Before seekg, what is file status?");
  print_status();

  logger->debug("Offset is: " + std::to_string(offset));
  handle_.seekg(offset);

  logger->debug("Before read, what is file status?");
  print_status();

  auto min_size = (1 + offset) * buffer.size();

  if (size() < min_size) {
    fs::resize_file(file_path_, min_size);
  }

  handle_.read(buffer.char_ptr(), buffer.size());

  logger->debug("File size is " + std::to_string(size()));
  logger->debug("Buffer size is " + std::to_string(buffer.size()));
  logger->debug("After read, what is file status?");
  print_status();
  logger->debug("READ READ READ READ READ READ READ: " + file_path());
}
