#include "file_record.h"
#include "stream_handler.h"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Specify input filename on command line, e.g. " << endl
         << endl << "\t" << argv[0] << " " << "input.txt" << endl << endl;
    return 1;
  }
  ifstream input(argv[1]);
  StreamHandler s(input);
  s.Process({
             [] (StockStats* s, FileRecord f) {
               s->volume_traded += f.getQuantity();
             },
             [] (StockStats* s, FileRecord f) {
               s->max_time_gap = std::max(s->max_time_gap,
                                          f.getTimestampUs() - s->last_time_traded);
             },
             [] (StockStats* s, FileRecord f) {
               s->max_trade_price = std::max(s->max_trade_price,
                                             f.getPrice());
             },
             [] (StockStats* s, FileRecord f) {
               s->weighted_average_numerator += f.getQuantity() * f.getPrice();
             }});      

  s.PrintStats(cerr);
  return 0;
}
