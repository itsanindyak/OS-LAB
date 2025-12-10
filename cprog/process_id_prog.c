#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

// NOTE: Parent process should terminate after child has terminated (good practice)
// If the parent exits first, the child becomes an orphan and is adopted by PID 1
// we will hault child and complete parent but parent will wait for the children 
// getpid() → returns the process’s own PID, getppid() → returns the parent’s PID.
// wait(NULL) → returns the PID of a terminated child; returns -1 only if there are no child processes

int main(){
	int id=fork();
	if(id==0){
		//sleep(1); /// intentionally making child sleep so that parent can complete execution
	}
	printf("Process ID: %d and Parent ID: %d \n",getpid(),getppid());
	
	int w=wait(NULL); //parent will wait for child but child has noone to wait for
	if(w==-1){
		printf("Process %d: no children to wait for.\n", getpid());
	}else{
		printf("Parent %d waited for child %d\n", getpid(), w);
	}
	
}
