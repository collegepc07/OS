#include <stdio.h>
#include <vector>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    std::vector<int> bt(n), at(n), completed(n), wt(n), tat(n);
    for(int i = 0; i < n; i++) {
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        completed[i] = 0;
        wt[i] = 0;
        tat[i] = 0;
    }
    int t = 0, completed_count = 0;
    while(completed_count < n) {
        int idx = -1;
        float max_rr = -1;
        for(int i = 0; i < n; i++) {
            if(at[i] <= t && !completed[i]) {
                float rr = (float)(t - at[i] + bt[i]) / bt[i];
                if(rr > max_rr) {
                    max_rr = rr;
                    idx = i;
                }
            }
        }
        if(idx == -1) {
            t++;
            continue;
        }
        wt[idx] = t - at[idx];
        t += bt[idx];
        tat[idx] = t - at[idx];
        completed[idx] = 1;
        completed_count++;
    }
    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    return 0;
}