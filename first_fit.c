#include <stdio.h>

int main() {
    int blocks[10], processes[10];
    int m, n, i, j;
    int allocation[10];

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each block:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blocks[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processes[i]);

    for(i = 0; i < n; i++)
        allocation[i] = -1;

    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i+1, processes[i]);
        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}
