#include "stream_handler.h"
#include "file_record.h"

StreamHandler::StreamHandler(istream& is) :
  is(is) {
}

void StreamHandler::Process(ProcessFunctionList functions) {
  FileRecord f;
  while (!is.eof()) {
    // Sometimes EOF isn't true until the next getline is done, so we
    // use an empty symbol string as a break condition.
    is >> f;
    if (f.getSymbol() == "") {
      break;
    }
    auto& existing = stockStats[f.getSymbol()];

    for (auto fn : functions) {
      fn(&existing, f);
    }
  }
}

void StreamHandler::ProcessStats(StatsFunction statsFn) {
  for (const auto& mapEntry : stockStats) {
    statsFn(mapEntry.first, mapEntry.second);
  }
}
