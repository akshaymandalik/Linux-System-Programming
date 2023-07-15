/*
Problem Statement: Write a program which accept directory name from user and print all file names from that directory.
Author Name: Akshay Mandalik
Last Modified:15 July 2023 11: PM
*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>

int main(int args, char * argv[]){

     DIR *dp = NULL;
     struct dirent *entry = NULL;

     if(args != 2){
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_executable[space]Name of Directory[space]\n");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL){
        printf("Error: Unable to open Directory\n");
        return -1;
    }

    printf("File Names in %s",argv[1]);
    while((entry = readdir(dp))!=NULL){

        printf("%s\n",entry->d_name);

    }


    return 0;
}