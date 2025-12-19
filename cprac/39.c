#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define READER 5
#define WRITER 2

sem_t mutex;
sem_t wrt;

int readerCount = 0;
int shraredResource = 0;

void *reader(void* arg){ // add * infront of function

    int id = *(int *)arg;

    while(1){

        sem_wait(&mutex);
        readerCount++;
        if (readerCount == 1)
            sem_wait(&wrt);
        sem_post(&mutex);

        // critical section
        printf("Reader %d read %d\n", id, shraredResource);
        sleep(1);
        // end

        sem_wait(&mutex);
        readerCount--;
        if(readerCount == 0)
            sem_post(&wrt);
        sem_post(&mutex);

        sleep(1);
    }
}
void *writer(void* arg){ // add * infront of function
    int id = *(int *)arg;

    while(1){
        sem_wait(&wrt);

        shraredResource++;
        printf("Writer %d write value %d\n", id, shraredResource);
        sleep(1);

        sem_post(&wrt);
        
        sleep(1);
    }
}

int main(){

    pthread_t r[READER], w[WRITER];

    int r_id[READER], w_id[WRITER];
    int i = 0;

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (i = 0; i < WRITER; i++)
    {
        w_id[i] = i + 1;
        pthread_create(&w[i], NULL, writer, &w_id[i]);
    }

    for (i = 0; i < READER ;i++){
        r_id[i] = i + 1;
        pthread_create(&r[i], NULL, reader, &r_id[i]);
    }

    for (i = 0; i < WRITER;i++){
        pthread_join(w[i], NULL);
    }
    for (i = 0; i < READER;i++){
        pthread_join(r[i], NULL);
    }

        return 0;
}