#include <stdio.h>

int main() {
    int n,i;
    scanf("%d", &n);

    int bt[n], wt[n], tat[n];

    
	for (i = 0; i < n; i++){
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];

    for (i = 0; i < n; i++)
        tat[i] = wt[i] + bt[i];

    double aw = 0, at = 0;

    for (i = 0; i < n; i++) {
        aw += wt[i];
        at += tat[i];
        printf("P%d BT=%d WT=%d TAT=%d\n", i+1, bt[i], wt[i], tat[i]);
    }

    printf("Average WT=%.2f Average TAT=%.2f\n", aw/n, at/n);
    return 0;
}
