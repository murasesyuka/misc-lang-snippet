#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include <errno.h>

unsigned long fib(unsigned long n)
{
    unsigned long f;

    switch (n) {
        case 1:
        case 2:
            f = 1;
            break;
        default:
            f = fib(n - 1) + fib(n - 2);
            break;
    }
    return f;
}

void* run_longtime() {
	printf("fib:%ld\n", fib(30));
	pthread_exit(0);
}
	
void* run() {
	pthread_exit(0);
}

int main () {
	enum{SIZE=4};
	pthread_t thread[SIZE];
	int rc;
	long i = 0, j=0;
	for (i = 0; i < SIZE; i++) {
		rc = pthread_create(&thread[i], 0, run_longtime, 0);
		if ( rc ) {
			printf("ERROR, rc is %d, so far %ld threads created\n", rc, i);
			perror("Fail:");
			return -1;
		}
	}


	for (i = 0; i < SIZE; i++) {
		printf("%d\n", i);
		//if (pthread_kill(thread[i], 0) == ESRCH){
			pthread_detach(thread[i]);
			pthread_kill(thread[i], SIGHUP);//1 is kill Parent
			//pthread_kill(thread[i], SIGTERM);//15 is kill Parent
			//}
		//pthread_detach(thread[i]);
	}

	for (j = 0; j < SIZE; j++) {
	for (i = 0; i < SIZE; i++) {
		rc = pthread_create(&thread[i], 0, run, 0);
		if ( rc ) {
			printf("ERROR, rc is %d, so far %ld threads created\n", rc, i);
			perror("Fail:");
			return -1;
		}
	}

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", i);
		pthread_join(thread[i], NULL);
	}

	sleep(5);
	}
	return 0;
}
