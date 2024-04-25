#include <stdio.h>
#include <stdlib.h>

int count = 0;
struct Edge
{
    int src;
    int dest;
    int wt;
};

struct Graph
{
    int v;
    int e;
    struct Edge edges[];
};

void makegraph(struct Graph **graph, int v, int e)
{
    *graph = malloc(sizeof(struct Graph) + e * sizeof(struct Edge));
    (*graph)->v = 9;
    (*graph)->e = 14;
}

void merge(struct Edge edges[], int l, int m, int u)
{
    int n1 = m - l + 1;
    int n2 = u - m;

    struct Edge b[n1], c[n2];
    for (int i = 0; i < n1; i++)
        b[i] = edges[l + i];
    for (int j = 0; j < n2; j++)
        c[j] = edges[m + 1 + j];
    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (b[i].wt <= c[j].wt)
        {
            edges[k] = b[i];
            i++;
        }
        else
        {
            edges[k] = c[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        edges[k] = b[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        edges[k] = c[j];
        j++;
        k++;
    }
}
void mergeSort(struct Edge edges[], int l, int h)
{
    if (l < h)
    {
        int m = (l + h) / 2;
        mergeSort(edges, 0, m);
        mergeSort(edges, m + 1, h);
        merge(edges, l, m, h);
    }
}

void insert(struct Edge edge[], int s, int d, int wt)
{
    struct Edge e;
    e.src = s;
    e.dest = d;
    e.wt = wt;
    edge[count] = e;
    count++;
}
int find(int par[], int i)
{
    if (par[i] == i)
    {
        return i;
    }
    else
    {
        find(par, par[i]);
    }
}
void unionM(int par[], int i, int j)
{
    int x = find(par, i);
    int y = find(par, j);
    par[x] = y;
}
void kruskal(struct Graph *graph)
{
    int par[graph->v];
    for (int i = 0; i < graph->v; i++)
    {
        par[i] = i;
    }
    int weight = 0;
    for (int k = 0; k < graph->e; k++)
    {
        int i = graph->edges[k].src;
        int j = graph->edges[k].dest;

        if (find(par, j) != find(par, i))
        {
            weight += graph->edges[k].wt;
            unionM(par, i, j);
        }
    }
    printf("Weight of minimal spanning tree: %d", weight);
}
int main()
{
    struct Graph *graph = NULL;
    makegraph(&graph, 9, 14);

    insert(graph->edges, 0, 1, 4);
    insert(graph->edges, 0, 7, 8);
    insert(graph->edges, 1, 7, 11);
    insert(graph->edges, 1, 2, 8);
    insert(graph->edges, 7, 6, 1);
    insert(graph->edges, 7, 8, 7);
    insert(graph->edges, 2, 8, 2);
    insert(graph->edges, 8, 6, 6);
    insert(graph->edges, 4, 5, 4);
    insert(graph->edges, 6, 5, 2);
    insert(graph->edges, 2, 3, 7);
    insert(graph->edges, 3, 5, 14);
    insert(graph->edges, 3, 4, 9);
    insert(graph->edges, 4, 5, 10);
    mergeSort(graph->edges, 0, graph->e);
    kruskal(graph);
    return 0;
}