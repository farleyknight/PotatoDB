#pragma once


class ColumnData {
public:
  ColumnData(const Buffer& buffer)
    : buffer_ (buffer)
  {}

  void read_column_oid() {
    
  }

  void write_column_oid() {
    
  }

  void read_column_name() {
    
  }

  void write_column_name() {
    
  }

  void read_nullable() {
    
  }

  void write_nullable() {
    
  }

  void read_autoincrement() {
    
  }

  void write_autoincrement() {
    
  }

  void read_primary_key() {
    
  }

  void write_primary_key() {
    
  }

private:
  const Buffer& buffer_;
  
  column_name_t name_;
  column_oid_t column_oid_;
  TypeId type_id_ = TypeId::INVALID;
}

