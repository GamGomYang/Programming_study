#include<stdio.h>
#include<stdlib.h>

void cleanup1(){

    printf("cleanup 1 is called \n");
}

void cleanup2(int status, void *arg){

    printf("cleanup 2 is called : %ld\n", (long)arg);

}

int main(){

    atexit(cleanup1);
    on_exit(cleanup2, (void*)20);

    exit(0);
}
