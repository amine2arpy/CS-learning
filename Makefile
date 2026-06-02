CC = gcc
CFLAGS = -Wall -g

all:
	$(CC) $(CFLAGS) *.c -o program
%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f program