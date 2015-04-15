#include <stdio.h>
#include <threads.h>

enum{S_SIZE = 10};
typedef struct Stack{
	int v_[S_SIZE];
	/* int vsize_; */
	int vused_;
	mtx_t *mtx_;
} Stack10;

int push(Stack10 *s, int x){
	mtx_lock(s->mtx_);
	
	if(s->vused_ == S_SIZE){
		
		mtx_unlock(s->mtx_);
		return -1;	/* Full */
	}
	s->v_[s->vused_++] = x;
	
	mtx_unlock(s->mtx_);
	return 0;
}

int pop(Stack10 *s, int *x){
	mtx_lock(s->mtx_);
	
	if(s->vused_ == 0){
		
		mtx_unlock(s->mtx_);
		return -1;
	}
	*x = s->v_[--s->vused_];
	
	mtx_unlock(s->mtx_);
	return 0;
}


int func(void *arg)
{
	int i;
	Stack10 *s =(Stack10*)arg;
	printf("thrd_current()vim is %ld\n", (unsigned long int)thrd_current());
	for(i = 0; i<3; ++i){
		push(s, i);
	}
	return 0;
}

int main()
{
	int i, ret;
	Stack10 s = {{0},0};
	
	mtx_t mtx;
	
	enum {SIZE = 4};
	thrd_t thr_s[SIZE];

	ret = mtx_init(&mtx, mtx_plain);
	if(ret != thrd_success){
		return ret;
	}
	s.mtx_ = &mtx;
	
	for(i=0; i<SIZE; i++) {
		thrd_create(&thr_s[i], func, (void*)(Stack10*)&s);
	}
	for(i=0; i<SIZE; i++) {
		thrd_join(thr_s[i], 0);
	}

	for(i=0; i<S_SIZE; i++){
		printf("staci[%d] = %d\n",i,s.v_[i]);
	}
	
	mtx_destroy(&mtx);
	return 0;
}
