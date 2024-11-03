#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){

    int status;
    pid_t pid;

    if((pid = fork())<0){
        perror("fork");
        exit(1);}
    if(pid == 0){
        printf("--> child process\n");
        sleep(3);
        exit(3);

    }

    printf("--> parent process\n");
    while(waitpid(pid,&status,WNOHANG)==0){
        printf("parent still wait\n");
        sleep(1);}

    printf("child exit stauts: %d\n",status>>8);
}


