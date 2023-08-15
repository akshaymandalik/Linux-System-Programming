#include<stdio.h>

int Addition(int iVal1,int iVal2){

    return iVal1+iVal2;
}

int main(){
    int iVal=10,iVal2=10;
    int iRet = 0;
    iRet = Addition(iVal,iVal2);

    printf("Addtion is:%d\n",iRet);

}