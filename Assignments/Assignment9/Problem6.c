#include<stdio.h>
#include<unistd.h>
#include<sys/resource.h>

extern char* environ;

int main(){

    char **env = environ;
    printf("Environment of Current Process:\n");
    for(;*env!= NULL;env++){
        printf("%s\n",*env);
    }
    return 0;
}