#include<stdio.h>
#include"Problem1-SharedFile.h"

void addition(){

    int iVal1 = 0, iVal2 = 0;
    printf("Enter First Number:");
    scanf("%d",&iVal1);
    printf("Enter Second Number:");
    scanf("%d",&iVal2);

    printf("Addition: %d",(iVal1+iVal2));
}

void subtraction(){

    int iVal1 = 0, iVal2 = 0;
    printf("Enter First Number:");
    scanf("%d",&iVal1);
    printf("Enter Second Number:");
    scanf("%d",&iVal2);

    printf("Subtraction: %d",(iVal1-iVal2));
}
void multiplication(){

    int iVal1 = 0, iVal2 = 0;
    printf("Enter First Number:");
    scanf("%d",&iVal1);
    printf("Enter Second Number:");
    scanf("%d",&iVal2);

    printf("Multiplication: %d",(iVal1*iVal2));
}
void division(){

    int iVal1 = 0, iVal2 = 0;
    printf("Enter First Number:");
    scanf("%d",&iVal1);
    printf("Enter Second Number:");
    scanf("%d",&iVal2);

    printf("Division: %d",(iVal1/iVal2));
}