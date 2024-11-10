#include<stdio.h>
#include<pthread.h>


void *threadfunc(void *vargp);

void *threadfunc(void *vargp){
    sleep(1);
    printf("hello world \n");
    return NULL;

}

int main(){
    pthread_t tid;
    pthread_create(&tid, NULL, threadfunc,NULL);
    printf("main \n");
    pthread_detach(tid);
    printf("main2\n");
    sleep(2);
    return 0;}


