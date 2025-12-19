#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define BUFFER_SIZE 5
#define PRODUCERS 3
#define CONSUMERS 3

sem_t mutex;
sem_t full;
sem_t empty;

int buffer[BUFFER_SIZE], in=0, out=0;

void *producer( void* arg){

    int id = *(int *)arg;
    int item;

    while(1){
        item = rand() % 100;

        sem_wait(&empty);
        sem_wait(&mutex);

        buffer[in] = item;
        in = (in + 1) % BUFFER_SIZE;
        printf("Prodncer %d produce %d \n", id, item);

        sem_post(&mutex);
        sem_post(&full);
    }
}

void *consumer(void* arg){

    int id = *(int *)arg;
    int item;

    while(1){
        sem_wait(&full);
        sem_wait(&mutex);

        item = buffer[out];
        out = (out + 1) % BUFFER_SIZE;
        printf("Consumer %d consume %d \n", id, item);

        sem_post(&mutex);
        sem_post(&empty);
    }
}

int main(){

    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    sem_init(&mutex, 0, 1); // 1--> unlock

    pthread_t pro[PRODUCERS], con[CONSUMERS];
    int p_id[PRODUCERS], c_id[CONSUMERS];
    int i = 0;
    for (i = 0; i < PRODUCERS;i++){
        p_id[i] = i + 1;
        pthread_create(&pro[i], NULL, producer, &p_id[i]);
    }

    for (i = 0; i < CONSUMERS;i++){
        c_id[i] = i + 1;
        pthread_create(&con[i], NULL, consumer, &c_id[i]);
    }

    for (i = 0; i < PRODUCERS;i++){
        pthread_join(&pro[i], NULL);
    }

    for (i = 0; i < CONSUMERS;i++){
        pthread_join(&con[i], NULL);
    }

        return 0;
}
