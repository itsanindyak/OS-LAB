#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
//consider a array , child will calculate sum of half and parent will do the half, later child will send the sum to parent , parent will add it with its sum to give the total sum
int main(void){
	int arr[]={1,8,3,0,1,5,2};
	int len=sizeof(arr)/sizeof(arr[0]);
	int start,end,sum=0;
	int fd[2];
	int pipeid=pipe(fd);
	int id=fork();
	if(id==0){
		start=0;
		end=len/2;
	}else{
		start=len/2;
		end=len;
	}
	for(int i=start;i<end;i++){
		sum=sum+arr[i];
	}
	if(id==0){
		printf("sum from child= %d \n",sum);
	}
	if(id>0){
		printf("sum from parent= %d \n",sum);
	}
	
	if(id==0){
		close(fd[0]);
		write(fd[1],&sum,sizeof(sum));
		close(fd[1]);
	}else{
		int partialsum;
		close(fd[1]);
		read(fd[0],&partialsum,sizeof(partialsum));
		close(fd[0]);
		int totalsum=partialsum+sum;
		printf("Total sum is : %d",totalsum);
	}
	return 0;
}
