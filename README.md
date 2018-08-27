Stock trade programming exercise for Quantlab.

This program implements the stock trade processing exercise for
Quantlab.  It has 2 main classes:

- StreamHandler, which takes care of file i/o and provides an
  interface to set callbacks for each line processed

- StockTradeProcessor which does all the calculations and provides an
  interface to get the stats calculated for each stock symbol.

A helper class called FileRecord is used inside StreamHandler for
constructing an in memory representation of each line.

There are a few test cases that are inside the testcases/ directory.
If I had more time I'd implement automated test infrastructure instead
of running them manually, using Google Test, and a better build system
using CMake.

Note that I used double for the volume identifier because it wasn't
specified that it was always integer, although the sample test case
provided has different output if you use int or double.  If this
causes any automated validation infrastructure you have to fail,
apologies.

I used some C++14 features like auto lambda parameters and
"make_unique"; if the build environment is only C++11, apologies
again.