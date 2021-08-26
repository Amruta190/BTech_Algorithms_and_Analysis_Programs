#include <stdio.h>
#define V 5
int vertex[V];
int min(int a, int b)
{
    return a < b ? a : b;
}
int next_permutation(int size)
{
    int scratch;
    int lastpermutation = 0;
    int i, j, k, l;
    while (!lastpermutation)
    {
        j = -1;
        for (i = 0; i < size; i++)
        {
            if (vertex[i + 1] > vertex[i])
            {
                j = i;
            }
        }
        if (j == -1)
        {
            lastpermutation = 1;
        }
        if (!lastpermutation)
        {
            for (i = j + 1; i < size; i++)
            {
                if (vertex[i] > vertex[j])
                {
                    l = i;
                }
            }
            scratch = vertex[j];
            vertex[j] = vertex[l];
            vertex[l] = scratch;
            k = (size - 1 - j) / 2;
            for (i = 0; i < k; i++)
            {
                scratch = vertex[j + 1 + i];
                vertex[j + 1 + i] = vertex[size - 1 - i];
                vertex[size - 1 - i] = scratch;
            }
            return 1;
        }
    }
    return 0;
}
int travellingSalesmanProblem(int graph[][V], int s)
{
    int j = 0;
    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;
    for (int i = 0; i < V; i++)
    {
        if (i != s)
            vertex[j++] = i;
    }
    int min_path = 999;
    do
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < j; i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        if (min_path > current_pathweight)
        {
            for (int i = 0; i < j; i++)
                visited[i] = vertex[i];
        }
        min_path = min(min_path, current_pathweight);

    } while (next_permutation(j));
    printf("Path : %d-", s);
    for (int i = 0; i < j; i++)
        printf("%d-", visited[i]);
    printf("%d\n", s);
    return min_path;
}
int main()
{
    // int graph[][V] = { { 0, 10, 15, 20 },
    // 				{ 10, 0, 35, 25 },
    // 				{ 15, 35, 0, 30 },
    // 				{ 20, 25, 30, 0 } };
    int graph[V][V] = {{0, 10, 18, 40, 20},
                       {10, 0, 35, 15, 12},
                       {18, 35, 0, 25, 25},
                       {40, 15, 25, 0, 30},
                       {20, 13, 25, 30, 0}};
    int s = 0;
    int ans = travellingSalesmanProblem(graph, s);
    printf("%d", ans);
    return 0;
}