#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/shm.h>
/*
        Server for Shared Memory 
*/

int main(){

    int shmid = 0;
    int shmsize = 100;
    int key =1234;

    char *ptr = NULL;

    printf("Server Application Running\n");

    shmid = shmget(key,shmsize,IPC_CREAT | 0666);

    printf("Shared Memory Created Successfully\n");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL){
        printf("Shared Memory Attached successfully\n");
    }


    *ptr ='H';
    ptr++;
    *ptr ='E';
    ptr++;
    *ptr ='L';
    ptr++;
    *ptr ='L';
    ptr++;
    *ptr ='O';
    ptr++;
    *ptr = '\0';

    return 0;
}

