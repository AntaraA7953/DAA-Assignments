#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int path[MAX];
int n;
int found = 0; // Flag to track if any cycle was found

// Function to print one Hamiltonian cycle
void printSolution() {
    for (int i = 0; i < n; i++)
        printf("%d -> ", path[i] + 1);
    printf("%d\n", path[0] + 1); // complete the cycle
}

// Check if the current vertex can be added to path[]
int isSafe(int v, int pos) {
    // Not adjacent to previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return 0;

    // Already included
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

// Recursive function to find all Hamiltonian cycles
void hamiltonianCycleUtil(int pos) {
    int v;

    // Base case: all vertices included
    if (pos == n) {
        // Check if last vertex connects to first
        if (graph[path[pos - 1]][path[0]] == 1) {
            printSolution();
            found = 1;
        }
        return;
    }

    // Try all vertices
    for (v = 1; v < n; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            hamiltonianCycleUtil(pos + 1);

            // Backtrack
            path[pos] = -1;
        }
    }
}

// Entry function to start the cycle search
void hamiltonianCycle() {
    int i;
    for (i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0; // Start at vertex 0

    printf("Hamiltonian cycles (if any):\n");
    hamiltonianCycleUtil(1);

    if (found == 0)
        printf("No Hamiltonian cycle found.\n");
}

int main() {
    int e, i, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Initialize graph
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            graph[i][j] = 0;

    printf("Enter edges (u v):\n");
    for (i = 0; i < e; i++) {
        scanf("%d%d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
    }

    hamiltonianCycle();

    return 0;
}
