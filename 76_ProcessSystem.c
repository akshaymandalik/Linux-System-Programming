#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<pthread.h>

/*
    Demonstration of MultiThreading
*/

// void * <Any Name>(void * <Any Name>)

/*
    Call Back Function: Call Nahi karayacha te apoaap call hot kiva dusarya function ne call krata yet.
    Prototype: Fixed.
    Pthread_create 3rd parameter means thread create zalyavr threadproc call krr 4th parameter arguments to 3rd function.
    1st parameter : Thread id parat milto
    2nd parameter: Attributes
*/

int Counter = 0;
void * ThreadProc(void * ptr){   

     int i=0;
     Counter++;
     printf("Thread Executed with counter:%d\n",Counter);
     for(i = 0; i< 0xFFFFFFFF;i++);
     printf("Thread Completed with counter:%d\n",Counter);

    pthread_exit(NULL);        
}

int main(){

    pthread_t TID,TID1;
    int iRet = 0,iRet1 = 0;
    

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


    return 0;
}

// Wrong Code  : Because main thread la thambayala sangat nahiye aapan

// Solve : pthread_join() - wait() sarakh.
