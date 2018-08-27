#pragma once

#include <string>
#include <sstream>

using namespace std;

constexpr char DELIMITER = ',';

class FileRecord {
 public:
  FileRecord() { }
  FileRecord(long timestamp_us, string symbol, int quantity, int price);
  friend istream& operator>>(istream& is, FileRecord& out);

  long getTimestampUs() const {
    return timestamp_us;
  }

  string getSymbol() const {
    return symbol;
  }

  double getQuantity() const {
    return quantity;
  }

  int getPrice() const {
    return price;
  }
 private:
  long timestamp_us;
  string symbol;
  double quantity;
  int price;

  void setTimestampUs(long timestamp_us) {
    this->timestamp_us = timestamp_us;
  }

  void setSymbol(string symbol) {
    this->symbol = symbol;
  }

  void setQuantity(double quantity) {
    this->quantity = quantity;
  }

  void setPrice(int price) {
    this->price = price;
  }
};

