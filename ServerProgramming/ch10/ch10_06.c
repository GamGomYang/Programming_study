#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<sys/stat.h>


int main(){
    if(mknod("HAN-FIFO",S_IFIFO | 0644, 0 ) == -1){
        perror("mknod");
        exit(1);
    }


    if(mkfifo("BIT-FIFO",0644) == -1){
        perror("mkfifo");
        exit(1);
    }
}
