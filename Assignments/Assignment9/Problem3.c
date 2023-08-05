#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/resource.h>
int main(){

    int PID = 0,iPriority = 0;
    PID = getpid();
    iPriority = getpriority(PRIO_PROCESS,PID);
    printf("PID:%d,Priority of Process is %d",PID,iPriority);
    return 0;
}