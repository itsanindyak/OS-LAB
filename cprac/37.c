#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>


int main(){
    // fd[0]--->read    fd[1] ---> write end
    int fd[2];
    int num;

    pipe(fd);

    pid_t pid = fork();

    if (pid >0){

        close(fd[0]);

        printf("Enter the number");
        scanf("%d", &num);

        write(fd[1], &num, sizeof(num));

        close(fd[1]);
    }else if (pid ==0){

        close(fd[1]);

        read(fd[0], &num, sizeof(num));

        close(fd[0]);

        printf("[child] Factorial of %d are :", num);
        printf("1, ");
        for (int i = 2; i <= num / 2;i++){
            
            if (num % i == 0)
            {
                printf("%d, ", i);
            }
        }
        printf("%d\n",num);
    }

    return 0;
}