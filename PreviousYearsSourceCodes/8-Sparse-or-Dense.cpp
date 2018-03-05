#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int graph[MAX + 1][MAX + 1];

bool checkSparseOrDense(int vertices); /// returns true if Sparse, false if Dense

int main()
{
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int v, e, i, j, a, b;

    /// number of vertices
    scanf("%d", &v);
    /// number of edges
    scanf("%d", &e);
    /// input terminal of edges
    for (i = 1; i <= e; i++) {
        scanf("%d%d", &a, &b);
        graph[a][b] = 1;
    }
    /// show the adjacency matrix
    printf("Adjacency Matrix\n");
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    if (checkSparseOrDense(v)) {
        printf("The graph is Sparse.\n");
    }
    else {
        printf("The graph is Dense.\n");
    }

    return 0;
}

bool checkSparseOrDense(int vertices)
{
    int i, j, totalEdges, totalPossibleEdges;
    double edgeRate;

    totalEdges = 0;
    totalPossibleEdges = vertices * (vertices - 1);

    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            if (graph[i][j] == 1) {
                totalEdges++;
            }
        }
    }

    edgeRate = (totalEdges * 100.0) / totalPossibleEdges;

    if (edgeRate > 80.0) {
        return false;
    }

    return true;
}

