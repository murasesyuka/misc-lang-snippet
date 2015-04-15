#include <stdio.h>
#include <threads.h>

enum{S_SIZE = 10};
typedef struct Stack{
	int v_[S_SIZE];
	/* int vsize_; */
	int vused_;
	mtx_t *mtx_;
	cnd_t *cnd_push_;
	cnd_t *cnd_pop_;
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
	int i, n, ret;
	Stack10 s = {{0},0};
	
	mtx_t mtx;
	cnd_t c_pu, c_po;
	
	enum {SIZE = 4};
	thrd_t thr_s[SIZE];

	/*
	 * init
	 */
	ret = mtx_init(&mtx, mtx_plain);
	if(ret != thrd_success){
		return ret;
	}
	s.mtx_ = &mtx;
	
	ret = cnd_init(&c_pu);
	if(ret != thrd_success){
		return ret;
	}
	s.cnd_push_ = &c_pu;

	ret = cnd_init(&c_po);
	if(ret != thrd_success){
		return ret;
	}
	s.cnd_pop_ = &c_po;

	/*
	 * run
	 */
	for(i=0; i<SIZE; i++) {
		thrd_create(&thr_s[i], func, (void*)(Stack10*)&s);
	}
	for(i=0; i<SIZE; i++) {
		thrd_join(thr_s[i], 0);
	}

	for(i=0; i<(SIZE*3); i++){
		pop(&s, &n);
		printf("%d : %d\n",i,n);
	}

	/*
	 * destroy
	 */
	mtx_destroy(&mtx);
	cnd_destroy(&c_pu);
	cnd_destroy(&c_po);
	
	return 0;
}
