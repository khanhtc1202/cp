CC = gcc
CFLAGS = -g -std=c99
RM = rm -rf
objects = prob_1 prob_2

all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS) -o $@.o $<
clean:
	$(RM) *.o *.txt *.o.dSYM
