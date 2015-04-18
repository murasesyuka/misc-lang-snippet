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

int stack10_Constructor(Stack10 *s, mtx_t *mtx, cnd_t *c_pu, cnd_t *c_po){
	int ret;
	
	ret = mtx_init(mtx, mtx_plain);
	if(ret != thrd_success){
		return ret;
	}
	s->mtx_ = mtx;
	
	ret = cnd_init(c_pu);
	if(ret != thrd_success){
		return ret;
	}
	s->cnd_push_ = c_pu;

	ret = cnd_init(c_po);
	if(ret != thrd_success){
		return ret;
	}
	s->cnd_pop_ = c_po;

	return 0;
}

void stack10_Destructor(Stack10 *s){
	mtx_destroy(s->mtx_);
	cnd_destroy(s->cnd_push_);
	cnd_destroy(s->cnd_pop_);
}


int stack10_push(Stack10 *s, int x){
	mtx_lock(s->mtx_);
	
	while(s->vused_ >= S_SIZE){
		cnd_wait(s->cnd_push_, s->mtx_);
	}
	s->v_[s->vused_++] = x;

	cnd_signal(s->cnd_pop_);
	mtx_unlock(s->mtx_);
	return 0;
}

int stack10_pop(Stack10 *s, int *x){
	mtx_lock(s->mtx_);
	
	while(s->vused_ == 0){
		cnd_wait(s->cnd_pop_, s->mtx_);
	}
	*x = s->v_[--s->vused_];
	
	cnd_signal(s->cnd_push_);
	mtx_unlock(s->mtx_);
	return 0;
}


int func(void *arg)
{
	int i;
	Stack10 *s =(Stack10*)arg;
	printf("thrd_current()vim is %ld\n", (unsigned long int)thrd_current());
	for(i = 0; i<3; ++i){
		stack10_push(s, i);
	}
	return 0;
}

int main()
{
	int i, n;
	Stack10 s = {{0},0};
	
	mtx_t mtx;
	cnd_t c_pu, c_po;
	
	enum {SIZE = 4};
	thrd_t thr_s[SIZE];

	/*
	 * init
	 */
	stack10_Constructor(&s, &mtx, &c_pu, &c_po);

	/*
	 * run
	 */
	for(i=0; i<SIZE; i++) {
		thrd_create(&thr_s[i], func, (void*)(Stack10*)&s);
	}

	for(i=0; i<(SIZE*3); i++){
		stack10_pop(&s, &n);
		printf("%d : %d\n",i,n);
	}

	for(i=0; i<SIZE; i++) {
		thrd_join(thr_s[i], 0);
	}


	/*
	 * destroy
	 */
	stack10_Destructor(&s);
	
	return 0;
}
