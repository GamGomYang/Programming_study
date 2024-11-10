#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>

#include<sys/stat.h>
#include<string.h>
#include<unistd.h>


int main(){

    int pd, n;
    char msg[] = "hello FIFO";

    printf("server =============\n");
    if(mkfifo("./HAN-FIFO",0666)==-1){
        perror("mkfifo");
        exit(1);}


    if((pd = open("./HAN-FIFO",O_WRONLY)) ==-1){
        perror("open");
        exit(1);

    }


    printf("TO client : %s\n" msg);

    n = write(pd,msg,strlen(msg)+1);

    if(n == -1){
        perror("write");
        exit(1);

    }

    close(pd);}


