#include<stdio.h>
#include "Problem3.h"
#define TRUE 1
#define FALSE 0
int checkPrime(int iNum){

    int iCnt = 0;
    int isPrime = TRUE;
    for(iCnt = 2;iCnt <= (iNum/2);iCnt++){
            if(iNum % iCnt == 0){

                    isPrime = FALSE;
                    break;
            }
    }  

    if(isPrime == FALSE){

        return -1;
    }

    return 0;

}