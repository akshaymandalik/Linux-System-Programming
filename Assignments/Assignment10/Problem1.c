#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void * findEven(void *ptr){

    int *iVal = (int *)ptr;
    printf("%d\n",*iVal);
    pthread_exit(iVal);
}

int main(){

    pthread_t TID;
    int iRet = 0;
    int iNo = 0;
    void *Result = 0;
    
    printf("Enter A Number:");
    scanf("%d",&iNo);

    iRet = pthread_create(&TID,NULL,findEven,(void *)&iNo); 
    if(iRet != 0){
        printf("Error:Unable to call function\n");
    }

    pthread_join(TID,&Result);
    printf("%d\n",*(int *)Result);

    return 0;
}