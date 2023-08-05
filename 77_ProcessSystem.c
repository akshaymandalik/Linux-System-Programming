#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

/*
Mutual Exclusion
*/

int Counter = 0;

pthread_mutex_t lock;

void * ThreadProc(void * ptr){   

     pthread_mutex_lock(&lock);
    
     Counter++;

     printf("Thread Executed with counter:%d\n",Counter);
     
     printf("Thread Completed with counter:%d\n",Counter);

     pthread_exit(NULL);        
}

int main(){

    pthread_t TID,TID1;
    int iRet = 0,iRet1 = 0;
    
    pthread_mutex_init(&lock,NULL);

    iRet = pthread_create(&TID,          // Address of pthread_attr_t structure object
                        NULL,           // Thread Attributess
                        ThreadProc,     // Address of callback function
                        NULL);          // Parameters of call back function

    if(iRet != 0){
        printf("Error: Unable to create Thread\n");
        return -1;
    }  

    iRet1 = pthread_create(&TID1,          // Address of pthread_attr_t structure object
                        NULL,           // Thread Attributess
                        ThreadProc,     // Address of callback function
                        NULL);          // Parameters of call back function

    if(iRet1 != 0){
        printf("Error: Unable to create Thread\n");
        return -1;
    }  

    pthread_join(TID,NULL);
    pthread_join(TID1,NULL);

    pthread_mutex_destroy(&lock);

    pthread_exit(NULL);

    return 0;
}

// Wrong Code  : Because main thread la thambayala sangat nahiye aapan

// Solve : pthread_join() - wait() sarakh.
