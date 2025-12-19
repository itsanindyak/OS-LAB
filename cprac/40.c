#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>


int isPrime(int num){
    if(num==2)
        return 1;
    if(num%2 ==0)
        return 0;

    for (int i = 3; i * i <= num; i=i+3){
        if(num%i == 0){
            return 0;
        }
    }
    return 1;
}

int main(){

    int fd[2];
    int num;
    pipe(fd);

    pid_t pid = fork();

    if(pid > 0){
        close(fd[0]);

        printf("Enter a number");
        scanf("%d", &num);

        write(fd[1], &num, sizeof(num));
        close(fd[1]);
    }
    else if (pid == 0){
        close(fd[1]);

        read(fd[0], &num, sizeof(num));
        
        if(isPrime(num)){
            printf("%d is prime number", num);
        }else{
            printf("%d is not prime number", num);
        }

        close(fd[0]);
    }

        return 0;
}