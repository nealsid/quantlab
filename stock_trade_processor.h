#pragma once

#include <istream>
#include <memory>
#include <ostream>
#include "stream_handler.h"

using namespace std;

class StockTradeProcessor {
 public:
  explicit StockTradeProcessor(istream& is) :
  s(make_unique<StreamHandler>(is)) {

  }
  void Process();
  void OutputStats(ostream& os);
 private:
  unique_ptr<StreamHandler> s;
};
