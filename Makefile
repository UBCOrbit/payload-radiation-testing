CC=gcc
# CFLAGS=-I ./src/

tests:
	$(CC) -o ./bin/matrix_multiplier ./src/matrix_multiplier.c
	$(CC) -o ./bin/nothing ./src/nothing.c
	$(CC) -o ./bin/RAM_bitflip_test ./src/RAM_bitflip_test.c
