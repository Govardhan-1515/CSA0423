#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>  // ADD THIS
#include <unistd.h>
#include <string.h>

int main(){
    key_t k=IPC_PRIVATE;
    int id=shmget(k,1024,0666|IPC_CREAT);
    char *p=(char*)shmat(id,NULL,0);
    pid_t pid=fork();
    if(pid==0){
        sleep(1);
        printf("child read: %s\n",p);
        shmdt(p);
    } else {
        strcpy(p,"hello from parent");
        wait(NULL);
        shmdt(p);
        shmctl(id,IPC_RMID,NULL);
    }
    return 0;
}
