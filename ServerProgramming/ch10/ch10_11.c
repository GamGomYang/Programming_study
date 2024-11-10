#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>



 #define MAX_THREAD 20

 pthread_mutex_t m_lock;

 void *t_func(void *data) {
 int *count = (int *)data;
 int i;
 pthread_t thread_id = pthread_self();

 for (i=0; i<10000; i++) {
 pthread_mutex_lock(&m_lock);
 *count = *count+1;
 pthread_mutex_unlock(&m_lock); }
 
 }

int main(int argc , char **argv){
    pthrea_t thread_id[MAX_TRHEAD];
    int i=0;
    int count=0;

    if(pthread_mutex_init(&m_lock,NULL)!=0){
        perror("Mutex init failure");
    }
    for(int i=0; i<MAX_TRHEAD;i++){
        pthread_create(&thread_id[i],NULL,t_func,(void *)&count);
    }

    for(int i=0; i<MAX_THREAD;i++){
        pthread_join(trhead_id[i],NULL);
    }

    pthread_mutex_destroy(&m_lock);
    printf("Main Thread: %d\n",count);


    return 0;}
