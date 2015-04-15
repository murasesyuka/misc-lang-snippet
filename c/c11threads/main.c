#include <stdio.h>
#include <threads.h>

mtx_t mtx;

int func(void *arg)
{
	//int n = (long)arg;
	//xtime dur = { 4, 0};

	mtx_lock(&mtx);
	
	printf("thrd_current()vim is %ld\n", (unsigned long int)thrd_current());

	mtx_unlock(&mtx);
	
	return 0;
}

int main()
{
	int i;
	enum {SIZE = 4};
	thrd_t thr_s[SIZE];

	mtx_init(&mtx, mtx_plain);
	for(i=0; i<SIZE; i++) {
		thrd_create(&thr_s[i], func, (void*)(long)i);
	}
	
	for(i=0; i<SIZE; i++) {
		thrd_join(thr_s[i], 0);
	}
	
	return 0;
}
