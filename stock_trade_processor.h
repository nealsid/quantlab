#pragma once

#include <istream>
#include <memory>
#include <ostream>
#include "stream_handler.h"

using namespace std;

using StatsFunction = std::function<void(const string& symbol, const StockStats& stats)>;
class StockTradeProcessor {
 public:
  explicit StockTradeProcessor(istream& is) :
  s(make_unique<StreamHandler>(is)) {

  }
  void Process();
  void OutputStats(StatsFunction fn);
 private:
  unique_ptr<StreamHandler> s;
};
