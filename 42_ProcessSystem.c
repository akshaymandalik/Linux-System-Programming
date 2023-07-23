#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

    int P_ID = 0;

    P_ID = getpid();
    printf("PID of running process is:%d\n",P_ID);

    for(;;){

    }
    
    return 0;
}