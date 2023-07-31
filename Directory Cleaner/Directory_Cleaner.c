#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 1024
#define THREADNO 3
#pragma pack(1)


struct removedFiles{
    char *files[256];
};

void * cleanEmptyFiles(void *ptr){

    char **fileNames = (char **)ptr;
    int iCnt = 0,iCnt1 = 0;
    struct stat sObj;
    struct removedFiles *filesptr = (struct removedFiles *) malloc (sizeof(struct removedFiles));

    while(fileNames[iCnt] != NULL){

        stat(fileNames[iCnt],&sObj);

        if(S_ISREG(sObj.st_mode)){


            if(sObj.st_size == 0){

                filesptr->files[iCnt1] = (char *)malloc(strlen(fileNames[iCnt])+1);
                strcpy(filesptr->files[iCnt1],fileNames[iCnt]);
                remove(fileNames[iCnt]);
                iCnt1++;
            }
        }
        iCnt++;
    }
    
    if(iCnt1 == 0){
        filesptr = NULL;
    }

    pthread_exit(filesptr);
    
}

void * cleanLargeFiles( void * ptr){

    char **fileNames = (char **)ptr;
    int iCnt = 0,iCnt1 = 0;
    struct stat sObj;
    int noofFiles = 0;
    struct removedFiles *filesptr = (struct removedFiles *) malloc (sizeof(struct removedFiles));


    while(fileNames[iCnt] != NULL){

        stat(fileNames[iCnt],&sObj);

        if(S_ISREG(sObj.st_mode)){

            if(sObj.st_size > MAXSIZE){

                filesptr->files[iCnt1] = (char *)malloc(strlen(fileNames[iCnt])+1);
                strcpy(filesptr->files[iCnt1],fileNames[iCnt]);
                remove(fileNames[iCnt]);
                iCnt1++;
            }
        }
        iCnt++;
    }

    if(iCnt1 == 0){
        filesptr = NULL;
    }
    

    pthread_exit(filesptr);
}


void * cleanDuplicateFiles(void *ptr){
    
    char **fileNames = (char **)ptr;
    int iCnt = 0,noOfFiles = 0,iCnt1 = 0,ret = 0,iCnt2 = 0;
    struct stat sObj,sObj1;
    int fd1 = 0;
    int fd2 = 0;
    char *buffer1[MAXSIZE]={"\0"};
    char *buffer2[MAXSIZE]={"\0"};

    struct removedFiles *filesptr = (struct removedFiles *)malloc(sizeof(struct removedFiles));

    while(fileNames[noOfFiles] != NULL){
            noOfFiles++;  
    }

    while( iCnt < noOfFiles-1){

        stat(fileNames[iCnt],&sObj);
        iCnt1 = iCnt+1;
        while(iCnt1 < noOfFiles){

            stat(fileNames[iCnt1],&sObj1);
            if(sObj.st_size == sObj1.st_size){
                    
                    fd1 = open(fileNames[iCnt],O_RDONLY);
                    if(fd1 == -1){
                        printf("Error: Unable to work on %s",fileNames[iCnt]);
                    }

                    fd2 = open(fileNames[iCnt1],O_RDONLY);
                    if(fd2 == -1){
                        printf("Error: Unable to work on %s",fileNames[iCnt1]);
                    }
                    
                    while((ret = read(fd1,buffer1,MAXSIZE))!=0){

                        read(fd2,buffer2,MAXSIZE);
                        if(memcmp(buffer1,buffer2,ret)!=0){
                            break;
                        }
                    }
                    if(ret == 0){

                        filesptr->files[iCnt2] = (char *)malloc(strlen(fileNames[iCnt])+1);
                        strcpy(filesptr->files[iCnt2],fileNames[iCnt]);
                        remove(fileNames[iCnt]);
                        iCnt2++;
                    }
               
            }
            
            iCnt1++;
        }

        iCnt++;
    }

    if(iCnt2 == 0){
        filesptr = NULL;
    }

    pthread_exit(filesptr);

}

int main(){

    int iRet[THREADNO];
    char dirName[256]={"\0"};
    DIR *dir = NULL;
    struct dirent *entry = NULL;
    pthread_t TID[THREADNO];
    char *fileNames[256];
    char pathName[50] = {"\0"};
    int iCnt = 0;
    struct removedFiles **deletedfiles = (struct removedFiles **)malloc(THREADNO * sizeof(struct removedFiles *));
    

    printf("Enter Directory Name:");
    scanf("%s",dirName);

    dir = opendir(dirName);
    if(dir == NULL){

        printf("Error Unable to open Directory\n");
        return -1;
    }

    while((entry = readdir(dir)) != NULL){

        sprintf(pathName,"%s/%s",dirName,entry->d_name);
        fileNames[iCnt] = (char*)malloc(strlen(pathName)+1);
        if(fileNames[iCnt] == NULL){
            printf("Error:Unable to work on %s\n",pathName);
        }
        strcpy(fileNames[iCnt],pathName);
        iCnt++;
    }

    fileNames[iCnt] = NULL;

        iRet[0] = pthread_create(&TID[0],NULL,cleanEmptyFiles,fileNames);
        if(iRet[0] !=0){
        printf("Error: Unable to clean Empty Files\n");
        return -1;
        }

        iRet[1] = pthread_create(&TID[1],NULL,cleanLargeFiles,fileNames);
        if(iRet[1] !=0){
        printf("Error: Unable to clean Empty Files\n");
        return -1;
        }
        
        iRet[2] = pthread_create(&TID[2],NULL,cleanDuplicateFiles,fileNames);
        if(iRet[2] !=0){
        printf("Error: Unable to clean Empty Files\n");
        return -1;
        }
        

    for(iCnt = 0;iCnt<THREADNO;iCnt++){

         pthread_join(TID[iCnt],(void *)&deletedfiles[iCnt]);
    }

    printf("\n=================================Summary=================================\n");
    iCnt = 0;
    printf("\n\t\tDeleted Empty Files:");
    if(deletedfiles[0] != NULL){
        while(deletedfiles[0]->files[iCnt] != NULL){
        printf("\n\t\t\t\t\tFile[%d]:%s\n",iCnt,deletedfiles[0]->files[iCnt]);
        iCnt++;
      }
    }
    else{
        printf(" [ No Empty Files Found]\n");
    }

    iCnt = 0;
    printf("\n\t\tDeleted Large Files:");
    if(deletedfiles[1] != NULL){
        while(deletedfiles[1]->files[iCnt] != NULL){
        printf("\n\t\t\t\t\tFile[%d]:%s\n",iCnt,deletedfiles[1]->files[iCnt]);
        iCnt++;
      }
    }
    else{
        printf(" [ No Large Files Found]\n");
    }
    iCnt = 0;
    printf("\n\t\tDeleted Duplicate Files:");
    if(deletedfiles[2] != NULL){
        while(deletedfiles[2]->files[iCnt] != NULL){
        printf("\n\t\t\t\t\tFile[%d]:%s\n",iCnt,deletedfiles[2]->files[iCnt]);
        iCnt++;
      }
    }
    else{
        printf(" [ No Duplicate Files Found]\n");
    }
    pthread_exit(NULL);

    return 0;
}