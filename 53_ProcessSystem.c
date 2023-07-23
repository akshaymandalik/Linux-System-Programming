#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int args, char *argv[]){ 

    printf("PID is:%d\n",getpid());
    printf("%s %s %s",argv[0],argv[1],argv[2]);

    return 0;

}