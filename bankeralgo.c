#include <stdio.h>
int main()
{

    int n=5;
    int m=3;
    int i, j, k;
    int need[n][m];
    int alloc[5][3] = {{0, 1, 0},{2, 0, 0},{3, 0, 2},{2, 1, 1},{0, 0, 2}};

    int max[5][3] = {{7, 5, 3},{3, 2, 2},{9, 0, 2},{2, 2, 2},{4, 3, 3}};

    int avail[3] = {3, 3, 2};

    int finished[n], ans[n], index = 0;

    for (k = 0; k < n; k++)
    {
        finished[k] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }

    int y = 0;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (finished[i] == 0)
            {

                int flag = 0;
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > avail[j])
                    {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0)
                {
                    ans[index++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    finished[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    for (int i = 0; i < n; i++)
    {
        if (finished[i] == 0)
        {
            flag = 0;
            printf("Not safe sequence");
            break;
        }
    }

    if (flag == 1)
    {
        printf("Safe Sequence\n");
        for (i = 0; i < n ; i++)
            printf(" P%d ", ans[i]);
    }

    return (0);
}
