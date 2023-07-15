/*
Problem Statement: Write a program which accept file name from user and write string in that file.
Author Name: Akshay Mandalik
Last Modified:15 July 2023 11:06 PM
*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int main(int args,char *argv[]){

    int isExists=-1;
    int isReadable =-1;
    int fd = 0;
    char buffer[100]={"\0"};

    if(args != 3){
        printf("Error: Invalid Arguments\n");
        printf("Usage: Name_of_executable[space]Name of file[space]String to write in file\n");
        return -1;
    }

    isExists = access(argv[1],F_OK);
    
    if(isExists == 0){

        isReadable = access(argv[1],R_OK);
        if(isReadable == 0){


            fd = open(argv[1],O_RDONLY);
            if(fd == -1){
                printf("Error: Unable to open file\n");
                close(fd);
                return -1;
            }
            strcpy(buffer,argv[2]);
           
            write(fd,buffer,sizeof(buffer));
            
            close(fd);

        }else if(errno == EACCES){
            printf("Error: No permission to read file\n");
            return -1;
        }

    }
    else if(errno == ENOENT)
    {
        printf("Error: File does not exists\n"); 
        return -1;
    }

    return 0;
}