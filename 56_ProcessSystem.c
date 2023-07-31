#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

    printf("Inside Child Process- PID of Parent Process:%d\n",getppid());
    return 0;
}