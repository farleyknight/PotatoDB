#pragma once

#include <climits>
#include <condition_variable>
#include <mutex>

class RWLatch {
  using Mutex = std::mutex;
  using CondVar = std::condition_variable;
  static const uint32_t MAX_READERS = UINT_MAX;

public:
  RWLatch() = default;
  ~RWLatch() {
    std::lock_guard<Mutex> guard(mutex_);
  }

  void wlock() {
    std::unique_lock<Mutex> latch(mutex_);
    while (writer_entered_) {
      reader_.wait(latch);
    }
    writer_entered_ = true;
    while (reader_count_ > 0) {
      writer_.wait(latch);
    }
  }

  void wunlock() {
    std::lock_guard<Mutex> guard(mutex_);
    writer_entered_ = false;
    reader_.notify_all();
  }

  void rlock() {
    std::unique_lock<Mutex> latch(mutex_);
    while (writer_entered_ || reader_count_ == MAX_READERS) {
      reader_.wait(latch);
    }
    reader_count_++;
  }

  void runlock() {
    std::lock_guard<Mutex> guard(mutex_);
    reader_count_--;
    if (writer_entered_) {
      if (reader_count_ == 0) {
        writer_.notify_one();
      }
    } else {
      if (reader_count_ == MAX_READERS - 1) {
        reader_.notify_one();
      }
    }
  }

private:
  Mutex mutex_;
  CondVar writer_, reader_;
  uint32_t reader_count_ = 0;
  bool writer_entered_ = false;
};
