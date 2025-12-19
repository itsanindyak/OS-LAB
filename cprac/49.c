#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

#define READER 5
#define WRITER 2


int readCount = 0;
int sharedResource = 0;

sem_t rw_mutex, mutex,writetry;

void *reader(void *arg){
    int id = *(int *)arg;

    while (1)
    {
        sem_wait(&writetry);//<==
        sem_post(&writetry);//<==

        sem_wait(&mutex);
        readCount++;
        if(readCount == 1)
            sem_wait(&rw_mutex);
        sem_post(&mutex);
        //

        printf("Reader %d read %d\n", id, sharedResource);
        sleep(1);

        //

        sem_wait(&mutex);
        readCount--;
        if(readCount ==0)
            sem_post(&rw_mutex);
        sem_post(&mutex);
        sleep(1);
    }
}

void *writer(void *arg){
    int id = *(int *)arg;

    while (1)
    {
        sem_wait(&writetry);//<==
        sem_wait(&rw_mutex);

        sharedResource++;
        printf("Writer %d write %d\n", id, sharedResource);
        sleep(1);

        sem_post(&rw_mutex);
        sem_post(&writetry);//<===
        sleep(1);
    }
}

int main(){
    pthread_t read[READER], write[WRITER];

    int r_id[READER], w_id[WRITER];
    int i = 0;

    sem_init(&mutex, 0, 1);
    sem_init(&rw_mutex, 0, 1);
    sem_init(&writetry, 0, 1);

    for (i = 0; i < WRITER;i++){
        w_id[i] = i + 1;
        pthread_create(&write[i], NULL, writer, &w_id[i]);
    }

    for (i = 0; i < READER;i++){
        r_id[i] = i + 1;
        pthread_create(&read[i], NULL, reader, &r_id[i]);
    }

    for (i = 0; i < WRITER;i++)
        pthread_join(write[i], NULL);
    

    for (i = 0; i < READER;i++)
        pthread_join(read[i], NULL);
    
    

        return 0;
}