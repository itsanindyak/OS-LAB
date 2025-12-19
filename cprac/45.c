#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

int shared = 10;

pthread_mutex_t lock;

void *func(void* arg){
    pthread_mutex_lock(&lock);
    printf("thread self %ld\n", pthread_self());
    printf("value of shared= %d and address= %p\n", shared, &shared);

    shared += 5;
    printf("value of shared= %d and address= %p\n", shared, &shared);

    pthread_mutex_unlock(&lock);
}

int main(){
    int n = 4;
    int i = 0;
    pthread_t th[n];

    for (i = 0; i < n;i++)
        pthread_create(&th[i], NULL, func, NULL);
    
    for (i = 0; i < n;i++)
        pthread_join(th[i], NULL);


        return 0;
}