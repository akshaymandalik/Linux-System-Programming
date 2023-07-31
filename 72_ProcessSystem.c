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

void * ThreadProc1(void * ptr){   

    printf("Thread 1\n");

    pthread_exit(NULL);
}
void * ThreadProc2(void * ptr){   

    printf("Thread 2\n");

    pthread_exit(NULL);
}

int main(){

    pthread_t TID1,TID2;
    int iRet1 = 0, iRet2 = 0;

    iRet1 = pthread_create(&TID1,          // Address of pthread_attr_t structure object
                        NULL,           // Thread Attributess
                        ThreadProc1,     // Address of callback function
                        NULL);          // Parameters of call back function

    if(iRet1 != 0){
        printf("Error: Unable to create Thread\n");
        return -1;
    }  

    printf("Thread 1 is created with ID:%u\n",TID1);



    iRet2 = pthread_create(&TID2,          // Address of pthread_attr_t structure object
                        NULL,           // Thread Attributess
                        ThreadProc2,     // Address of callback function
                        NULL);          // Parameters of call back function

    if(iRet2 != 0){
        printf("Error: Unable to create Thread\n");
        return -1;
    }  

    printf("Thread 2 is created with ID:%u\n",TID2);

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("End of main Thread\n");

    pthread_exit(NULL);

    return 0;
}

// Wrong Code  : Because main thread la thambayala sangat nahiye aapan

// Solve : pthread_join() - wait() sarakh.
