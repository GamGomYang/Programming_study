#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    printf(" --> before exec function\n");

    if(execlp("ls","ls","-a",(char*)NULL) ==-1 ){

            perror("execlp");
            exit(1);}

    printf("--> After exec funtion\n");

    }
