#include<stdio.h>
#include<unistd.h>
#include<sys/shm.h>
#include<string.h>
int main(){

    int shmid = 0;
    int shmsize = 1024;
    int key = 1234;
    int choice = 0;
    char Message[512]={"\0"};
    int iCnt = 0;

    char *ptr  = NULL;

    shmid = shmget(key,shmsize,0666);

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL){
        printf("Shared Memory attached Successfully\n");
    }


    do{

        printf("1.Send Message\n2.Read Message\n3.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);

        switch(choice){

            case 1: printf("Enter Message:");
                    scanf(" %[^\n]s",Message);
                    strcpy(ptr,Message);
                    break;

            case 2: strcpy(Message,ptr);
                    printf("Message From Client:%s\n",Message);
                    break;

            case 3: strcpy(Message,"I am going off, See you Later!!");
                    printf("See you Later!!");
                    break;               
        }
        
    
    }while(choice !=3);

    return 0;
}