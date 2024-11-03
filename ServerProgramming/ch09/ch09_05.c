#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(){

    char *argv[3];

    printf("before exec function\n");

    argv[0] = "is";
    argv[2] = "-a";
    argv[2] = NULL;
    if(execv("/usr/bin/ls", argv) == -1){
        perror("execv");
        exit(1);
    }

    printf("after exec function \n");}
