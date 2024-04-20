#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex{
    long long distance;
    int num;
    char color;
    struct Vertex *ancestor;
    struct Vector *adjacent;
}Vertex;

typedef struct Edge{
    long long len;
    Vertex *beginning;
    Vertex *end;
}Edge;

typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

typedef struct Vector{//global[1].adjacent->first[1]
    Edge **first;
    int used;
    int len;
} Vector;

void addToVector(Edge *el, Vector *vector){
    if(vector->used >= vector->len){
        vector->first = (Edge**) realloc(vector->first, (vector->len + 2) * sizeof(Edge*));
        vector->len += 2;
    }
    vector->first[vector->used] = el;
    vector->used++;
}

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 1) * sizeof(int));
        vector->len += 1;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

Vertex **vertices;
Edge **edges;
char *cycledVertices;

int relax(Edge *edge){
//    if(cycledVertices[edge->beginning->num] == 1) cycledVertices[edge->end->num] = 1;
    if(edge->end->distance > edge->beginning->distance + edge->len && edge->beginning->distance < LONG_LONG_MAX){
        edge->end->distance = -1 * LONG_LONG_MAX + 8 > edge->beginning->distance + edge->len ? -1 * LONG_LONG_MAX + 8 : edge->beginning->distance + edge->len;
        edge->end->ancestor = edge->beginning;
        return 1;
    }
    return 0;
}

void dfsVisit(Vertex *vert, int n){
    vert->color = 0;
    for(int i = 0; i < vert->adjacent->used; i++){
        Vertex *tmp = vert->adjacent->first[i]->end;
        if(tmp->color == 1){
//            tmp->ancestor = vert;
            dfsVisit(tmp, n);
        }
    }
    vert->color = -1;
    cycledVertices[vert->num] = 1;
}


int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e, s;
    scanf("%d %d %d\n", &n, &e, &s);
    vertices = (Vertex**) calloc(n, sizeof(Vertex*));
    edges = (Edge**) calloc(e + 1, sizeof(Edge*));
    cycledVertices = (char*) calloc(n + 1, sizeof(char));

//FIRST INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i] = (Vertex*) calloc(1, sizeof(Vertex));
        vertices[i]->adjacent = (Vector*) calloc(1, sizeof(Vector));
        vertices[i]->distance = LONG_LONG_MAX;
        vertices[i]->num = i;
        vertices[i]->color = 1;
        vertices[i]->ancestor = NULL;
    }

    for(int i = 1; i <= e; i++){
        int row, column;
        long long distance;
        scanf("%d %d %lld", &row, &column, &distance);
        Edge *from = (Edge*) calloc(1, sizeof(Edge));
        from->beginning = vertices[row];
        from->end = vertices[column];
        from->len = distance;
        addToVector(from, vertices[row]->adjacent);
        edges[i] = from;
    }

//    for(int i = 1; i <= n; i++){
//        if(vertices[i]->color == 1) dfsVisit(vertices[i], n + 1);
//    }
    //SINGLE SOURCE

    vertices[s]->distance = 0;
    int changeFlag = 0;
    for(int i = 1; i <= n + 1; i++){
        changeFlag = 0;
        for(int j = 1; j <= e; j++){
            Edge *debug = edges[j];
            int cflag = 0;
             changeFlag += cflag = relax(debug);
            if(i == n + 1 && cflag)
                dfsVisit(debug->end, n);
        }
    }

//PRINT
    for(int i = 1; i <= n; i++){
        if(cycledVertices[i] == 1) printf("-\n");
        else if(vertices[i]->distance == LONG_LONG_MAX) printf("*\n");
        else printf("%lld\n", vertices[i]->distance);
    }
    return 0;
}

//7 8 1
//1 2 10
//2 3 5
//1 3 100
//3 5 7
//5 4 10
//4 3 -18
//6 1 -1
//2 7 -50

//4 5 1
//1 2 10
//2 3 -2
//3 2 -3
//2 4 15




//9 11 2
//
//2 3 -5
//3 2 1
//
//1 2 -1
//3 4 10000
//
//1 5 -1
//5 6 10
//6 8 20
//8 5 -210
//
//1 7 -1
//7 9 -10
//9 1 30