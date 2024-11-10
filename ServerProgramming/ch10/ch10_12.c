#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>


pthread_mutex_t mut;
pthread_cond_t cond;


void *f(void *data){
    printf("before wait\n");
    pthread_mutex_lock(&cond, &mut);
    printf("after wait\n");
    pthread_mutex_unlock(&mut);

    return 0;}



    int main(int argc , char *argv[]){
        int res =0;
        res = pthread_mutex_init(&mut ,NULL);
        res = pthread_cond_init(&cond,NULL);

        pthread_t pt;
        pthread_create(&pt, NULL, f ,NULL);

        sleep(2);
        pthread_cond_signal(&pt, NULL);
        pthread_mutex_destroy(&mut);
        pthread_cond_destroy(&cond);


        return 0;}


