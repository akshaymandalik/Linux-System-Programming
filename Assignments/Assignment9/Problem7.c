#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<pwd.h>
#include<stdlib.h>
int main(){
    
    const char *homedir;
    const char *logName;
    if((homedir = getenv("HOME")) == NULL){
    
        homedir = getpwuid(getuid())->pw_dir;
    }

    logName = getenv("LOGNAME");

    printf("Home Directory: %s\n",homedir);
    printf("Login Name : %s\n",logName);


    return 0;
}