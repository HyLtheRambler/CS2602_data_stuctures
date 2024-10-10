CC = g++

.PHONY: clean run

linklist:
	$(CC) -o test ./testcode/test_linkList.cpp
	./test

seqstack:
	$(CC) -o test ./testcode/test_seqStack.cpp
	./test

seqqueue:
	$(CC) -o test ./testcode/test_seqQueue.cpp
	./test

linkqueue:
	$(CC) -o test ./testcode/test_linkQueue.cpp
	./test

btree:
	$(CC) -o test ./testcode/test_btree.cpp
	cat ./testcode/btree_input.txt | ./test

clean:
	rm ./test