/*
Problem Statement:Write a program which accept file name from user which contains information of emloyee, we have to read all contents of that file.
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

    printf("Enter File Name");
    scanf("%s",fName);

    fd = open(fName,O_RDONLY);

    read(fd,&emp1,sizeof(emp1));

    printf("Employee Id: %d\n",emp1.EmpId);
    printf("Employee Name: %s\n",emp1.EName);
    printf("Employee Designation: %s\n",emp1.Edesignation);
    printf("Employee Age: %d\n",emp1.Age);


    return 0;
}