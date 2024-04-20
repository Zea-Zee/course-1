#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Vertex{
    char color; //1 - white; 0 - gray -1 - black
    int companenta;
//    int distance;
    int num;
    int f;
    struct Vector *adjacent;
//    struct Vertex *ancestor;
}Vertex;

typedef struct Vector{
    struct Bound **first;
    int used;
    int len;
} Vector;

//typedef struct Bound{
//    Vertex *vert;
//    char isBound;
//} Bound;

void addToVector(Vertex *el, Vector *vector){
    if(vector->used == vector->len){
        vector->first = (Vertex**) realloc(vector->first, (vector->len + 1) * sizeof(Vertex*));
        vector->len += 1;
    }
//    Bound *boundEl = (Bound*) calloc(1, sizeof(Bound));
//    boundEl->vert = el;
//    boundEl->isBound = used;
    vector->first[vector->used] = el;
    vector->used++;
}

typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 10) * sizeof(int));
        vector->len += 10;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

int tout;
int *notGrowF;
int companent;

void dfsVisit(Vertex *vert, int n){
    vert->color = 0;
    for(int i = 0; i < vert->adjacent->used; i++){
        Vertex *tmp = vert->adjacent->first[i];
        if(tmp->color == 1){
//            tmp->ancestor = vert;
            dfsVisit(tmp, n);
        }
    }
    vert->color = -1;
    vert->f = tout;
    notGrowF[tout] = vert->num;
    tout++;
}

void dfsVisitT(Vertex *vert, int n){
    vert->color = 0;
    for(int i = 0; i < vert->adjacent->used; i++){
        Vertex *tmp = vert->adjacent->first[i];
        if(tmp->color == 1){
//            tmp->ancestor = vert;
            dfsVisitT(tmp, n);
        }
    }
    vert->color = -1;
    vert->companenta = companent;
}

//void transpose(Vertex *)

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e;
    scanf("%d %d\n", &n, &e);
    Vertex *vertices = (Vertex*) calloc(n + 1, sizeof(Vertex));
    Vertex *transpodedGraph = (Vertex*) calloc(n + 1, sizeof(Vertex));
    notGrowF = (int*) calloc(n, sizeof(int));
    tout = 0;
    //INITIALIZE
    for(int i = 0; i <= n; i++){
        vertices[i].color = 1;
        vertices[i].num = i;
        vertices[i].adjacent = (Vector*) calloc(1, sizeof(Vector));
        vertices[i].adjacent->used = 0;
        vertices[i].adjacent->len = 0;
        vertices[i].adjacent->first = (Vertex*) calloc(vertices[i].adjacent->len, sizeof(Vertex));

        transpodedGraph[i].color = 1;
        transpodedGraph[i].num = i;
        transpodedGraph[i].adjacent = (Vector*) calloc(1, sizeof(Vector));
        transpodedGraph[i].adjacent->used = 0;
        transpodedGraph[i].adjacent->len = 0;
        transpodedGraph[i].adjacent->first = (Vertex*) calloc(transpodedGraph[i].adjacent->len, sizeof(Vertex));
    }

    //FILL ADJACENT
    for(int i = 0; i < e; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        addToVector(&vertices[to], (vertices[from].adjacent));
        addToVector(&transpodedGraph[from], (transpodedGraph[to].adjacent));
    }

    //DEPTH FIRST SEARCH
    for(int i = 1; i <= n; i++){
        if(vertices[i].color == 1) dfsVisit(&vertices[i], n);
    }
    companent = 1;
    for(int i = n - 1; i >= 0; i--){
        if(transpodedGraph[notGrowF[i]].color == 1){
            dfsVisitT(&transpodedGraph[notGrowF[i]], n);
            companent++;
        }
    }

    printf("%d\n", companent - 1);
    for(int i = 1; i <= n; i++) printf("%d ", transpodedGraph[i].companenta);
    return 0;
}