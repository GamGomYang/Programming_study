#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(){
    pid_t pid;

    switch(pid = fork()){
        case -1 :
              perror("fork error");
              return 1;
              break;
        case 0:
            printf("--> Child Process\n");
            execlp("sleep", "sleep","5",NULL);
            perror("sleep error");
            exit(1);
            break;

        default:
             printf("--> Parent process\n");
            int status;
            while( waitpid(pid, &status,WNOHANG)==0){
                sleep(1);

            }
            printf("Child Exit status : %d\n", status);
            return 0;
            
              
    }


}
