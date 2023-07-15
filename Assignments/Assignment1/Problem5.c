/*
Problem Statement: Write a program which accept file name and number of bytes from user and read that number of bytes from file
Author Name: Akshay Mandalik
Last Modified: Sat 15 July 2023 4:59PM
*/
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
int main(int args, char *argv[]){

    int isExists = -1;
    int isReadable = -1;
    char *buffer = NULL;
    int size = 0;
    int fd = 0;
    int ret = 0;
    if(args!=3){
        printf("Error: Invalid Arguments!!\n");
        printf("Usage:Name_of_Executable[space]Name_of_file[space]No_of_bytes_to_read");
        return -1;
    }

    size = atoi(argv[2]);
    if(size<=0){
        printf("Error: Can't read 0 or less than 0 bytes");
        return -1;
    }

    buffer = (char *)malloc(size);
    if(buffer == NULL){
        printf("Error: Unable to read\n");
        return -1;
    }

    

    isExists = access(argv[1],F_OK);


    if(isExists == 0){

        isReadable = access(argv[1],R_OK);
        if(isReadable == 0){

                fd = open(argv[1],O_RDONLY);
                if(fd == -1){
                    printf("Error: Unable to open File\n");
                    free(buffer);
                    return -1;
                }
                printf("Reading....\n");
                ret = read(fd,buffer,size);
                if(ret == -1){
                    printf("Error:Unable to read file.\n");
                    free(buffer);
                    close(fd);
                    return -1;
                }
                close(fd);
        }
        else if(errno == EACCES){
            printf("File is not Readable\n");
            free(buffer);
            return -1;
        }

    }
    else if(errno == ENOENT){
        printf("File Does not exists\n");
        free(buffer);
        return -1;
    }

    write(1,buffer,ret);

    
    free(buffer);
    return 0;
}