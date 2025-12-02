#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc,char *argv[]){
    if(argc!=3){printf("usage src dst\n");return 1;}
    int in=open(argv[1],O_RDONLY);
    int out=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0644);
    if(in<0||out<0){perror("open");return 1;}
    char buf[4096];
    ssize_t n;
    while((n=read(in,buf,sizeof(buf)))>0) write(out,buf,n);
    close(in); close(out);
    
    printf("copied\n");
    return 0;
}
