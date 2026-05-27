#include <stdio.h>

#define MAX 100

int V[MAX][MAX];
int indegree[MAX];
int visited[MAX];
int TP[MAX];

int main() {
    int n;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &V[i][j]);
        }
    }


    for (int i = 0; i < n; i++) {
        indegree[i] = 0;
        for (int j = 0; j < n; j++) {
            if (V[j][i] == 1) {
                indegree[i]++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    int tp_count = 0;


    while (1) {
        int w = -1;


        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }


        if (w == -1)
            break;


        TP[tp_count++] = w;
        visited[w] = 1;


        for (int i = 0; i < n; i++) {
            if (V[w][i] == 1) {
                indegree[i]--;
            }
        }
    }


    if (tp_count < n) {
        printf("No Topological Sequence (Cycle detected)\n");
    } else {
        printf("Topological Order:\n");
        for (int i = 0; i < tp_count; i++) {
            printf("%d ", TP[i]);
        }
    }

    return 0;
}
