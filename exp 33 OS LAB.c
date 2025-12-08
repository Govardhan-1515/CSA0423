#include <stdio.h>
int main(){
    int pages[]={7,0,1,2,0,3,0,4,2,3,0,3,2},n=13,f=4;
    int frame[f],i,j; for(i=0;i<f;i++) frame[i]=-1;
    int cnt=0;
    for(i=0;i<n;i++){
        int hit=0;
        for(j=0;j<f;j++) if(frame[j]==pages[i]) hit=1;
        if(!hit){
            int pos=-1,farthest=-1;
            for(j=0;j<f;j++){
                int k; for(k=i+1;k<n;k++) if(frame[j]==pages[k]) break;
                if(k==n){pos=j; break;}
                if(k>farthest){farthest=k; pos=j;}
            }
            frame[pos]=pages[i]; cnt++;
        }
        printf("Page %d: ",pages[i]);
        for(j=0;j<f;j++) printf("%d ",frame[j]);
        printf("\n");
    }
    printf("Faults=%d\n",cnt);
    return 0;
}
