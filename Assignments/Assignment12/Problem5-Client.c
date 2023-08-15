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
    long int msgToRecieve = 0;
   

    msgId = msgget((key_t)1234,0666);
    if(msgId == -1){
        printf("Failed to Create\n");
        exit(EXIT_FAILURE);
    }

    while(running){

       
        msgrcv(msgId,(void *)&myMessage,BUFSIZE,msgToRecieve,0);

        printf("Message from Server:%s\n",myMessage.my_msg);

        if(strncmp(myMessage.my_msg,"end",3)==0){
            running = 0;
        }

    }

    exit(EXIT_SUCCESS);
}