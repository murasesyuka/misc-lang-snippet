CFLAGS = -Wall -I. -Ic11 -DHAVE_PTHREAD
LDFLAGS = -pthread

test:
	gcc $(CFLAGS) main.c $(LDFLAGS)

.PHONY: clean
clean:
	rm -f a.out
