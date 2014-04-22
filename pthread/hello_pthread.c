/**
 * see:
 *      https://computing.llnl.gov/tutorials/pthreads/
 * 
 * compile: 
 *      gcc -lpthread hello.c
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THREADS	5

void *PrintHello(void *threadid)
{
    int r = rand() % 1000;

    long tid = (long)threadid;

    if(tid > 0) {
        sleep(1);
    }

    printf("hello thread #%ld!\n", tid);

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    srand(time(NULL));

    pthread_t threads[NUM_THREADS];
    int rc;
    long t;

    for(t=0; t<NUM_THREADS; t++){
        printf("creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, PrintHello, (void *)t);
        if (rc){
            printf("pthread_create() failed: %d\n", rc);
            return 1;
        }
    }

    /* Last thing that main() should do */
    
    /* 
     * By having main() explicitly call pthread_exit() as the last thing it does, 
     * main() will block and be kept alive to support the threads it created 
     * until they are done. 
     */
    pthread_exit(NULL);
}
