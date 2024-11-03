#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid;

    switch(pid = fork()){
        case -1 :
           perror("fork error");
           return 1;
           break;
        case 0 :
           system("pwd");
           break;

        default:
           system("ls");
           break;

        
    }
    printf("End of fork\n");

    return 0;

}
