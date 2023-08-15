//Hard Link

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){

    char FileName1[256],FileName2[256];

    int iRet = 0;

    printf("Enter Existing file Name:");
    scanf("%s",FileName1);

    printf("Enter Hard Link file Name:");
    scanf("%s",FileName2);

    iRet = link(FileName1,FileName2);

    if (iRet == 0 ){
        printf("Hard Link Gets Created Successfully\n");
    }

    printf("%d",iRet);

    return 0;   
}