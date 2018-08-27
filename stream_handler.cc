#include "stream_handler.h"
#include "file_record.h"

StreamHandler::StreamHandler(istream& is) :
  is(is) {
}

void StreamHandler::Process(ProcessFunctionList functions) {
  FileRecord f;
  while (!is.eof()) {
    // Sometimes EOF isn't true until the next getline is done, so we
    // use an empty symbol string as a continue condition, which can
    // also happen if the input file has comments.
    is >> f;
    if (f.getSymbol() == "") {
      continue;
    }

    for (auto fn : functions) {
      fn(f);
    }
  }
}
