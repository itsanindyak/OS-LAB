#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<pthread.h>
#include <stdlib.h>


// we are inputing a number , calling the thread to square it and returning the value

void* square(void* a){  //format return type: void* and arg also void*
	int num=*(int*)a; // convert a to int pointer and then extracting the value
	num=num*num;
	int* result=malloc(sizeof(4));  // stack will clear after func call, so we create entry in heap memory
	*result=num;   //putting the value
	return (void*)result;   //as return type is void* 
}

int main(){
	int a;
	printf("Enter a number: ");
	scanf("%d",&a);
	pthread_t t1;
	pthread_create(&t1,NULL,&square,&a);  //last parameter takes the arg of function
	int* res;
	pthread_join(t1,(void**)&res);  //last parameter is the return value, thread return the value before you die 
	printf("Result after squaring...%d",*res); 
	free(res);
	return 0;
}
