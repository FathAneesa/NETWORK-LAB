#include<stdio.h>
#include<stdlib.h>

void main() {
    int u, v, n, i, j, ne = 1;
    int visited[10] = {0}, min, mincost = 0, cost[10][10];

    printf("\nEnter the number of nodes: ");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0) {
                cost[i][j] = 999;  // Treat 0 as no edge for non-diagonal elements
            }
        }
    }

    visited[0] = 1;  // Start from the first node (index 0)
    printf("\n");

    while(ne < n) {  // Loop to find the MST (until we find n-1 edges)
        min = 999;
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                // If the edge is less than the current minimum and one node is visited
                // and the other node is not visited yet
                if(cost[i][j] < min && visited[i] != 0 && visited[j] == 0) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Output the edge and its cost
        printf("\nEdge %d: (%d %d) cost: %d", ne++, u, v, min);
        mincost += min;  // Add the minimum cost of the edge to the total cost

        visited[v] = 1;  // Mark node v as visited
        cost[u][v] = cost[v][u] = 999;  // Set the edge cost to 999 to avoid revisiting
    }

    printf("\nMinimum cost = %d", mincost);
}

