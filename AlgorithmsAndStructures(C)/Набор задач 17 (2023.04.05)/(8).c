#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct Vertex{
    long long distance;
    long long num;
    char color;
    char vectorFlag;
    struct VectorInt *adjacent;
    struct Vertex *ancestor;
}Vertex;

typedef struct Vector{//global[1].adjacent->first[1]
    Vertex **first;
    long long used;
    long long len;
} Vector;

void addToVector(Vertex *el, Vector *vector){
    if(vector->used == vector->len){
        vector->first = (Vertex**) realloc(vector->first, (vector->len + 1) * sizeof(Vertex*));
        vector->len++;
    }
    vector->first[vector->used] = el;
    vector->used++;
}

Vertex *getLastFromVector(Vector *vector){
    if(vector->used > 0 && vector->first[vector->used]->vectorFlag){
        vector->used--;
        vector->first[vector->used]->distance = 0;
        return vector->first[vector->used];
    }
    return NULL;
}

Vertex *getMinFromVector(Vector *vector){
    if(vector->used > 0){
        int minI;
        int min = -10 + INT_MAX;
        for(int i = 0; i < vector->used; i++){
            if(vector->first[i]->distance < min && vector->first[i]->vectorFlag){
                minI = i;
                min = vector->first[i]->distance;
            }
        }
        if(min < -11 + INT_MAX){
            vector->first[minI]->vectorFlag = 0;
            return vector->first[minI];
        }
    }
    return NULL;
}

typedef struct VectorInt{
    long long *val;
    long long used;
    long long len;
} VectorInt;

void addToVectorInt(long long el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (long long*) realloc(vector->val, (vector->len + 10) * sizeof(long long));
        vector->len += 10;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

long long getLastFromVectorInt(VectorInt *vector){
    if(vector->used > 0){
        vector->used--;
        return vector->val[vector->used];
    }
    return -1;
}

Vertex **vertices;
Vector *heap2;
int **adjM;
int *degrees;


void relax(Vertex *u, Vertex *v){
    if(v->distance > u->distance + adjM[u->num][v->num]){
        v->distance = u->distance + adjM[u->num][v->num];
        v->ancestor = u;
        if(v->color == 1){
            v->color--;
            addToVector(v, heap2);
        }
    }
}

void init(long long n){
    for(long long i = 1; i <= n; i++){
        vertices[i]->distance = (long long) INT_MAX;
        vertices[i]->ancestor = NULL;
        vertices[i]->color = 1;
        vertices[i]->adjacent->used = degrees[i];
        vertices[i]->vectorFlag = 1;
        heap2->used = 0;
        heap2->len = 0;
////        heap2->first = NULL;//        free(heap2->first);
//        free(heap2);
//        free(*heap2->first);
//        heap2 = (Vector*) calloc(1, sizeof(Vector));
    }
};

long long main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n, e, p;
    scanf("%lld %lld %lld", &n, &e, &p);
    vertices = (Vertex**) calloc(n + 1, sizeof(Vertex*));
    adjM = (int**) calloc(n + 1, sizeof(int*));
    for(int i = 0; i <= n; i++){
        adjM[i] = (int*) calloc(n + 1, sizeof(int));
        for(int j = 0; j <= n; j++) adjM[i][j] = INT_MAX;
    }
    heap2 = (Vector*) calloc(1, sizeof(Vector));
    degrees = (int*) calloc(n + 1, 4);

    int requests[p][2];
    for(int i = 0; i < p; i++) scanf("%d %d", &requests[i][0], &requests[i][1]);

//FIRST INITIALIZE
    for(long long i = 1; i <= n; i++){
        vertices[i] = (Vertex*) calloc(1, sizeof(Vertex));
        vertices[i]->distance = (long long) INT_MAX;
        vertices[i]->num = i;
        vertices[i]->adjacent = NULL;
        vertices[i]->ancestor = NULL;
        vertices[i]->color = 1;
        vertices[i]->vectorFlag = 1;

        vertices[i]->adjacent = (VectorInt *) calloc(1, sizeof(VectorInt));
        vertices[i]->adjacent->val = NULL;
        vertices[i]->adjacent->used = 0;
        vertices[i]->adjacent->len = 0;
    }

    for(long long i = 0; i < e; i++){
        long long row, column, distance;
        scanf("%lld %lld %lld", &row, &column, &distance);
        if(adjM[row][column] > distance) adjM[row][column] = distance;
        if(adjM[column][row] > distance) adjM[column][row] = distance;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(adjM[i][j] < (long long) INT_MAX) addToVectorInt(j, vertices[i]->adjacent);
        }
        degrees[i] = vertices[i]->adjacent->used;
    }

//ALL PAIRS
    for(long long iter = 1; iter < p + 1; iter++){
        //SINGLE SOURCE
        long long fromPoint, endPoint;
        fromPoint = requests[iter - 1][0];
        endPoint = requests[iter - 1][1];
        init(n);
        Vertex *newVert = vertices[fromPoint];
        newVert->distance = 0;
        while(newVert != NULL/* && newVert->adjacent != NULL*/){
            int index = getLastFromVectorInt(newVert->adjacent);
            if(index == -1) break;
            Vertex *adj = vertices[index];
            while(adj != NULL){
                relax(newVert, adj);
                index = getLastFromVectorInt(newVert->adjacent);
                if(index == -1) break;
                adj = vertices[index];
            }
            newVert = getMinFromVector(heap2);
        }
//PRINT
        Vertex *endOfPath = vertices[endPoint];
        Vertex *startOfPath = vertices[fromPoint];
        if(endOfPath->distance == INT_MAX){
            printf("NO\n");
            continue;
        }
        Vertex *ancestor = endOfPath->ancestor;
        VectorInt *ancestors = (VectorInt*) calloc(1, sizeof(VectorInt));
//    addToVectorInt(endOfPath->num, ancestors);
        long long num = 2;
        while(ancestor != startOfPath && ancestor != NULL){
            addToVectorInt(ancestor->num, ancestors);
            ancestor = ancestor->ancestor;
            num++;
        }
        printf("YES %lld %lld %lld ", endOfPath->distance, num, startOfPath->num);
        for(long long b = 0; b < ancestors->used; b++) printf("%lld ", ancestors->val[ancestors->used - b - 1]);
        printf("%lld\n", endOfPath->num);
    }
    return 0;
}