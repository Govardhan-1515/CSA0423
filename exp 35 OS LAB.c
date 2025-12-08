#include <stdio.h>
int main(){
    int n=3;
    char file[3][20]={"a","b","c"};
    int index[3][5]={{1,4,7},{2,5,8},{3,6,9}};
    int i,j;
    int len[3]={3,3,3};
    for(i=0;i<n;i++){
        printf("File %s index block -> ",file[i]);
        for(j=0;j<len[i];j++) printf("%d ",index[i][j]);
        printf("\n");
    }
    return 0;
}
