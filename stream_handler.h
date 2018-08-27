#pragma once

#include <istream>
#include <map>
#include <ostream>

using namespace std;
using namespace std::chrono;

struct StockStats;
class FileRecord;

using ProcessFunctionList = std::initializer_list<std::function<void(const FileRecord&)>>;
using StatsFunction = std::function<void(const string& symbol, const StockStats&)>;

// Class that handles input from the stream containing stock trades
// and supports processing via lambdas provided by the client that are
// callbacked into.
class StreamHandler {
 public:
  explicit StreamHandler(istream& is);

  void Process(ProcessFunctionList functions);
 private:
  istream& is;
};
