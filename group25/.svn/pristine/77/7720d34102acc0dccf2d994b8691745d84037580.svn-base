/* NAME:
   NSID:
   Student Number:

   CMPT 332 Term 1 2018

   Lab 1

   September 10, 2018
*/

#include <stdlib.h>
#include <stdio.h>

#include "thread.h"

/* Main code for threads */
int child_main(void *param) {
    int id;
    int seconds;

    id = *((int *) param);
    seconds = id % 5 + 1;

    printf("thread(%d) sleeping for %d\n", id, seconds);
    thread_sleep(seconds);
    printf("thread(%d) done\n", id);

    return 0;
}

/* Main code for parent thread */
int parent_main(int n)
{
    int i;
    struct thread_info *threads;
    int threadReturn;

    threads = malloc(n * sizeof(struct thread_info));
    if (threads == NULL) exit(1);

    for (i = 0; i < n; i++) {
        threads[i].id = i;
        threads[i].entry = child_main;
        threadReturn = thread_create(&threads[i]);
	if (threadReturn) perror("createThread");

    }

    for (i = 0; i < n; i++) {
        threadReturn = thread_join(&threads[i]);
	if (threadReturn) perror("join");

    }

    printf("All %d threads finished\n", n);

    return 0;
}

/* Parse arguments and return n */
int parse_args(int argc, char *argv[]) {
    int n;

    if (argc != 2) {
        printf("usage: %s <n>\n", argv[0]);
        exit(1);
    }

    n = atoi(argv[1]);
    if (n < 1) {
        printf("n must 1 or greater\n");
        exit(1);
    }

    return n;
}
