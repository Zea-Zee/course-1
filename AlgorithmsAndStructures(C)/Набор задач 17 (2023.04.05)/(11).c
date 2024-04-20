#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Vertex{
    char color; //1 - white; 0 - gray -1 - black
    int distance;
    int tup;
    int num;
    struct Vector *adjacent;
}Vertex;

typedef struct Edge{
    int num;
    Vertex *end;
}Edge;

typedef struct Vector{//global[1].adjacent->first[1]
    Edge **first;
    int used;
    int len;
} Vector;

void addToVector(Edge *el, Vector *vector){
    if(vector->used == vector->len){
        vector->first = (Edge**) realloc(vector->first, (vector->len + 10) * sizeof(Edge*));
        vector->len += 10;
    }
    vector->first[vector->used] = el;
    vector->used++;
}

Edge *getLastFromVector(Vector *vector){
    if(vector->used > 0){
        vector->used--;
        return vector->first[vector->used];
    }
    return NULL;
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

Vertex **heap;
VectorInt *bridges;
int tin;
char *articularPoints;
int articularCount;

void dfsVisit(Vertex *vert, Vertex *p){
    vert->color = 0;
    vert->distance = vert->tup = tin++;
    int children = 0;
    for(int i = 0; i < vert->adjacent->used; i++){
        Vertex *tmp = (Vertex*) vert->adjacent->first[i]->end;
//        if(tmp == NULL || tmp == p) continue;
        if(tmp->color == 0){
            if(vert->tup > tmp->distance) vert->tup = tmp->distance;
            else vert->tup = vert->tup;
        }
        else{
            dfsVisit(tmp, vert);
            if(vert->tup > tmp->tup) vert->tup = tmp->tup;
            else vert->tup = vert->tup;
            if(tmp->tup >= vert->distance && p != NULL){
                if(articularPoints[tmp->num] == 0) articularCount++;;
                articularPoints[vert->num] = 1;
//                articularCount++;
                addToVectorInt(vert->num, bridges);
            }
            children++;
        }
    }
    if(p == NULL && children > 1 ){
        if(articularPoints[vert->num] == 0) articularCount++;
        articularPoints[vert->num] = 1;
        addToVectorInt(vert->num, bridges);
    }
}

int compare(const void * x1, const void * x2){return ( *(int*)x1 - *(int*)x2 );}

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e, p, k;
    scanf("%d %d\n", &n, &e);
    Vertex *vertices = (Vertex*) calloc(n + 1, sizeof(Vertex));
    bridges = (VectorInt*) calloc(1, sizeof(VectorInt));
    bridges->used = 0;
    bridges->len = 0;

    articularPoints = (char*) calloc(n + 1, sizeof(char));
    for(int i = 0; i <= n; i++) articularPoints[i] = 0;
    articularCount = 0;
    int count = 0;
    tin = 1;

//FIRST INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i].distance = -1;
        vertices[i].color = 1;
        vertices[i].num = i;
        vertices[i].adjacent = NULL;

        vertices[i].adjacent = (Vector*) calloc(1, sizeof(Vector));
        vertices[i].adjacent->first = NULL;
        vertices[i].adjacent->used = 0;
        vertices[i].adjacent->len = 0;
    }

    for(int i = 1; i <= e; i++){
        int row, column;
        scanf("%d %d", &row, &column);
        count++;
        if(column == row) continue;

            Edge *fst = (Edge*) malloc(sizeof(Edge));
            fst->end = &vertices[column];
            fst->num = i;
            addToVector(fst, vertices[row].adjacent);

            Edge *snd = (Edge*) malloc(sizeof(Edge));
            snd->end = &vertices[row];
            snd->num = i;
            addToVector(snd, vertices[column].adjacent);
        }

    for(int i = 1; i <= n; i++){
        if(vertices[i].color == 1) dfsVisit(&vertices[i], NULL);
    }

    int newCount = 0;
    for(int i = 1; i <= n; i++) if(articularPoints[i] == 1) newCount++;
    printf("%d\n", newCount);
    for(int i = 1; i <= n; i++) if(articularPoints[i] == 1) printf("%d ", i);

//    if(bridges->used > 0){
//        qsort(bridges->val, bridges->used, sizeof(int), compare);
//        int cc = 0;
//        int last = -1;
//        int ansArr[bridges->used];
//        for(int i = 0; i < bridges->used; i++){
//            if(bridges->val[i] == last) continue;
//            last = bridges->val[i];
//            ansArr[cc] = last;
//            cc++;
//        }
//        printf("%d\n", cc);
//        for(int i = 0; i < cc; i++) printf("%d ", ansArr[i]);
//    }

    return 0;
}