CXX = g++
CC = gcc
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -O3 -g -fsanitize=address
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c18 -O3 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

EXEC = nth_prime_vector nth_prime_array nth_prime_array_c
OBJ = $(EXEC:=.o)
$(echo $(EXEC) $(OBJ))
SRC = $(OBJ:.o=.cpp)

all: $(EXEC)


nth_prime_vector: nth_prime_vector.o
	$(CXX) $(LDFLAGS) -o $@ $< $(LBLIBS)

nth_prime_array: nth_prime_array.o
	$(CXX) $(LDFLAGS) -o $@ $< $(LBLIBS)

nth_prime_array_c: nth_prime_array_c.o
	$(CC) $(LDFLAGS) -o $@ $< $(LBLIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) $< -c -o $@

.c.o:
	$(CC) $(CFLAGS) $< -c -o $@

clean:
	rm -rf $(OBJ) $(EXEC)