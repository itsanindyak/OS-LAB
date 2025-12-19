#include<pthread.h>
#include<stdio.h>
#include<unistd.h>

int shared;

pthread_mutex_t lock;

void *input(void* arg){
    pthread_mutex_lock(&lock);

    printf("Enter a number :");
    scanf("%d", &shared);

    pthread_mutex_unlock(&lock);
}

void *factorial(void* arg){
    pthread_mutex_lock(&lock);

    int result = 1;
    for (int i = 1; i <= shared; i++)
    {
        result = result * i;
    }

    printf("Factorial is %d\n", result);
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *prime(void* arg){
    pthread_mutex_lock(&lock);

    if(shared==2)
        printf(" %d is prime\n", shared);
    if(shared%2 ==0)
        printf(" %d is not prime\n", shared);

    for (int i = 3; i * i <= shared; i=i+3){
        if(shared%i == 0){
            printf(" %d is prime\n", shared);
        }
    }
    printf(" %d is not prime\n", shared);


    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(){
    pthread_t i, f, p;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&i, NULL, input, NULL);
    pthread_join(i, NULL);

    pthread_create(&f, NULL, factorial, NULL);
    pthread_create(&p, NULL, prime, NULL);

    pthread_join(f, NULL);
    pthread_join(p, NULL);

    return 0;
}