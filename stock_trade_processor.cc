#include "stock_trade_processor.h"

#include "stream_handler.h"
#include "file_record.h"

#include <istream>
#include <memory>
#include <ostream>

using namespace std;

void StockTradeProcessor::Process() {
  s->Process({
              [] (StockStats* s, FileRecord f) {
                s->volume_traded += f.getQuantity();
              },
              [] (StockStats* s, FileRecord f) {
                if (s->last_time_traded_us == 0) {
                  s->max_time_gap_us = 0;
                } else {
                  s->max_time_gap_us = std::max(s->max_time_gap_us,
                                                f.getTimestampUs() - s->last_time_traded_us);
                }
                s->last_time_traded_us = f.getTimestampUs();
              },
              [] (StockStats* s, FileRecord f) {
                s->max_trade_price = std::max(s->max_trade_price,
                                              f.getPrice());
              },
              [] (StockStats* s, FileRecord f) {
                s->weighted_average_numerator += f.getQuantity() * f.getPrice();
              }});      
}

void StockTradeProcessor::OutputStats(ostream& os) {
  s->ProcessStats([&os] (const string& symbol, const StockStats& stats) {
                    os << symbol << ","
                       << stats.max_time_gap_us << ","
                       << stats.volume_traded << ","
                       << stats.weighted_average_numerator / stats.volume_traded << ","
                       << stats.max_trade_price << endl;
                  });
  
}
