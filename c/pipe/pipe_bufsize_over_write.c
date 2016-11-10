#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    int pipefd[2];
    pid_t cpid;
    char buf[65536] = {0};
    int count = 0;

    char dummy[65536] = {0};
    dummy[6553-1] = '\n';

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <string>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    printf("get pipe buf size is %d\n", fcntl(pipefd[1], F_GETPIPE_SZ ));
    //printf("get pipe buf size is %d\n", fcntl(pipefd[1], F_SETPIPE_SZ, 1024 ));

    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) {    /* 子プロセスがパイプから読み込む */
        close(pipefd[1]);  /* 使用しない write 側はクローズする */

        while (read(pipefd[0], &buf, 65536) > 0){
		//write(STDOUT_FILENO, &buf, 1);
		printf("count %d\n", count++);
	}

        write(STDOUT_FILENO, "\n", 1);
        close(pipefd[0]);
        _exit(EXIT_SUCCESS);

    } else {            /* 親プロセスは argv[1] をパイプへ書き込む */
        close(pipefd[0]);          /* 使用しない read 側はクローズする */

	printf("write size is %lu\n", sizeof(char) * 65536 );

        write(pipefd[1], dummy, sizeof(char) * 65536 );
        close(pipefd[1]);          /* 読み込み側が EOF に出会う */
        wait(NULL);                /* 子プロセスを待つ */
        exit(EXIT_SUCCESS);
    }
}
