#include "stock_trade_processor.h"

#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Specify input filename on command line, e.g. " << endl
         << endl << "\t" << argv[0] << " " << "input.txt" << endl << endl;
    return 1;
  }
  ifstream input(argv[1]);
  StockTradeProcessor s(input);
  s.Process();
  ofstream of("output.csv", ios::out | ios::trunc);
  s.OutputStats([&of] (const auto& symbol, const auto& stats) {
                  of << symbol << ","
                     << stats.max_time_gap_us << ","
                     << setprecision(10)
                     << stats.volume_traded << ","
                     << setprecision(20)
                     << stats.weighted_average_numerator / stats.volume_traded << ","
                     << stats.max_trade_price << endl;
                });
  return 0;
}
