#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t wrt; pthread_mutex_t m; int readcnt=0,data=0;
void* writer(void* a){
	int i;
    for(i=0;i<2;i++){
        sem_wait(&wrt); data++; printf("Writer %ld wrote %d\n",(long)a,data);
        sem_post(&wrt); sleep(1);
    } return NULL;
}
void* reader(void* a){
	int i;
    for(i=0;i<2;i++){
        pthread_mutex_lock(&m); readcnt++; if(readcnt==1) sem_wait(&wrt);
        pthread_mutex_unlock(&m);
        printf("Reader %ld read %d\n",(long)a,data);
        pthread_mutex_lock(&m); readcnt--; if(readcnt==0) sem_post(&wrt);
        pthread_mutex_unlock(&m); sleep(1);
    } return NULL;
}
int main(){
    pthread_t r1,r2,w1;
    sem_init(&wrt,0,1); pthread_mutex_init(&m,NULL);
    pthread_create(&r1,NULL,reader,(void*)1);
    pthread_create(&r2,NULL,reader,(void*)2);
    pthread_create(&w1,NULL,writer,(void*)1);
    pthread_join(r1,NULL); pthread_join(r2,NULL); pthread_join(w1,NULL);
    return 0;
}
