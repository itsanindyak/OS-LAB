#include<pthread.h>
#include<stdio.h>

#define MAX 5

pthread_mutex_t lock;
int arr[MAX];

void *input(void* arg){

    pthread_mutex_lock(&lock);

    printf("Enter %d elements:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &arr[i]);
    }

    pthread_mutex_unlock(&lock);
    return NULL;
}
void *bubblesort(void *arg){

    pthread_mutex_lock(&lock);
    

    for (int i = 0; i < MAX-1;i++){
        for (int j = 0; j < MAX - i - 1;j++){
            if(arr[j]> arr[j+1]){
                int swap = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = swap;
            }
        }
    }
    printf("Sorted array:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    pthread_mutex_unlock(&lock);
}

int main(){
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);

    pthread_create(&t1, NULL, input, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, bubblesort, NULL);
    pthread_join(t2, NULL);


    return 0;
}