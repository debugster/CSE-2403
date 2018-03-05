#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int graph[MAX + 1][MAX + 1];

bool checkLoop(int vertices); /// returns if there exists a Loop

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

    if (checkLoop(v)) {
        printf("Loop(s) exists.\n");
    }
    else {
        printf("No loop exists.\n");
    }

    return 0;
}

bool checkLoop(int vertices)
{
    int i;

    for (i = 1; i <= vertices; i++) {
        if (graph[i][i] == 1) {
            return true;
        }
    }

    return false;
}

