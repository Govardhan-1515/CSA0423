#include <stdio.h>
int main(){
    int n=5; char file[5][20]={"a","b","c","d","e"};
    int start[5]={0,5,10,15,20},len[5]={5,3,2,4,6};
    int i,j;
	for(i=0;i<n;i++){
        printf("File %s blocks: ",file[i]);
        for(j=0;j<len[i];j++) printf("%d ",start[i]+j);
        printf("\n");
    }
    return 0;
}
