#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){ 

    int ret = 0;
    ret = fork();

    if(ret == 0){
        printf("Child Process is Running\n");
        printf("MY Pid:%d\n",getpid());
    }else{
        printf("Parent Process is Running\n");
        printf("PID of Child Process is:%d\n",ret);
    }

    return 0;

}