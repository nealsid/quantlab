CFLAGS=-std=c++14
CC=clang++

file_record.o: file_record.cc
	$(CC) $(CFLAGS) -c file_record.cc

stream_handler.o: stream_handler.cc
	$(CC) $(CFLAGS) -c stream_handler.cc

stock_trade_processor.o: stock_trade_processor.cc
	$(CC) $(CFLAGS) -c stock_trade_processor.cc

quantlab_main.o: quantlab_main.cc
	$(CC) $(CFLAGS) -c quantlab_main.cc

quantlab_main: quantlab_main.o file_record.o stream_handler.o stock_trade_processor.o
	$(CC) $(CFLAGS) -o quantlab_main quantlab_main.o file_record.o stream_handler.o stock_trade_processor.o

clean:
	rm -f *~ *o quantlab_main
