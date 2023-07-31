#include<unistd.h>
#include<sys/resource.h>
#include<stdio.h>
#include<stdlib.h>

extern char **environ;

int main(){

    char **env = environ;
    printf("Environment of running process:\n");
    for(;*env!=NULL;env++){
        printf("%s\n",*env);
    }
    return 0;
}