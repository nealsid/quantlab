#include "file_record.h"

FileRecord::FileRecord(long timestamp_us, string symbol, int quantity, int price) {
  this->timestamp_us = timestamp_us;
  this->symbol = symbol;
  this->quantity = quantity;
  this->price = price;
}


istream& operator>>(istream& is, FileRecord& out) {
  string line;
  getline(is, line);
  istringstream lineStream(line);
  string component;
  getline(lineStream, component, DELIMITER);
  out.setTimestampUs(stol(component));
  getline(lineStream, component, DELIMITER);
  out.setSymbol(component);
  getline(lineStream, component, DELIMITER);
  out.setQuantity(stoi(component));
  getline(lineStream, component, DELIMITER);
  out.setPrice(stoi(component));
  return is;
}
