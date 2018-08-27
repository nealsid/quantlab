#pragma once

#include <sstream>
#include <string>

using namespace std;

// In memory representation of each line of the input file.
class FileRecord {
 public:
  FileRecord() { }
  FileRecord(long timestamp_us, string symbol, int quantity, int price);

  // The stream extraction operator is a friend so it can access the
  // setters.
  friend istream& operator>>(istream& is, FileRecord& out);

  unsigned long getTimestampUs() const {
    return timestamp_us;
  }

  string getSymbol() const {
    return symbol;
  }

  double getQuantity() const {
    return quantity;
  }

  unsigned int getPrice() const {
    return price;
  }
 private:
  unsigned long timestamp_us;
  string symbol;
  double quantity;
  unsigned int price;

  void setTimestampUs(unsigned long timestamp_us) {
    this->timestamp_us = timestamp_us;
  }

  void setSymbol(string symbol) {
    this->symbol = symbol;
  }

  void setQuantity(double quantity) {
    this->quantity = quantity;
  }

  void setPrice(unsigned int price) {
    this->price = price;
  }
};

