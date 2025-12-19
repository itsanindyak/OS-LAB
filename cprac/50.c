#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

#define SIZE 5


int a[SIZE];

sem_t sem;

void* input(void* arg){

    printf("Enter element upto %d : ",SIZE);
    for (int i = 0; i < SIZE;i++){
        scanf("%d", &a[i]);
    }

    sem_post(&sem);
}

void* search(void * arg){
    sem_wait(&sem);

    int element;
    printf("Enter the serach element: ");
    scanf("%d", &element);
    for (int i = 0; i < SIZE;i++){
        if(a[i]== element){
            printf("%d is found", a[i]);
            return NULL;
        }
    }
    printf("%d is not found", element);
    return NULL;
}

int main(){
    pthread_t th1, th2;

    sem_init(&sem, 0,0);

    pthread_create(&th1, NULL, input, NULL);
    pthread_create(&th2, NULL, search, NULL);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    sem_destroy(&sem);

    return 0;
}
