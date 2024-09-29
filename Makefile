CC = g++
.PHONY:all clean
all:
	$(CC) -o test main.cpp

clean:
	rm ./test