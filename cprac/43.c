#include<stdio.h>
#include<sys/types.h>
#include<ctype.h>
#include<unistd.h>

int main(){
    int fd[2];

    char buffer[100];

    pipe(fd);

    pid_t pid = fork();

    if(pid>0){

        close(fd[0]);
        printf("Enter the text : ");
        scanf("%s", buffer);

        write(fd[1], buffer, sizeof(buffer));

        close(fd[1]);
    }
    else if (pid == 0)
    {
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));
        int alpha=0,numeric=0, spChar = 0;

        for (int i = 0; buffer[i] != '\0'; i++){
            char ch = buffer[i];
            if(isalpha(ch))
                alpha++;
            else if(isdigit(ch))
                numeric++;
            else if(ispunct(ch))
                spChar++;
        }

        printf("alphabet=%d\n", alpha);
        printf("numeric =%d\n", numeric);
        printf("special character=%d\n", spChar);
    }

    return 0;
}
