#include "stock_trade_processor.h"

#include "stream_handler.h"
#include "file_record.h"

#include <istream>
#include <memory>
#include <ostream>

using namespace std;

void StockTradeProcessor::Process() {
  // Technically this could all be done in 1 lambda and may be faster,
  // but I had the Process() function take a list of functions so that
  // separate stats calculations could be kept separate and/or reused
  // without having to reuse the entire processing function.
  s->Process({
              [] (auto s, auto f) {
                s->volume_traded += f.getQuantity();
              },
              [] (auto s, auto f) {
                if (s->last_time_traded_us == 0) {
                  s->max_time_gap_us = 0;
                } else {
                  s->max_time_gap_us = std::max(s->max_time_gap_us,
                                                f.getTimestampUs() - s->last_time_traded_us);
                }
                s->last_time_traded_us = f.getTimestampUs();
              },
              [] (auto s, auto f) {
                s->max_trade_price = std::max(s->max_trade_price,
                                              f.getPrice());
              },
              [] (auto s, auto f) {
                s->weighted_average_numerator += f.getQuantity() * f.getPrice();
              }});      
}

void StockTradeProcessor::OutputStats(StatsFunction fn) {
  s->ProcessStats(fn);
}
