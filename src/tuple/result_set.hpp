#pragma once

class ResultSet {
public:
  ResultSet()
    : schema_ (QuerySchema::empty())
  {}

  ResultSet(vector<Tuple>&& results, QuerySchema schema)
    : schema_  (schema),
      results_ (move(results)) {}

  // No copy
  ResultSet(const ResultSet&) = delete;
  // No copy assign
  ResultSet& operator=(const ResultSet&) = delete;
  ~ResultSet() = default;

  static ptr<ResultSet> empty() {
    return make_unique<ResultSet>();
  }

  template<typename T>
  T value(const string name, const Tuple& tuple) {
    return tuple.value(schema_, schema_.index_for(name)).as<T>();
  }

  template<typename T>
  T value_at(const string name, size_t index) {
    assert(results_.size() >= index + 1);
    return results_[index].value(schema_, schema_.index_for(name)).as<T>();
  }

  const vector<Tuple>& results() {
    return results_;
  }

  size_t size() {
    return results_.size();
  }

  const Tuple& operator[](uint32_t i) const {
    return results_[i];
  }

  const string to_string() {
    stringstream os;

    for (index_t i = 0; i < results_.size(); ++i) {
      if (i > 0) {
        os << ",\n";
      }
      os << results_[i].to_string(schema_);
    }

    return os.str();
  }

private:
  QuerySchema schema_;
  vector<Tuple> results_;
};
