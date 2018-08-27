#include "file_record.h"

#include <iostream>

FileRecord::FileRecord(long timestamp_us, string symbol, int quantity, int price) {
  this->timestamp_us = timestamp_us;
  this->symbol = symbol;
  this->quantity = quantity;
  this->price = price;
}


istream& operator>>(istream& is, FileRecord& out) {
  string line;
  getline(is, line);
  if (is.eof()) {
    out.setSymbol("");
    return is;
  }
  istringstream lineStream(line);
  string component;
  getline(lineStream, component, DELIMITER);

  out.setTimestampUs(stol(component));
  getline(lineStream, component, DELIMITER);
  out.setSymbol(component);
  getline(lineStream, component, DELIMITER);
  out.setQuantity(stod(component));
  getline(lineStream, component, DELIMITER);
  out.setPrice(stoi(component));
  return is;
}
