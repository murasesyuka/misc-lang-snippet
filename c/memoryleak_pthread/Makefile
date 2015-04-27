CFLAGS = -Wall -g -I.
LDFLAGS = -pthread

PROG1=forgetjoin
$(PROG1):
	gcc $(CFLAGS) -o $(PROG1) memleak_forgetjoin.c $(LDFLAGS)

check:
	valgrind --leak-check=full ./$(PROG1)

.PHONY: clean
clean:
	rm -f $(PROG1)
