#include "file_record.h"

#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    cerr << "Specify input filename on command line, e.g. " << endl
         << endl << "\t" << argv[0] << " " << "input.txt" << endl << endl;
    return 1;
  }
  ifstream input(argv[1]);
  while (!input.eof()) {

  }
}
