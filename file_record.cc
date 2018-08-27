#include "file_record.h"

#include <cmath>
#include <iostream>

// Delimiter used in parsing the CSV file.
constexpr char DELIMITER = ',';

FileRecord::FileRecord(long timestamp_us, string symbol, int quantity, int price) {
  this->timestamp_us = timestamp_us;
  this->symbol = symbol;
  this->quantity = quantity;
  this->price = price;
}

// Stream extraction operator to convert an CSV record into a FileRecord
istream& operator>>(istream& is, FileRecord& out) {
  string line;
  getline(is, line);
  if (is.eof() || line.empty() || line[0] == '#') {
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
  // For our purposes, we can take the absolute value of the quantity,
  // in case it's negative.
  auto quantity = std::abs(stod(component));
  if (quantity != 0) {
    out.setQuantity();
  } else {
    // if quantity is 0, it may be valid somehow, but for our purposes
    // it won't contribute to the statistics we calculate, so throw it
    // out.
    out.setSymbol("");
    return is;
  }
  getline(lineStream, component, DELIMITER);
  out.setPrice(stoi(component));
  return is;
}
