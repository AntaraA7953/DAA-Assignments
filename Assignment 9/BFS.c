#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency matrix
int visited[MAX];  // Visited array
int queue[MAX];    // Queue for BFS
int front = 0, rear = -1;
int bfsPath[MAX];  // Stores BFS traversal path
int pathIndex = 0;

// Enqueue function
void enqueue(int vertex) {
    queue[++rear] = vertex;
}

// Dequeue function
int dequeue() {
    return queue[front++];
}

// Check if queue is empty
int isQueueEmpty() {
    return front > rear;
}

// BFS algorithm
void bfs(int startVertex, int n) {
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (!isQueueEmpty()) {
        int current = dequeue();
        bfsPath[pathIndex++] = current;

        for (int i = 0; i < n; i++) {
            if (adj[current][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

// Function to display BFS path
void displayPath() {
    printf("BFS Traversal Path: ");
    for (int i = 0; i < pathIndex; i++) {
        printf("%d ", bfsPath[i]);
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

    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(startVertex, n);
    displayPath();

    return 0;
}
