CC=g++ -std=c++11
.PHONY: test

TARGET = main
all:
	$(CC) $(TARGET).cpp -o $(TARGET).out && ./$(TARGET).out
	make clean

test:
	$(CC) test/test_helper.cpp -o unit_tests.out && ./unit_tests.out
	make clean

clean:
	rm *.out
