#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>

#define SIZE 3

sem_t mutex;

int a[SIZE];

void *input(void *arg){

    printf("Enter %d elements : ", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", &a[i]);
    }
        sem_post(&mutex);
        return NULL;
}
void *reverse(void *arg){
    sem_wait(&mutex);

    for (int i = SIZE - 1; i >= 0;i--){
        printf("%d\t", a[i]);
    }
    return NULL;
}

int main(){
    pthread_t th1, th2;

    sem_init(&mutex, 0, 0);
    pthread_create(&th1, NULL, input, NULL);
    pthread_create(&th2, NULL, reverse, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}