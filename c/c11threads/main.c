#include <stdio.h>

#define HAVE_PTHREAD
#include "c11/threads.h"

int func(void *arg)
{
	int n = (long)arg;
	xtime dur = { 4, 0};

	printf("start thread[%d]\n", n);

	thrd_sleep(&dur);

	printf("stop thread[%d]\n", n);

	return 0;
}

int main()
{
	int i;
	enum {SIZE = 4};
	thrd_t thr_s[SIZE];
	
	for(i=0; i<SIZE; i++) {
		thrd_create(&thr_s[i], func, (void*)(long)i);
	}
	
	for(i=0; i<SIZE; i++) {
		thrd_join(thr_s[i], 0);
	}
	
	return 0;
}
