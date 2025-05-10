#include <stdio.h>
#define MAX 100
#define INF 9999

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

int dist[MAX];
int path[MAX];
int V, E;
struct Edge edgeList[MAX];

// Function to create the graph from user input
void createGraph() {
    int i;
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges in the format: source destination weight\n");
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &edgeList[i].src, &edgeList[i].dest, &edgeList[i].weight);
        edgeList[i].src--;   // Convert to 0-based indexing
        edgeList[i].dest--;
    }
}

// Bellman-Ford algorithm to find shortest paths
int bellmanFord(int source) {
    int i, j;

    // Step 1: Initialize distances
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        path[i] = -1;
    }
    dist[source] = 0;

    // Step 2: Relax edges V-1 times
    for (i = 1; i <= V - 1; i++) {
        for (j = 0; j < E; j++) {
            int u = edgeList[j].src;
            int v = edgeList[j].dest;
            int w = edgeList[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                path[v] = u;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (j = 0; j < E; j++) {
        int u = edgeList[j].src;
        int v = edgeList[j].dest;
        int w = edgeList[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle.\n");
            return 0;
        }
    }

    return 1;
}

// Function to display shortest paths from source
void displayPaths(int source) {
    int i;
    printf("\nShortest paths from vertex %d:\n", source + 1);
    for (i = 0; i < V; i++) {
        if (i != source) {
            printf("To vertex %d: Cost = %d, Path = ", i + 1, dist[i]);
            int stack[MAX], top = -1;
            int temp = i;
            while (temp != -1) {
                stack[++top] = temp;
                temp = path[temp];
            }
            while (top >= 0) {
                printf("%d", stack[top--] + 1);
                if (top >= 0)
                    printf(" -> ");
            }
            printf("\n");
        }
    }
}

int main() {
    int source;
    createGraph();

    printf("Enter the source vertex (1 to %d): ", V);
    scanf("%d", &source);
    source--;

    if (bellmanFord(source)) {
        displayPaths(source);
    }

    return 0;
}
/*
Sample Input:
Enter number of vertices: 5
Enter number of edges: 8
Enter edges in the format: source destination weight
1 2 6
1 3 7
2 3 8
2 4 5
2 5 -4
3 4 -3
4 2 -2
5 4 9
Enter the source vertex (1 to 5): 1

Sample Output:
Shortest paths from vertex 1:
To vertex 2: Cost = 2, Path = 1 -> 3 -> 4 -> 2
To vertex 3: Cost = 7, Path = 1 -> 3
To vertex 4: Cost = 4, Path = 1 -> 3 -> 4
To vertex 5: Cost = -2, Path = 1 -> 3 -> 4 -> 2 -> 5
*/