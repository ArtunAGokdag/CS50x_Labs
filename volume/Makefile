CC = gcc

CFLAGS =-Wall -g
BINS = volume
OUT = output.wav

all : $(BINS)

%: %.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) -r $(BINS) $(OUT) *.dSYM
