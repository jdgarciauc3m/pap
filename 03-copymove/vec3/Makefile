all: test

vector.o:	vector.cpp vector.h
	g++ vector.cpp -c -std=c++11 -Wall -Werror -Wpedantic -Wextra

test:	main.cpp vector.o
	g++ main.cpp vector.o -o test -std=c++11 -Wall -Werror -Wpedantic -Wextra
