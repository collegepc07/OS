// C program for Banker's Algorithm with Manual Input
#include <stdio.h>

int main()
{
    int n, r, i, j, k;

    // Input number of processes and resources
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &r);

    int alloc[n][r], max[n][r], need[n][r];
    int avail[r];
    int f[n], ans[n], ind = 0;

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process P%d:\n", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input Max Matrix
    printf("\nEnter Max Matrix:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process P%d:\n", i);
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &avail[j]);
    }

    // Initialize finish array
    for (i = 0; i < n; i++)
        f[i] = 0;

    // Calculate Need Matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Banker's Algorithm
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (f[i] == 0)
            {
                int flag = 0;
                for (j = 0; j < r; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[ind++] = i;
                    for (j = 0; j < r; j++)
                        avail[j] += alloc[i][j];
                    f[i] = 1;
                }
            }
        }
    }

    // Display Safe Sequence
    printf("\nSAFE Sequence is:\n");
    for (i = 0; i < n - 1; i++)
        printf("P%d -> ", ans[i]);
    printf("P%d\n", ans[n - 1]);

    return 0;
}
