#include <stdio.h>
#include <pthread.h>

int shared_resource = 0;

#define NUM_ITERS 100
#define NUM_THREADS 100

void lock(int tid);
void unlock(int tid);

int entering[NUM_THREADS] = {0};
int ticket[NUM_THREADS] = {0};

void lock(int tid)
{
    entering[tid] = 1;
    int max_ticket = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        if (ticket[i] > max_ticket) {
            max_ticket = ticket[i];
        }
    }
    ticket[tid] = max_ticket + 1;
    entering[tid] = 0;
    for (int i = 0; i < NUM_THREADS; i++) {
        while (entering[i]) {} // wait until thread i finishes its ticket
        while (ticket[i] && (ticket[i] < ticket[tid] ||
                (ticket[i] == ticket[tid] && i < tid))) {} // wait until it's my turn
    }
}

void unlock(int tid)
{
    ticket[tid] = 0;
}

void* thread_func(void* arg) {
    int tid = *(int*)arg;
    
    lock(tid);
    
        for(int i = 0; i < NUM_ITERS; i++)    shared_resource++;
    
    unlock(tid);
    
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int tids[NUM_THREADS];
    
    for (int i = 0; i < NUM_THREADS; i++) {
        tids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &tids[i]);
    }
    
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("shared: %d\n", shared_resource);
    
    return 0;
}