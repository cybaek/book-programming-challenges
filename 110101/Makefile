all:
	g++ main.cpp

simple:
	g++ simple.cpp 

test: test-small

test-small:
	./a.out < input.small > tmp.txt && diff tmp.txt output.small

test-large: test-small
	./a.out < input.large > tmp.txt && diff tmp.txt output.large

clean:
	rm -f a.out tmp.txt
