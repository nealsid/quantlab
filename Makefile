CFLAGS=-std=c++11
CC=clang++

file_record.o: file_record.cc
	$(CC) $(CFLAGS) -c file_record.cc

quantlab_main.o: quantlab_main.cc
	$(CC) $(CFLAGS) -c quantlab_main.cc

quantlab_main: quantlab_main.o file_record.o
	$(CC) $(CFLAGS) -o quantlab_main quantlab_main.o file_record.o
