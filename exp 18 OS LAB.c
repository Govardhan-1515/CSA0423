#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int buf[5],in=0,out=0;
sem_t full,empty,mutex;
void* prod(void* a){
	int i;
    for(i=1;i<=5;i++){
        sem_wait(&empty); sem_wait(&mutex);
        buf[in]=i; in=(in+1)%5; printf("Produced %d\n",i);
        sem_post(&mutex); sem_post(&full); sleep(1);
    } return NULL;
}
void* cons(void* a){
	int i;
    for(i=1;i<=5;i++){
        sem_wait(&full); sem_wait(&mutex);
        int v=buf[out]; out=(out+1)%5; printf("Consumed %d\n",v);
        sem_post(&mutex); sem_post(&empty); sleep(1);
    } return NULL;
}
int main(){
    pthread_t p,c;
    sem_init(&full,0,0); sem_init(&empty,0,5); sem_init(&mutex,0,1);
    pthread_create(&p,NULL,prod,NULL); pthread_create(&c,NULL,cons,NULL);
    pthread_join(p,NULL); pthread_join(c,NULL);
    return 0;
}
