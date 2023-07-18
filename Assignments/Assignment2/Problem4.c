/*
Problem Statement: Write a program which accept directory name 
                   from user and print all file names and its 
                   types from that directory.
Author Name:Akshay Mandalik
Last Modified:Sunday,16July,3:08 PM
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
int main(int args, char *argv[]){

    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char fileType[20]={"\0"};
    if(args != 2){
        printf("Error: Invalid Arguments\n ");
        return 0;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Error: Unable to open directory\n");
        closedir(dp);
        return -1;
    }

    printf("Filename\t\tType\n");
    while((entry = readdir(dp))!= NULL){

        if(entry->d_type == 4){
            strcpy(fileType,"Directory");
        }else if(entry->d_type == 8){
            strcpy(fileType,"Regular File");
        }
        else{
             strcpy(fileType,"Special File");

        }
        printf("%s\t\t%s\n",entry->d_name,fileType);   

    }
    closedir(dp);

    return 0;
}