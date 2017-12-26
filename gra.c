#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>


int Dijkstra(int** arr, int n, int st) {
    int* distance = (int*)malloc(sizeof(int)*n);
    int i, j, u, c, min;
        c = st + 1;
    bool * visited = (bool*) malloc(n);
    for (j = 0; j < n; j++) {
        distance[j] = INT_MAX;
        visited[j] = false;
    }
    distance[st] = 0;
    for (i = 0; i < n - 1; i++) {

        // selecting the current node with min weight from unvisited
        min = INT_MAX;
        for (j = 0; j < n; j++) {
            if (!visited[j] && distance[j] <= min) {
                min = distance[j];
                u = j;
            }
        }
        visited[u] = true;


        for (j = 0; j < n; j++) {
            if (!visited[j] && arr[u][j] && distance[u] != INT_MAX && distance[u] + arr[u][j] < distance[j]) {
                distance[j] = distance[u] + arr[u][j];
            }
        }
    }

    printf("The cost from the node #%d to the other ones: \n", c);
    for (i = 0; i < n; i++) {
        if (distance[i] != INT_MAX) {
            printf("%d > %d = %d\n", c, i + 1, distance[i]);
        } else {
            printf("%d > %d = the route is unavailable\n", c, i + 1);
        }
    }
    return 0;
}

int main() {
    FILE* f = fopen("gra_in.txt", "r");
    int i, j, n, s;
    fscanf(f, "%d\n", &n);
    int** arr = (int**)malloc(sizeof(int*)*n);
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * n);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            // arr[i][j] is same as *(*(arr+i)+j)
            fscanf(f, "%d", &arr[i][j]);
        }
    }

    printf("Plese select the node number to calculte the costs: ");
    scanf("%d", &s);

    Dijkstra(arr, n, s-1);

    return 0;
}