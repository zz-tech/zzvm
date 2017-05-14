CFLAGS = -Wall -Wextra -g -std=c99
CC = gcc

all: zzvm dump
zzvm: zzvm.c 
	${CC} ${CFLAGS} zzvm.c -o zzvm

dump: dump.c 
	${CC} ${CFLAGS} dump.c -o dump

.PHONY : clean

clean:
	rm -f zzvm dump
