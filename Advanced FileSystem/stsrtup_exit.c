//Program to demostrate startup and exit using #pragma.
#include<stdio.h>
#pragma startup fun
#pragma exit sun

int k;
void fun()
{
    k = 10;
    exit(0);
}

void sun()
{

}



int main()
{
printf("\nIn main");
printf("  %d:",k);
return 0;
}


