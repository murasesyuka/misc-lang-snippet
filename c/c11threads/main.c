#include <stdio.h>

#define HAVE_PTHREAD
#include "c11/threads.h"

int func(void *arg)
{
	//int n = (long)arg;
	//xtime dur = { 4, 0};

	printf("%ld\n", (unsigned long int)thrd_current());

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
