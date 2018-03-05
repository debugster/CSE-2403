#include <bits/stdc++.h>

using namespace std;

#define MAX 100

int graph[MAX + 1][MAX + 1];
int IN_DEG[MAX + 1];
int OUT_DEG[MAX + 1];
vector<int>moreOutward;

void computeDeg(int vertices);
void createList(int vertices);

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
    createList(v);

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

void createList(int vertices)
{
    int i;

    for (i = 1; i <= vertices; i++) {
        if (IN_DEG[i] < OUT_DEG[i]) {
            moreOutward.push_back(i);
        }
    }

    if (moreOutward.empty()) {
        printf("There is no such vertex.\n");
    }
    else {
        for (i = 0; i < moreOutward.size(); i++) {
            printf("%d\t", moreOutward[i]);
        }
    }
}


