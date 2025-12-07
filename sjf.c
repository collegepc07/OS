#include <stdio.h>

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);
    int bt[n], p[n], wt[n], tat[n];
    for(int i = 0; i < n; i++) {
        printf("Enter Burst Time For P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    // Sort By Burst Time
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(bt[j] < bt[i]) {
                int temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                temp = p[i]; p[i] = p[j]; p[j] = temp;
            }
        }
    }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i-1] + bt[i-1];
    for(int i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    return 0;
}
