#include <stdio.h>
#include <pthread.h>
void* func(void* arg){
    printf("Hello from thread %ld\n",(long)arg);
    return NULL;
}
int main(){
    pthread_t t1,t2;
    pthread_create(&t1,NULL,func,(void*)1);
    pthread_create(&t2,NULL,func,(void*)2);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    return 0;
}
