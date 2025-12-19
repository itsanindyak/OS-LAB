#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int power(int base, int power){
    int result=1;
    for (int i = 0; i < power; i++)
    {
        result = result * base;
    }
    return result;
}

int isArm(int num){
    int count = 0;

    int sum = 0;
    int ref = num;
    int ref2 = num;
    int reminder;
    while (ref != 0)
    {
        ref = ref / 10;
        count++;
    }

    while (num != 0)
    {
        reminder = num % 10;
        sum = sum + power(reminder, count);
        num = num / 10;
    }

    if(sum == ref2){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int fd[2];
    int num;

    pipe(fd);

    pid_t pid = fork();

    if(pid>0){
        close(fd[0]);
        printf("Enter a number");
        scanf("%d", &num);

        write(fd[1], &num, sizeof(num));

        close(fd[1]);
    }
    else if(pid == 0)
    {
        close(fd[1]);
        
        read(fd[0], &num, sizeof(num));
        if(isArm(num)){
            printf("%d is Armstrong  ",num);
        }else{
            printf("%d is not Armstrong  ",num);
        }

        close(fd[0]);

    }

    return 0;
}