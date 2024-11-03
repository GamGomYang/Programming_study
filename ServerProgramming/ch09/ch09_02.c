#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

    pid_t pid;

    switch(pid = fork()){

        case -1 : 
            perror("fork");
            exit(1);
            break;

        case 0:
            printf("child process - my pid: %d my parent's pid : %d\n",(int)getpid(), (int)getpid());
            break;

        default: 
            printf("parent process - my PID :%d my parent's pid :%d , my childs pid : %d\n", (int)getpid(), (int)getppid(),(int)pid);
            break;}

    printf("end of fork \n");\
}
