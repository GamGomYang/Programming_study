#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/wait.h>

int main(){

    int status;
    pid_t pid;

    switch(pid = fork()){
      case -1:
          perror("folk");
          exit(1);
          break;

      case 0:
          printf("--> child process");
          exit(2);
          break;

      default :
           while(wait(&status)!=pid)
               continue;
           printf("-->parent process\n");
           printf("status : %d %x \n",status,status);
           printf("child process Exit Status: %d\n",status >> 8);
           break;
    }}
