/* NAME:
   NSID:
   Student Number:

   CMPT 332 Term 1 2018

   Lab 1

   September 10, 2018
*/


typedef int(*thread_entry)(void *);

/* Store information for thread */
struct thread_info {
    long long id;
    thread_entry entry;
    void *thread; /* point to arch specific thread info */
};

/* Create a thread */
int thread_create(struct thread_info *);

/* Sleep for a thread */
void thread_sleep(int seconds);

/* Join a thread */
int thread_join(struct thread_info *);

int parent_main(int n);

int parse_args(int argc, char *argv[]);
