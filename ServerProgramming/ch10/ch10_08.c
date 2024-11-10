#include<stdio.h>
#include<pthread.h>

void *threadfunc(void *vargp);

void *theradfunc(void *vargp){
   
    printf("hello world\n");
    return NULL;
  }


int main(){

    pthread_t tid;

    pthread_create(&tid, NULL, threadfunc, NULL);

    pthread_join(tid,NULL);

    printf("main2\n");
   
    return 0;}


