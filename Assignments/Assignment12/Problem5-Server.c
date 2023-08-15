#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/msg.h>
#include<stdlib.h>
#define BUFSIZE 1024
#define MAX_TEXT 512
struct Message{
    long int msg_type;
    char my_msg[MAX_TEXT];
};

int main(){

    int running = 1;
    struct Message myMessage;
    int msgId = 0;
    char buffer[BUFSIZE];

    msgId = msgget((key_t)1234,0666|IPC_CREAT);
    if(msgId == -1){
        printf("Failed to Create\n");
        exit(EXIT_FAILURE);
    }

    while(running){

        printf("Enter Some Data:");
        scanf(" %[^\n]s",buffer);
        myMessage.msg_type = 1;

        strcpy(myMessage.my_msg,buffer);
        if(msgsnd(msgId,(void *)&myMessage,MAX_TEXT,0)==-1){

            fprintf(stderr,"msgsnd failder\n");
            exit(EXIT_FAILURE);
        }

        if(strncmp(buffer,"end",3) == 0){
            running = 0;
        }

    }

    exit(EXIT_SUCCESS);
}