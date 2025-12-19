#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_mutex_t lock;

int shared = 10;

void *increment(void* arg){
    pthread_mutex_lock(&lock);
    shared += 5;
    printf("shared= %d\n", shared);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){

    int n = 3;

    pthread_t th[n];

    pthread_mutex_init(&lock,NULL);

    for (int i = 0; i < n;i++)
        pthread_create(&th[i], NULL, increment, NULL);
    
    for (int i = 0; i < n;i++)
        pthread_join(th[i], NULL);

    printf("Atlast shared= %d\n", shared);

    return 0;
}