#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex{
    long long distance;
    int num;
    struct Vertex *ancestor;
}Vertex;

typedef struct Edge{
    int len;
    Vertex *beginning;
    Vertex *end;
}Edge;


typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 1) * sizeof(int));
        vector->len += 1;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

Vertex **vertices;
Edge *edges;

char relax(Edge *edge){
    if(edge->end->distance > edge->beginning->distance + edge->len){
        edge->end->distance = edge->beginning->distance + edge->len;
        edge->end->ancestor = edge->beginning;
        return 1;
    }
    return 0;
}

void init(int n){
    for(int i = 2; i <= n; i++){
        vertices[i]->distance = INT_MAX;
        vertices[i]->ancestor = NULL;
    }
};

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e, r;
    scanf("%d %d %d\n", &n, &e, &r);
    vertices = (Vertex**) calloc(n, sizeof(Vertex*));
    edges = (Edge*) calloc(e + 1, sizeof(Edge));

//FIRST INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i] = (Vertex*) calloc(1, sizeof(Vertex));
        vertices[i]->distance = (long long) -10 + INT_MAX;
        vertices[i]->num = i;
        vertices[i]->ancestor = NULL;
    }

    int *requests = (int*) calloc(r, sizeof(int));
    for(int i = 0; i < r; i++) scanf("%d", &requests[i]);


    for(int i = 1; i <= e; i++){
        int row, column, distance;
        scanf("%d %d %d", &row, &column, &distance);

        edges[i].beginning = vertices[row];
        edges[i].len = distance;
        edges[i].end = vertices[column];
    }

//ALL PAIRS
    Vertex *startOfPath = vertices[1];
    init(n);
    for(int iter = 0; iter < r; iter++){
        //SINGLE SOURCE

        vertices[1]->distance = 0;
        int changeFlag = 1;
        for(int i = 0; i < n; i++){
            changeFlag = 0;
            for(int i = 1; i <= e; i++){
                Edge debug = edges[i];
                changeFlag += relax(&debug);
            }
            if(changeFlag == 0) break;
        }

//PRINT
        Vertex *endOfPath = vertices[requests[iter]];
        Vertex *ancestor = endOfPath->ancestor;
        VectorInt *ancestors = (VectorInt*) calloc(1, sizeof(VectorInt));
        int num = 2;
        while(ancestor != NULL && ancestor != startOfPath){
            addToVectorInt(ancestor->num, ancestors);
            ancestor = ancestor->ancestor;
            num++;
        }
        printf("%lld %d %d ", endOfPath->distance, num, startOfPath->num);
        for(int b = 0; b < ancestors->used; b++) printf("%d ", ancestors->val[ancestors->used - b - 1]);
        printf("%d\n", endOfPath->num);
//        free(ancestors->val);
//        free(ancestors);
        ancestors->used = 0;
    }
    return 0;
}