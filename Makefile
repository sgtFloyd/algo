CC=g++ -std=c++11
.PHONY: test

all: test

test:
	$(CC) test/test_helper.cpp -o unit_tests && ./unit_tests
	make clean

clean:
	rm unit_tests
