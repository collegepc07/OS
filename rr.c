#include <stdio.h>
int main() {
    int n, quantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], rt[n], wt[n], tat[n];
    for(int i = 0; i < n; i++) {
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &quantum);
    int t = 0;
    while(1) {
        int done = 1;
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = 0;
                if(rt[i] > quantum) {
                    t += quantum;
                    rt[i] -= quantum;
                } else {
                    t += rt[i];
                    wt[i] = t - bt[i];
                    rt[i] = 0;
                }
            }
        }
        if(done == 1) break;
    }
    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, bt[i], wt[i], tat[i]);
    return 0;
}