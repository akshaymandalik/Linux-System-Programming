#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *printNum(void *ptr){
    
    int *limit = (int*)ptr;
    for(register int iCnt = 1;iCnt<(*limit);iCnt++){

        printf("%d\n",iCnt);
    }

    pthread_exit(NULL);
}

void *printNum1(void *ptr){

    int *limit = (int *)ptr;
    for(register int iCnt = (*limit);iCnt >=1;iCnt--){
        printf("%d\n",iCnt);
    }
    pthread_exit(NULL);
}


int main()
{

    pthread_t TID1,TID2;
    int iRet1 =0,iRet2 = 0;
    int input1 = 500;

    iRet1 = pthread_create(&TID1,NULL,printNum,(void *)&input1);
    if(iRet1 != 0){
        printf("Something Went Wrong!!");
        return -1;
    }

    iRet2 = pthread_create(&TID2,NULL,printNum1,(void *)&input1);
    if(iRet2 != 0){
        printf("Something Went Wrong!!");
        return -1;
    }

    pthread_join(TID1,NULL);
    pthread_join(TID2,NULL);

    return 0;
}