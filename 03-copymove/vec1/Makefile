all: test

vector.o:	vector.cpp
	g++ vector.cpp -c -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra

test:	main.cpp vector.o
	g++ main.cpp vector.o -o test -std=c++11 -Wall -Weffc++ -Werror -Wpedantic -Wextra
