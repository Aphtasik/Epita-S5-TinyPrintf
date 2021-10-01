CC=gcc
CFLAGS=-std=c99 -pedantic -Werror -Wall -Wextra -c -g
LDFLAGS= -o tinyprintf -lcriterion

# TODO: remove
all: tinyprintf.o main.o
	$(CC) $(LDFLAGS) $^

check: tests.o tinyprintf.o
	$(CC) $(LDFLAGS) $^

tests.o: tests/tests.c
	$(CC) $(CFLAGS) $^

tinyprintf.o: src/tinyprintf.c
	$(CC) $(CFLAGS) $^

# TODO: remove
main.o: src/main.c
	$(CC) $(CFLAGS) $^

clean:
	rm *.o
	rm tinyprintf
