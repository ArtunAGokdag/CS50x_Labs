CC = gcc

CFLAGS =-Wall -g cs50.c
BINS = tideman

all : $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) *.dSYM