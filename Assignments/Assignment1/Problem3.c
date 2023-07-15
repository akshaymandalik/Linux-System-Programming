/*
Problem Statement: Write a program which accept file name and on mode and that program check whether our process can access that file in accepted mode or not.
Author Name: Akshay Mandalik
Last Modified: Friday 14 July 10:18 AM
*/

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#define TRUE 1
#define FALSE 2
int main(int args,char *argv[]){

    int checkAccess = -1;
    int flag = FALSE;

    if(args!=3){
        printf("Error:Invalid Arguments\n");
        printf("Usage:Name_of_Executable[space]Name_of_file[space]File_opening_mode");
        return -1;
    }

    checkAccess = access(argv[1],F_OK);
    if(checkAccess == 0){
        if(strcmp(argv[2],"Read")==0){
             
             checkAccess = access(argv[1],R_OK);
             if(checkAccess == 0){
                
                flag = TRUE;

             }
        }
        else if(strcmp(argv[2],"Write")==0){
             
             checkAccess = access(argv[1],W_OK);
             if(checkAccess == 0){
                
                flag = TRUE;

             }
        }
        else if(strcmp(argv[2],"Execute")==0){
             
             checkAccess = access(argv[1],X_OK);
             if(checkAccess == 0){
                
                flag = TRUE;

             }
        }

    }else if(errno == ENOENT){
        printf("File Does not Exists!!");
        return -1;
    }

    if(flag == TRUE){
        printf("%s is accessible with %s mode\n",argv[1],argv[2]);
    }
    else{
        printf("%s is not accessible with %s mode\n",argv[1],argv[2]);
    }



    return 0;
}