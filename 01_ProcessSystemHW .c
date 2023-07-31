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

   
    char Buffer[512]={"\0"};
    int iCnt = 0;
    int iRet = 0,i=0;

   

    while((iRet = read((int)ptr,Buffer,sizeof(Buffer)))!=0){

        for(i = 0;i<iRet;i++){
            if((Buffer[i]>='a') && (Buffer[i]<='z')){
                iCnt++;
            }
        }
    }

    printf("No.of small characters are:%d\n",iCnt);


    pthread_exit(NULL);
}
void * ThreadProc2(void * ptr){   

    
    char Buffer[512]={"\0"};
    int iCnt = 0;
    int iRet = 0,i=0;    

    while((iRet = read((int)ptr,Buffer,sizeof(Buffer)))!=0){

        for(i = 0;i<iRet;i++){
            if((Buffer[i]>='A') && (Buffer[i]<='Z')){
                iCnt++;
            }
        }
    }

    printf("No.of Capital characters are:%d\n",iCnt);


    pthread_exit(NULL);
}

int main(){

    pthread_t TID1,TID2;
    int iRet1 = 0, iRet2 = 0,fd = 0;

    fd = open("Demo.txt",O_RDONLY);
    if(fd == -1){
        printf("Error: Unable to open file\n");
        return -1;
    }

    iRet1 = pthread_create(&TID1,          // Address of pthread_attr_t structure object
                        NULL,           // Thread Attributess
                        ThreadProc1,     // Address of callback function
                        (int *)fd);          // Parameters of call back function

    if(iRet1 != 0){
        printf("Error: Unable to create Thread\n");
        return -1;
    }  




    iRet2 = pthread_create(&TID2,          // Address of pthread_attr_t structure object
                        NULL,           // Thread Attributess
                        ThreadProc2,     // Address of callback function
                        (int *)fd);          // Parameters of call back function

    if(iRet2 != 0){
        printf("Error: Unable to create Thread\n");
        return -1;
    }  


    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    printf("End of main Thread\n");
    close(fd);
    pthread_exit(NULL);

    return 0;
}

// Wrong Code  : Because main thread la thambayala sangat nahiye aapan

// Solve : pthread_join() - wait() sarakh.
