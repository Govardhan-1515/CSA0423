#include <stdio.h>
struct block{int b,next;} disk[10];
int main(){
    int file[3]={0,3,6};
    int i,f;
    for(i=0;i<9;i++) disk[i].b=i,disk[i].next=i+1;
    disk[2].next=-1; disk[5].next=-1; disk[8].next=-1;
    for(f=0;f<3;f++){
        int cur=file[f];
        printf("File %d blocks: ",f);
        while(cur!=-1){printf("%d ",cur); cur=disk[cur].next;}
        printf("\n");
    }
    return 0;
}
