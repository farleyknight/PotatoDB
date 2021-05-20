#pragma once

template<typename T>
class ListExpr {
public:
  ListExpr() = default;

  ListExpr(vector<T> list)
    : list_ (list) {}

  void push_back(T expr) {
    list_.push_back(expr);
  }

  void emplace_back(T&& expr) {
    list_.emplace_back(move(expr));
  }

  const vector<T>& list() const {
    return list_;
  }

  T& front() {
    return list_.front();
  }

  const T& front() const {
    return list_.front();
  }

  T& back() {
    return list_.back();
  }

  const T& back() const {
    return list_.back();
  }

  const string to_string() const {
    std::stringstream stream;
    stream << "[";

    for (size_t i = 0; i < list_.size(); ++i) {
      stream << list_[i].to_string();
      if (i != list_.size() - 1) {
        stream << ", ";
      }
    }

    stream << "]" << std::endl;;
    return stream.str();
  }

protected:
  vector<T> list_;
};
