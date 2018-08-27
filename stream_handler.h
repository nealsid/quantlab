#pragma once

#include <istream>
#include <ostream>
#include <map>

using namespace std;

struct StockStats;
class FileRecord;

using ProcessFunctionList = std::initializer_list<std::function<void(StockStats*, FileRecord)>>;

struct StockStats {
  long last_time_traded;
  long max_time_gap;
  double volume_traded;
  int max_trade_price;
  double weighted_average_numerator;
  StockStats() {
    last_time_traded = 0;
    max_trade_price = 0;
    volume_traded = 0;
    max_trade_price = 0;
    weighted_average_numerator = 0;
  }
};

class StreamHandler {
 public:
  explicit StreamHandler(istream& is);

  void Process(ProcessFunctionList functions);

  void PrintStats(ostream& os);
 private:
  istream& is;
  map<string, StockStats> stockStats;
};
