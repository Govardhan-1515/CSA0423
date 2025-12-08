#include <stdio.h>
int main(){
    int n=5,m=3;
    int alloc[5][3]={{0,1,0},{2,0,0},{3,0,2},{2,1,1},{0,0,2}};
    int max[5][3]={{7,5,3},{3,2,2},{9,0,2},{2,2,2},{4,3,3}};
    int avail[3]={3,3,2},need[5][3];
    int i,j,k;
    for(i=0;i<n;i++) for(j=0;j<m;j++) need[i][j]=max[i][j]-alloc[i][j];
    int f[5]={0},ans[5],ind=0;
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(!f[i]){
                int ok=1;
                for(j=0;j<m;j++) if(need[i][j]>avail[j]) ok=0;
                if(ok){for(j=0;j<m;j++) avail[j]+=alloc[i][j]; ans[ind++]=i; f[i]=1;}
            }
        }
    }
    printf("Safe sequence: ");
    for(i=0;i<n;i++) printf("P%d ",ans[i]);
    return 0;
}
