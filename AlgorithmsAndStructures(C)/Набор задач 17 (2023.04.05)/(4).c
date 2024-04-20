#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vertex{
    char color; //1 - white; 0 - gray -1 - black
    int distance;
    int num;
    int f;
    struct Vector *adjacent;
    struct Vertex *ancestor;
}Vertex;

typedef struct Vector{
    Vertex **first;
    int used;
    int len;
} Vector;

void addToVector(Vertex *el, Vector *vector){
    if(vector->used == vector->len){
        vector->first = (Vertex**) realloc(vector->first, (vector->len + 10) * sizeof(Vertex*));
        vector->len += 10;
    }
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

int time;

void dfsVisit(Vertex *vert, int n){
    vert->color = 0;
//    vert->distance = time;
//    time++;
    for(int i = 0; i < vert->adjacent->used; i++){
        Vertex *tmp = vert->adjacent->first[i];
        if(tmp->color == 0){
            printf("NO");
            exit(0);
        }
        else if(tmp->color == 1){
            tmp->ancestor = vert;
            dfsVisit(tmp, n);
        }
    }
    vert->color = -1;
    vert->f = time;
    time++;
}

int main () {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        int n, e;
        scanf("%d %d\n", &n, &e);
        Vertex  *vertices = (Vertex*) calloc(n + 1, sizeof(Vertex));
        time = 0;
        //INITIALIZE
        for(int i = 0; i <= n; i++){
            vertices[i].color = 1;
            vertices[i].distance = 0;
            vertices[i].num = i;
            vertices[i].adjacent = (Vector*) calloc(1, sizeof(Vector));
            vertices[i].adjacent->used = 0;
            vertices[i].adjacent->len = 0;
            vertices[i].adjacent->first = (Vertex*) calloc(vertices[i].adjacent->len, sizeof(Vertex));
            vertices[i].ancestor = NULL;// (Vertex*) calloc(1, sizeof(Vertex*));
        }

        //FILL ADJACENT
        for(int i = 0; i < e; i++){
            int from, to;
            scanf("%d %d", &from, &to);
            addToVector(&vertices[to], (vertices[from].adjacent));
        }

        //DEPTH FIRST SEARCH
        for(int i = 1; i <= n; i++){
            if(vertices[i].color == 1) dfsVisit(&vertices[i], n);
        }
        printf("YES\n");
        for(int i = 1; i <= n; i++){
            printf("%d ", n - vertices[i].f);
        }
//        printf("-1");
        return 0;
    }