#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>
/*
        Client for Shared Memory 
*/

int main(){

    int shmid = 0;
    int shmsize = 100;
    int key =1234;

    char *ptr = NULL;

    printf("Client Application Running\n");

    shmid = shmget(key,shmsize,0666);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL){
        printf("Shared Memory Attached successfully\n");
    }

    return 0;
}

