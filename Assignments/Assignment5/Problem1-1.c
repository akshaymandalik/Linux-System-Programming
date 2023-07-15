/*
Problem Statement:
Author Name: Akshay Mandalik
Last Modified: Sat 15 July 9:26 AM
*/
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#pragma pack(1)

struct Student{
    int Roll_no;
    char Sname[20];
    float Marks;
    int Age;
};

struct Fileinfo{

    char fName[20];
    int fileSize;
};

int main(int args, char *argv[]){

    char fName[20];
    int fd = 0;

    // struct Student sObj;
    struct Fileinfo fObj;
    // sObj.Roll_no = 11;
    // strcpy(sObj.Sname,"Akshay");
    // sObj.Marks = 98.99f;
    // sObj.Age = 21;

    printf("Enter File Name");
    scanf("%s",fName);

    fd = open(fName,O_RDONLY);

    read(fd,&fObj,sizeof(fObj));

    // printf("Roll No:%d\n",sObj.Roll_no);
    // printf("Name:%s\n",sObj.Sname);
    // printf("Marks:%f\n",sObj.Marks);
    // printf("Age:%d\n",sObj.Age);

    printf("File Name \t\t FileSize\n");
    printf("%s\t\t%d\n",fObj.fName,fObj.fileSize);

    return 0;
}