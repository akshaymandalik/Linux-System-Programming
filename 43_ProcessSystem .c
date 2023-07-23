#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

    int P_ID = 0;
    int PP_ID = 0;

    P_ID = getpid();
    PP_ID = getppid();
    printf("PID of running process is:%d\n",P_ID);
    printf("PPID of running process is:%d\n",PP_ID);


   
    
    return 0;
}