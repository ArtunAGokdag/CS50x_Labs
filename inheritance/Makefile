CC = gcc

CFLAGS =-Wall -g
BINS = inheritance

all : $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) *.dSYM