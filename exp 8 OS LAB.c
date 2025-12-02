#include <stdio.h>
int main(){
    int n,i,qt; scanf("%d %d",&n,&qt);
    int bt[n],rt[n];
    for(i=0;i<n;i++){scanf("%d",&bt[i]); rt[i]=bt[i];}
    int t=0,done=0;
    double aw=0,at=0;
    while(done<n){
        int progress=0;
        for(i=0;i<n;i++){
            if(rt[i]>0){
                progress=1;
                if(rt[i]>qt){rt[i]-=qt; t+=qt;}
                else{t+=rt[i]; int tat=t; int wt=tat-bt[i]; rt[i]=0; done++; aw+=wt; at+=tat; printf("P%d BT=%d WT=%d TAT=%d\n",i+1,bt[i],wt,tat);}
            }
        }
        if(!progress) break;
    }
    printf("Average WT=%.2f Average TAT=%.2f\n",aw/n,at/n);
    return 0;
}
