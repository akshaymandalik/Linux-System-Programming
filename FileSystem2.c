#include<stdio.h>
int main(int argc, char * argv[]){
 if(argc == 1){
	printf("Please Enter Your First Name as your Command Line Argument\n");
 return -1;
}
else{
 
 printf("%d\n",argc); 
 printf("Enter to AMGroups:%s\n",argv[1]);
 return 0;
}
}
