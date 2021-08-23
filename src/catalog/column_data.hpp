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
  UNUSED const Buffer& buffer_;
  
  column_name_t name_;
  UNUSED column_oid_t column_oid_;
  UNUSED TypeId type_id_ = TypeId::INVALID;
};

