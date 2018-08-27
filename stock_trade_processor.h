#pragma once

#include "stream_handler.h"

#include <istream>
#include <memory>
#include <ostream>

using namespace std;

using StatsFunction = std::function<void(const string& symbol, const StockStats& stats)>;

// Main class for processing the input file of stock trades.
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
