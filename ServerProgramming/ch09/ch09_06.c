#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    pid_t pid;

    switch(pid = fork()){
        case -1:
            perror("fork");
            exit(1);
            break;

        case 0:
            printf("-->child process\n");
            if(execlp("ls","ls","-a",(char*)NULL) == -1){
                    perror("execlp");
                    exit(1);}

            exit(0);
            break;

        default:
            printf("--> parent process - My Pid : %d\n", (int)getpid());
            break;

    }
}
