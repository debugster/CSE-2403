#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int graph[MAX + 1][MAX + 1];
int graphT[MAX + 1][MAX + 1];

void createTranspose(int vertices);

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

    createTranspose(v);

    /// show the adjacency matrix
    printf("Transposed Matrix\n");
    for (i = 1; i <= v; i++) {
        for (j = 1; j <= v; j++) {
            printf("%d\t", graphT[i][j]);
        }
        printf("\n");
    }


    return 0;
}

void createTranspose(int vertices)
{
    int i, j;

    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            graphT[i][j] = graph[j][i];
        }
    }
}

