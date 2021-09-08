
#include "disk/file_handle.hpp"

FileHandle::FileHandle(file_id_t file_id, fs::path file_path)
  : file_id_   (file_id),
    file_path_ (file_path)
{
  if (!fs::exists(file_path)) {
    logger->debug("[FileHandle] Creating file " + file_path.string());
    create();
  }

  logger->debug("[FileHandle] Just before open");
  print_status();
  open();
  logger->debug("[FileHandle] Just after open");
  print_status();
}

void FileHandle::write_buffer(buffer_offset_t offset,
                              const Buffer& buffer)
{
  logger->debug("[FileHandle] Writing: " + file_path());
  logger->debug("[FileHandle] Before seekp, what is file status?");
  print_status();

  handle_.seekp(offset);

  logger->debug("[FileHandle] Before write, what is file status?");

  print_status();

  handle_.write(buffer.char_ptr(), buffer.size());

  logger->debug("[FileHandle] Buffer size is " + std::to_string(buffer.size()));
  logger->debug("[FileHandle] After write, file size is now: " + std::to_string(size()));

  print_status();

  handle_.flush();
  logger->debug("[FileHandle] Written: " + file_path());
}

void FileHandle::print_status() const {
  if (handle_.is_open()) {
    logger->debug("[FileHandle] >File is open");
  }

  if (handle_.bad()) {
    logger->debug("[FileHandle] >File is bad");
  }

  if (handle_.good()) {
    logger->debug("[FileHandle] >File is good");
  }

  if (handle_.fail()) {
    logger->debug("[FileHandle] >File has failed");
  }
}

void FileHandle::read_buffer(buffer_offset_t offset,
                             Buffer& buffer)
{
  // TODO: Clean up all of the debugging lines.
  logger->debug("[FileHandle] Reading: " + file_path());
  logger->debug("[FileHandle] Before seekg, what is file status?");
  print_status();

  logger->debug("[FileHandle] Offset is: " + std::to_string(offset));
  handle_.seekg(offset);

  logger->debug("[FileHandle] Before read, what is file status?");
  print_status();

  handle_.read(buffer.char_ptr(), buffer.size());

  logger->debug("[FileHandle] File size is " + std::to_string(size()));
  logger->debug("[FileHandle] Buffer size is " + std::to_string(buffer.size()));
  logger->debug("[FileHandle] After read, what is file status?");
  print_status();
  logger->debug("[FileHandle] Read: " + file_path());
  logger->flush();
}

bool
FileHandle::allocate_block(block_id_t block_id) {
  assert(block_id >= next_block_id_);
  next_block_id_ = block_id;

  auto new_size = next_block_id_ * PAGE_SIZE;
  return resize(new_size);
}

bool
FileHandle::deallocate_block(block_id_t block_id) {
  assert(block_id < next_block_id_);
  next_block_id_ = block_id;

  auto new_size = next_block_id_ * PAGE_SIZE;
  return resize(new_size);
}
