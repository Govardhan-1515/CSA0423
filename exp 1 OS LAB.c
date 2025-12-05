#include <stdio.h>
#include <unistd.h>
int main(){
    pid_t pid=fork();
    if(pid==0){
        printf("child: pid=%d ppid=%d\n",getpid(),getppid());
    } else {
        printf("parent: pid=%d ppid=%d childpid=%d\n",getpid(),getppid(),pid);
    }
    return 0;
}
