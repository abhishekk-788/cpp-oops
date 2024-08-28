#include <stdio.h>
#include <stdlib.h>

#define MAX 9

int min_vertice_not_included(int distance[], int included[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < MAX; v++)
        if (included[v] == 0 && distance[v] < min)
            min = distance[v], min_index = v;

    return min_index;
}

void print_path(int parent[], int vertex)
{
    if (parent[vertex] == -1)
        return;

    print_path(parent, parent[vertex]);

    printf("%d -> ", vertex);
}

int print_solution(int distance[], int parent[], int start)
{
    for (int v = 1; v < MAX; v++)
    {
        if (distance[v] > 9)
            printf("\n%d -> %d \t\t   %d\t\t%d -> ", start, v, distance[v], start);
        else
            printf("\n%d -> %d \t\t    %d\t\t%d -> ", start, v, distance[v], start);

        print_path(parent, v);

        printf("\b\b\b   ");
    }

    printf("\n");
}

void dijkstra(int graph[MAX][MAX], int start)
{
    int distance[MAX], included[MAX], parent[MAX];

    for (int i = 0; i < MAX; i++)
        distance[i] = INT_MAX, included[i] = 0, parent[i] = -1;

    distance[start] = 0;

    for (int count = 0; count < MAX - 1; count++)
    {
        int min_vertice = min_vertice_not_included(distance, included);

        included[min_vertice] = 1;

        for (int neighbor = 0; neighbor < MAX; neighbor++)
        {
            if (graph[min_vertice][neighbor] && included[neighbor] == 0 &&
                distance[min_vertice] + graph[min_vertice][neighbor] < distance[neighbor])
            {
                parent[neighbor] = min_vertice;
                distance[neighbor] = distance[min_vertice] + graph[min_vertice][neighbor];
            }
        }
    }

    print_solution(distance, parent, start);
}

void main()
{
    //                      0, 1, 2, 3, 4, 5, 6, 7, 8
    int graph[MAX][MAX] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                           {4, 0, 8, 0, 0, 0, 0, 11, 0},
                           {0, 8, 0, 7, 0, 4, 0, 0, 2},
                           {0, 0, 7, 0, 9, 14, 0, 0, 0},
                           {0, 0, 0, 9, 0, 10, 0, 0, 0},
                           {0, 0, 4, 0, 10, 0, 2, 0, 0},
                           {0, 0, 0, 14, 0, 2, 0, 1, 6},
                           {8, 11, 0, 0, 0, 0, 1, 0, 7},
                           {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    int start;
    
	printf("Starting vertex: ");
    scanf("%d", &start);

    dijkstra(graph, start);
}
