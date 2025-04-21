#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int data;
    int weight;
    struct Node * next;
} Node;

Node * createNode(int data, int weight) {
    Node * new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->weight = weight;
    new->next = NULL;
    return new;
}

void createAdjList(Node ** A, int n) {
    for (int i = 0; i < n; i++) {
        A[i] = NULL;
        int m;
        printf("Enter the number of vertices adjacent to vertex %d: ", i);
        scanf("%d", &m);
        printf("Enter the vertices and their weight adjacent to vertex %d:\n", i);
        for (int j = 0; j < m; j++) {
            int x, w;
            scanf("%d %d", &x, &w);
            Node * temp = createNode(x, w);
            if (A[i] == NULL) {
                A[i] = temp;
            } else {
                Node * p = A[i];
                while (p->next != NULL) {
                    p = p->next;
                }
                p->next = temp;
            }
        }
    }
}

void printAdjList(Node ** A, int n) {
    for (int i = 0; i < n; i++) {
        Node * p = A[i];
        printf("%d\t", i);
        while (p != NULL) {
            printf("%d(%d) ", p->data, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

int original_parent(int i, int * parent) {
    if (parent[i] == 0) return i;
    return parent[i] = original_parent(parent[i], parent); 
}

void remove_edge(Node ** A, int n, int a, int b) {
    Node * temp = A[a];
    while (temp != NULL) {
        if (temp->data == b) {
            temp->weight = INT_MAX;
            break;
        }
        temp = temp->next;
    }

    temp = A[b];
    while (temp != NULL) {
        if (temp->data == a) {
            temp->weight = INT_MAX;
            break;
        }
        temp = temp->next;
    }
}

void kruskals(Node ** A, int n) {
    int a, b, u, v;
    int * parent = (int *)calloc(n, sizeof(int));
    int ne = 0, mincost = 0;

    while (ne < n - 1) {
        int min = INT_MAX;
        for (int i = 0; i < n; i++) {
            Node * temp = A[i];
            while (temp != NULL) {
                if (temp->weight < min) {
                    min = temp->weight;
                    a = u = i;
                    b = v = temp->data;
                }
                temp = temp->next;
            }
        }

        u = original_parent(u, parent);
        v = original_parent(v, parent);

        if (u != v) {
            printf("%d edge (%d, %d) = %d\n", ++ne, a, b, min);
            mincost += min;
            parent[v] = u;
        }

        remove_edge(A, n, a, b);
    }

    printf("The cost of the MST is %d\n", mincost);
}

int main() {
    int n;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    Node ** A = malloc(n * sizeof(Node *));
    createAdjList(A, n);
    printf("\nAdjacency List:\n");
    printAdjList(A, n);
    printf("\nKruskal's MST:\n");
    kruskals(A, n);

    return 0;
}
