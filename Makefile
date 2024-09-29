CC = g++
.PHONY:all clean
all:
	$(CC) -o test main.cpp

linklist:
	$(CC) -o test test_linkList.cpp

clean:
	rm ./test