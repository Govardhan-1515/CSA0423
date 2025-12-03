#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t chop[5];
void* philos(void* n){
    int id=(long)n;
    sem_wait(&chop[id]);
    sem_wait(&chop[(id+1)%5]);
    printf("Philosopher %d is eating\n",id);
    sleep(1);
    printf("Philosopher %d finished\n",id);
    sem_post(&chop[id]);
    sem_post(&chop[(id+1)%5]);
    return NULL;
}
int main(){
    pthread_t th[5];
	int i;
    for(i=0;i<5;i++) sem_init(&chop[i],0,1);
    for(i=0;i<5;i++) pthread_create(&th[i],NULL,philos,(void*)(long)i);
    for(i=0;i<5;i++) pthread_join(th[i],NULL);
    return 0;
}
