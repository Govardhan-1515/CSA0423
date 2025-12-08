#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
pthread_mutex_t m;
int cnt=0;
void* work(void* a){
	int i;
    for(i=0;i<3;i++){
        pthread_mutex_lock(&m);
        cnt++; printf("Thread %ld cnt=%d\n",(long)a,cnt);
        pthread_mutex_unlock(&m);
        sleep(1);
    } return NULL;
}
int main(){
    pthread_t t1,t2;
    pthread_mutex_init(&m,NULL);
    pthread_create(&t1,NULL,work,(void*)1);
    pthread_create(&t2,NULL,work,(void*)2);
    pthread_join(t1,NULL); pthread_join(t2,NULL);
    return 0;
}
