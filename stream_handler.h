#pragma once

#include <istream>
#include <map>
#include <ostream>

using namespace std;
using namespace std::chrono;

struct StockStats;
class FileRecord;

using ProcessFunctionList = std::initializer_list<std::function<void(StockStats*, FileRecord)>>;
using StatsFunction = std::function<void(const string& symbol, const StockStats&)>;

struct StockStats {
  
  // The following two are timestamps and represent microseconds since
  // midnight.  Using chrono library may be clearer but there's no
  // overloaded stream extraction operator for duration and no
  // assignment conversion from longs to duration. Since the
  // arithmetic we're doing is fairly simple, I stuck with longs.
  unsigned long last_time_traded_us;
  unsigned long max_time_gap_us;
  double volume_traded;
  unsigned int max_trade_price;
  double weighted_average_numerator;
  StockStats() {
    last_time_traded_us = 0;
    max_time_gap_us = 0;
    volume_traded = 0;
    max_trade_price = 0;
    weighted_average_numerator = 0;
  }
};

class StreamHandler {
 public:
  explicit StreamHandler(istream& is);

  void Process(ProcessFunctionList functions);

  void ProcessStats(StatsFunction statsFn);
 private:
  istream& is;
  map<string, StockStats> stockStats;
};
