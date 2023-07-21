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

struct Employee{
    int EmpId;
    char EName[20];
    char Edesignation[50];
    int Age;
};


int main(int args, char *argv[]){

    char fName[20];
    int fd = 0;

    struct Employee emp1;
    emp1.EmpId = 1;
    strcpy(emp1.EName,"Akshay");
    strcpy(emp1.Edesignation,"CEO");
    emp1.Age = 23;

    printf("Enter File Name:");
    scanf("%s",fName);

    fd = creat(fName,0777);

    write(fd,&emp1,sizeof(emp1));
    if(fd == -1){
        printf("Error: Unable to create File\n");
        return -1;
    }

    write(fd,&emp1,sizeof(emp1));


    return 0;
}