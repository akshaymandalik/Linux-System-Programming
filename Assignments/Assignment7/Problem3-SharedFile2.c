#include<stdio.h>
#include "Problem3.h"

int checkPerfect(int iVal){

    int iCnt = 0;
    int iSum = 1;
    for(iCnt = 2;iCnt<=(iVal/2);iCnt++){

        if(iVal % iCnt == 0){
            iSum = iSum + iCnt;
        }
    }
    if(iSum != iVal){
        return -1;
    }

    return 0;
}