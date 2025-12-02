#include <stdio.h>
int main(){
    int n,i; scanf("%d",&n);
    int bt[n],pr[n],rt[n];
    for(i=0;i<n;i++){scanf("%d %d",&bt[i],&pr[i]); rt[i]=bt[i];}
    int t=0,completed=0;
    double aw=0,at=0;
    int last=-1;
    while(completed<n){
        int idx=-1, high=-100000;
        for(i=0;i<n;i++) if(rt[i]>0 && pr[i]>high){ high=pr[i]; idx=i;}
        if(idx==-1){t++; continue;}
        rt[idx]--; t++;
        if(rt[idx]==0){completed++; int tat=t; int wt=tat-bt[idx]; aw+=wt; at+=tat; printf("P%d BT=%d PR=%d WT=%d TAT=%d\n",idx+1,bt[idx],pr[idx],wt,tat);}
    }
    printf("Average WT=%.2f Average TAT=%.2f\n",aw/n,at/n);
    return 0;
}
