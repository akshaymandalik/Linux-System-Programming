#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include "Problem2-SharedFile.h"
#include<sys/stat.h>
#include<string.h>
#define MAXSIZE 1024

int CompareContent(char *argv[]){

    int fd1 = 0;
    int fd2 = 0;
    int isExists = 0;
    int isReadable = 0;
    char *buffer1[MAXSIZE]={"\0"};
    char *buffer2[MAXSIZE]={"\0"};
    struct stat sObj1;
    int file1Size = 0;
    int file2Size = 0;
    int ret = 0;
    

    isExists = access((argv[1]),F_OK);
    if(isExists == 0){

            isExists = access((argv[2]),F_OK);
            if(isExists == 0){

                isReadable = access((argv[1]),R_OK);
                if(isReadable == 0){

                    isReadable = access((argv[2]),R_OK);
                    if(isReadable == 0){
                            
                        stat(argv[1],&sObj1);
                        file1Size = sObj1.st_size;
                        stat(argv[2],&sObj1);
                        file2Size = sObj1.st_size;

                        if(file1Size != file2Size){
                            printf("Error: Files have different size\n");
                            return -1;
                        }

                        fd1 = open(argv[1],O_RDONLY);
                        if(fd1 == -1){
                            printf("Error: Unable to open %s",argv[1]);
                            return -1;
                        }
                        fd2 = open(argv[2],O_RDONLY);
                        if(fd2 == -1){
                            printf("Error: Unable to open %s",argv[2]);
                            return -1;
                        }

                        int iCnt = 1;
                        while((ret = read(fd1,buffer1,MAXSIZE)) != 0){

                            
                            ret = read(fd2,buffer2,MAXSIZE);
                            if((memcmp(buffer1,buffer2,ret))!=0){
                                break;
                            }

                        }
                        if(ret == 0){
                            return 0;
                        }
                        else{
                            return -1;
                        }
                        

                    }
                    else if(errno == EACCES){
                    printf("Error: No access to read %s",(argv[2]));
                    return -1;
                }
                }
                else if(errno == EACCES){
                    printf("Error: No access to read %s",(argv[1]));
                    return -1;
                }
                    
            }
            else{
                printf("Error: %s does not exists\n",(argv[2]));
                return -1;
            }
    }
    else{
        printf("Error: %s does not exists\n",(argv[1]));
        return -1;
    }
    
    return 0;
}

