/*
Problem Statement:
Author Name: Akshay Mandalik
Last Modified: Sat 15 July 9:26 AM
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.hcle>
#pragma pack(1)

struct Student{
    int Roll_no;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int args, char *argv[]){

    char fName[20];
    int fd = 0;

    struct Student sObj;
    sObj.Roll_no = 11;
    strcpy(sObj.Sname,"Akshay");
    sObj.Marks = 98.99f;
    sObj.Age = 21;

    printf("Enter File Name");
    scanf("%s",fName);

    fd = creat(fName,0777);

    write(fd,&sObj,sizeof(sObj));

    return 0;
}