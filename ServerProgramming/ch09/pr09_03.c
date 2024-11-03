#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>


int main(){

    pid_t pid;

    switch(pid = fork()){

        case -1:
           perror("fork error");
           return 1;
           break;
        case 0:
           char *args[]={"/bin/date",NULL};
           execv(args[0], args);
           perror("execv failed");
           exit(1);
           break;
        default:
           int status;
           while(waitpid(pid, &status , WNOHANG)==0){
            sleep(1);
           }
           printf("Child Exit status : %d \n",status);

    }

    return 0;
}