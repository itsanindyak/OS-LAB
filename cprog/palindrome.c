#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
int palindrome(char s[]){
    int i=0;
    int j=strlen(s)-1;
    int c=1;// default=palindrome
    while(i!=j){
        if(s[i]!=s[j]){
            c=0;//not palindrome
            break;
        }
        i++;
        j--;
    }
    return c;

}
int main(){
    int fd[2];
    pipe(fd);
    int id=fork();
    if (id==0){
        char inputstr[100];
        close(fd[0]);
        printf("enter a str: ");
        scanf("%s",inputstr);
        write(fd[1],inputstr,sizeof(inputstr));
        close(fd[1]);
    }
    if(id>0){
        char str[100];
        close(fd[1]);
        read(fd[0],str,sizeof(str));
        close(fd[0]);
        int res;
        res=palindrome(str);
        if(res==0){
            printf("not palindrome\n");
        }
        else
            printf("palindrome\n");
        }
    }


