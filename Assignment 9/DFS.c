#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];     // Visited array
int dfsPath[MAX];     // Stores DFS traversal path
int pathIndex = 0;

// DFS algorithm (recursive)
void dfs(int vertex, int n) {
    visited[vertex] = 1;
    dfsPath[pathIndex++] = vertex;

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

// Function to display DFS path
void displayPath() {
    printf("DFS Traversal Path: ");
    for (int i = 0; i < pathIndex; i++) {
        printf("%d ", dfsPath[i]);
    }
    printf("\n");
}

int main() {
    int n, edges, u, v, startVertex;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter each edge as a pair of vertices (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // Because the graph is undirected
    }

    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    dfs(startVertex, n);
    displayPath();

    return 0;
}
