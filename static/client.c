#include<stdio.h>
#include"sharedfile.h"
int main(){
    int a = 10,b = 20,ret = 0;
    ret = Addition(a,b);
    printf("Addition:%d",ret);

    return 0;
}

//gcc -static client.c sharedfile.a -o myExe
//./myExe