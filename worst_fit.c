#include <stdio.h>

int main() {
    int blocks[10], processes[10], allocation[10];
    int m, n, i, j, worst;

    printf("Enter number of blocks: ");
    scanf("%d", &m);

    printf("Enter block sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blocks[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter process sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processes[i]);

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++) {
        worst = -1;
        for(j = 0; j < m; j++) {
            if(blocks[j] >= processes[i]) {
                if(worst == -1 || blocks[j] > blocks[worst])
                    worst = j;
            }
        }
        if(worst != -1) {
            allocation[i] = worst;
            blocks[worst] -= processes[i];
        }
    }

    printf("\nProcess\tSize\tBlock\n");
    for(i = 0; i < n; i++) {
        printf("%d\t%d\t", i+1, processes[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
