#include <stdio.h>
#define MAX 20
#define INF 9999

int cost[MAX][MAX];     // Cost matrix
int dist[MAX];          // Distance from source to each vertex
int visited[MAX];       // Visited vertices
int path[MAX];          // Path matrix to reconstruct shortest path
int n;                  // Number of vertices

// Function to find the vertex with minimum distance not yet visited
int minDistance() {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++)
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    return min_index;
}

// Function to implement Dijkstra's algorithm from given source
void dijkstra(int src) {
    int i, count, u, v;

    // Initialize all distances and visited
    for (i = 0; i < n; i++) {
        dist[i] = cost[src][i];
        visited[i] = 0;
        if (cost[src][i] != INF && i != src)
            path[i] = src;
        else
            path[i] = -1;
    }

    dist[src] = 0;
    visited[src] = 1;

    for (count = 1; count < n - 1; count++) {
        u = minDistance();
        visited[u] = 1;

        for (v = 0; v < n; v++) {
            if (!visited[v] && cost[u][v] != INF &&
                dist[u] + cost[u][v] < dist[v]) {
                dist[v] = dist[u] + cost[u][v];
                path[v] = u;
            }
        }
    }
}

// Function to display paths from source
void displayPaths(int src) {
    int i, j;

    printf("\nShortest paths from vertex %d:\n", src + 1);
    for (i = 0; i < n; i++) {
        if (i != src) {
            printf("To vertex %d: Cost = %d, Path = %d", i + 1, dist[i], src + 1);
            int temp = i;
            while (path[temp] != src && path[temp] != -1) {
                printf(" -> %d", path[temp] + 1);
                temp = path[temp];
            }
            printf(" -> %d\n", i + 1);
        }
    }
}

int main() {
    int i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter the cost matrix (use 9999 for no direct edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter the source vertex (1 to %d): ", n);
    scanf("%d", &source);

    dijkstra(source - 1);
    displayPaths(source - 1);

    return 0;
}
/*
Sample Input:
Enter number of vertices: 4
Enter the cost matrix:
0 1 9999 3
1 0 1 9999
9999 1 0 1
3 9999 1 0
Enter the source vertex (1 to 4): 1

 Output:


Shortest paths from vertex 1:
To vertex 2: Cost = 1, Path = 1 -> 2
To vertex 3: Cost = 2, Path = 1 -> 2 -> 3
To vertex 4: Cost = 3, Path = 1 -> 4

*/
