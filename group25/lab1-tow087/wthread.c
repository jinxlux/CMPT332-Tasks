/* NAME:
   NSID:
   Student Number:

   CMPT 332 Term 1 2018

   Lab 1

   September 10, 2018
*/

#include <stdlib.h>
#include <stdio.h>

#include <windows.h>

#include "thread.h"

int thread_create(struct thread_info *info) {
    HANDLE *thread;

    thread = malloc(sizeof(HANDLE));
    if (!thread) perror("malloc");

    info->thread = thread;
    *thread = CreateThread(
        NULL, 0, (DWORD (*)(void*)) info->entry, &(info->id), 0, NULL
    );

    if (*thread == NULL) {
        free(thread);
        return -1;
    }

    return 0;
}

void thread_sleep(int seconds) {
    Sleep(seconds * 1000);
}

int thread_join(struct thread_info *info) {
    HANDLE *thread;
    DWORD returnVal;

    thread = info->thread;
    returnVal = WaitForSingleObject(*thread, INFINITE);

    return returnVal;
}

int main(int argc, char *argv[]) {
    int n;
    int returnVal;

    n = parse_args(argc, argv);
    returnVal = parent_main(n);

    return (returnVal);
}
