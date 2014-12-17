CC=g++
.PHONY: test

all: test

test:
	g++ test/test_helper.cpp -o unit_tests && ./unit_tests
	make clean

clean:
	rm unit_tests
