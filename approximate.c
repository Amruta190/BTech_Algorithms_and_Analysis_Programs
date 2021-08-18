#include <stdio.h>
#include <stdlib.h>
#define V 4
int final_ans[V + 1];
int z = 0;
int visited_nodes[V];

int minimum_key(int key[], int mstSet[])
{
    int min = 999, min_index;
    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}
int **MST(int parent[], int graph[V][V])
{
    int **v;
    v = malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
        v[i] = malloc(sizeof(int *) * 2);
    for (int i = 1; i < V; i++)
    {
        v[i - 1][0] = parent[i];
        v[i - 1][1] = i;
    }
    return v;
}
int **primMST(int graph[V][V])
{
    int parent[V];
    int key[V];
    int mstSet[V];
    for (int i = 0; i < V; i++)
    {
        key[i] = 999;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minimum_key(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    int **v;
    v = malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
        v[i] = malloc(sizeof(int *) * 2);
    v = MST(parent, graph);
    return v;
}
void DFS(int **edges_list, int num_nodes, int starting_vertex, int visited_nodes[V])
{
    final_ans[z++] = starting_vertex;
    visited_nodes[starting_vertex] = 1;
    for (int i = 0; i < num_nodes; i++)
    {
        if (i == starting_vertex)
            continue;
        if (edges_list[starting_vertex][i] == 1)
        {
            if (visited_nodes[i])
                continue;
            DFS(edges_list, num_nodes, i, visited_nodes);
        }
    }
}
int main()
{
    // int graph[V][V] = {{0, 10, 18, 40, 20},
    //                    {10, 0, 35, 15, 12},
    //                    {18, 35, 0, 25, 25},
    //                    {40, 15, 25, 0, 30},
    //                    {20, 13, 25, 30, 0}};

    int graph[V][V] = {{0, 10, 15, 20},
                           {10, 0, 35, 25},
                           {15, 35, 0, 30},
                           {20, 25, 30, 0}};
    int **v;
    v = malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
        v[i] = malloc(sizeof(int *) * 2);
    // getting the output as MST
    v = primMST(graph);
    int **edges_list;
    edges_list = malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
        edges_list[i] = malloc(sizeof(int *) * V);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            edges_list[i][j] = 0;
        }
    }
    for (int i = 0; i < V-1; i++)
    {
        int first_node = v[i][0];
        int second_node = v[i][1];
        edges_list[first_node][second_node] = 1;
        edges_list[second_node][first_node] = 1;
    }
    for (int i = 0; i < V; i++)
    {
        int visited_node;
        visited_nodes[i] = 0;
    }
    DFS(edges_list, V, 0, visited_nodes);
    final_ans[z++] = final_ans[0];
    printf("Path : ");
    for (int i = 0; i < z-1; i++)
        printf("%d-", final_ans[i]);
    printf("%d", final_ans[z-1]);
    int min_cost=0;
    for(int i=1;i<z;i++)
        min_cost+=graph[final_ans[i-1]][final_ans[i]];
    printf("\nMinimum cost = %d",min_cost);
    return 0;
}