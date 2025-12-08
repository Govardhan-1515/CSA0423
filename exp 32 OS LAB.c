#include <stdio.h>
int main(){
    int pages[]={1,2,3,4,1,2,5,1,2,3,4,5},n=12,f=3;
    int frame[f],used[f],cnt=0,t=0;
    int i,j,k;
    for(i=0;i<f;i++){frame[i]=-1; used[i]=0;}
    for(i=0;i<n;i++){
        int hit=0;
        for(j=0;j<f;j++) if(frame[j]==pages[i]){hit=1; used[j]=t;}
        if(!hit){
            int pos=0;
            for(j=1;j<f;j++) if(used[j]<used[pos]) pos=j;
            frame[pos]=pages[i]; used[pos]=t; cnt++;
        }
        t++;
        printf("Page %d: ",pages[i]);
        for(k=0;k<f;k++) printf("%d ",frame[k]);
        printf("\n");
    }
    printf("Faults=%d\n",cnt);
    return 0;
}
