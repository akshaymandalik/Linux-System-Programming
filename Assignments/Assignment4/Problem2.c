/*
    Problem Statement: Write a a program which accept directory name from user and create new directory of that name.
    Author Name: Akshay Mandalik
    Last Modified: 19 July 2023 
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int args, char *argv[]){

    int status = 0;
    if(args != 2){
        printf("Error: Invalid Arguments\n");
        return -1;
    }

    status = mkdir(argv[1],S_ISVTX);
    if(status == -1){
        printf("Unable to create Directory\n");
        return -1;
    }

    printf("Directory Created Successfully\n");

    return 0;
}