#include <stdio.h>

#define V 5
#define INF 9999

int findMin(int dist[], int visited[]) {
    int min = INF, min_index = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printPath(int parent[], int j) {
    if (parent[j] == -1) {
        printf("%d ", j);
        return;
    }
    printPath(parent, parent[j]);
    printf("%d ", j);
}

void dijkstra(int graph[V][V], int source) {
    int dist[V], visited[V], parent[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;   
    }
    dist[source] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = findMin(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\tPath\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\t\t", i, dist[i]);
        printPath(parent, i);
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };
    dijkstra(graph, 0);
    return 0;
}