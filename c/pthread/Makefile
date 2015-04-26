CFLAGS = -Wall -g -I.
LDFLAGS = -pthread

PROG1=forgetjoin
$(PROG1):
	gcc $(CFLAGS) -o $(PROG1) memleak_forgetjoin.c $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(PROG1)
