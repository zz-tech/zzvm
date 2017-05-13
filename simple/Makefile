CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -O3

all: zzvm

zzvm: zzvm.o
	$(CC) zzvm.o -o $@

%.o: %.c
	$(CC) $< -c $(CFLAGS)

test: zzvm
	./zzvm

.PHONY : clean

clean:
	rm -f zzvm *.o
