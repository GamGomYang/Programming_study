#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(){
    int status;
    pid_t pid;
    siginfo_t infop;

    if((pid = fork())<0){
        perror("folk");
        exit(1);
    }

    if(pid == 0 ){

        printf("--> child process \n");

        while(waitid(P_PID, pid , &infop,WEXITED)!=0){
            printf("Parent still wait\n");
            

        }

        printf("child's PID %d\n",infop_si_pid);
        printf("child's UID %d\n",infop_si_uid);
        printf("child's Code %d\n", infop_si_code);
        printf("child's Status %d\n", infop_si_status);
    }



