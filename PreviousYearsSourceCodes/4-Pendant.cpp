#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int graph[MAX + 1][MAX + 1];
int IN_DEG[MAX + 1];
int OUT_DEG[MAX + 1];

void computeDeg(int vertices);
int countPendant(int vertices);

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

    computeDeg(v);

    printf("There are %d pendant vertex(s).\n", countPendant(v));

    return 0;
}

void computeDeg(int vertices)
{
    int i, j;

    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            if (graph[j][i] == 1) {
                IN_DEG[i]++;
            }
            if (graph[i][j] == 1) {
                OUT_DEG[i]++;
            }
        }
    }
}

int countPendant(int vertices)
{
    int i, count = 0;

    for (i = 1; i <= vertices; i++) {
        if (IN_DEG[i] == 1 && OUT_DEG[i] == 0) {
            count++;
        }
    }

    return count;
}

