#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>


#define N 5

sem_t frok[N];

void *philo(void* arg){

    int id = *(int *)arg;
    int left = id;
    int right = (id + 1) % N;

    while(1){
        printf("%d Thinnking....\n", id);

        sem_wait(&frok[left]);
        sem_wait(&frok[right]);

        printf("%d eating....\n", id);
        sleep(1);

        sem_post(&frok[right]);
        sem_post(&frok[left]);
    }
}

int main(){

    pthread_t ph[N];

    int id[N];

    int i = 0;

    for (i = 0; i < N;i++)
        sem_init(&frok[i],0,1);

    for(i = 0; i < N;i++){
        id[i] = i + 1;
        pthread_create(&ph[i], NULL, philo, &id[i]);
    }

    for (i = 0; i < N;i++)
        pthread_join(ph[i],NULL);

        return 0;
}