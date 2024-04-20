#include <stdio.h>
#include <stdlib.h>
#ifndef DOHULILLION
#define DOHULILLION 1000000000000000000
#endif

typedef struct Vertex{
    long long distance;
    int num;
    long long heapPosition;
    struct Vector *adjacent;
    struct Vertex *ancestor;
    int inputTrip;
    int tripCount;
}Vertex;

typedef struct Edge{
    int num;
    long long len;
    Vertex *end;
}Edge;

typedef struct Vector{//global[1].adjacent->first[1]
    Edge **first;
    int used;
    int len;
} Vector;

void addToVector(Edge *el, Vector *vector){
    if(vector->used >= vector->len){
        vector->first = (Edge**) realloc(vector->first, (vector->len + 200) * sizeof(Edge*));
        vector->len += 200;
    }
    vector->first[vector->used] = el;
    vector->used++;
}

typedef struct VectorV{//global[1].adjacent->first[1]
    Vertex **first;
    int used;
    int len;
} VectorV;

void addToVectorV(Vertex *el, VectorV *vector){
    if(vector->used == vector->len){
        vector->first = (Vertex**) realloc(vector->first, (vector->len + 100) * sizeof(Vertex*));
        vector->len += 100;
    }
    vector->first[vector->used] = el;
    vector->used++;
}

typedef struct VectorInt{
    long long *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(long long el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (long long*) realloc(vector->val, (vector->len + 50) * sizeof(long long));
        vector->len += 50;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

Vertex **vertices;
VectorV *heap;

void swap(long long a, long long b){
    Vertex *tmp = heap->first[a];
    heap->first[a] = heap->first[b];
    heap->first[b] = tmp;
    if(b < heap->used)
        heap->first[b]->heapPosition = b;
    else
        heap->first[b]->heapPosition = -1;
    if(a < heap->used)
        heap->first[a]->heapPosition = a;
    else
        heap->first[a]->heapPosition = -1;
}

void siftDown(int i){
    while(2 * i + 1 < heap->used) {     // heapSize — количество элементов в куче
        int left = 2 * i + 1;            // left — левый сын
        int right = 2 * i + 2;            // right — правый сын
        int j = left;
        if(right < heap->used && heap->first[right]->distance < heap->first[left]->distance) j = right;
        if(heap->first[i]->distance <= heap->first[j]->distance) break;
        swap(i, j);
        i = j;
    }
}


Vertex *extraxtMin(){
    if(heap->used > 0){
        Vertex *min = heap->first[0];
        heap->first[0] = heap->first[heap->used - 1];
        heap->used--;
        siftDown(0);
        min->heapPosition = -1;
        return min;
    }
    return NULL;
}

void siftUp(int i){
    while(heap->first[i]->distance < (long long) heap->first[(i - 1) / 2]->distance){
        swap(i, (long long) (i - 1) / 2);
        i = (int) (i - 1) / 2;
    }
}

void addToHeap(Vertex *el){
    addToVectorV(el, heap);
    siftUp(heap->used - 1);
}

void relax(Vertex *u, Edge *v){
    if(v->end->distance > u->distance + v->len){
        v->end->distance = u->distance + (long long) v->len;
        v->end->ancestor = u;
        v->end->tripCount = u->tripCount + 1;
        v->end->inputTrip = v->num;
        if(v->end->heapPosition == -1){
            addToHeap(v->end);
        } else{
            siftUp(v->end->heapPosition);
        }
    }
}

void init(int n) {
    for (int i = 1; i <= n; i++) {
        vertices[i]->distance = (long long) DOHULILLION;
        vertices[i]->ancestor = NULL;
        vertices[i]->inputTrip = -1;
        vertices[i]->heapPosition = -1;
        vertices[i]->tripCount = (int) INT_MAX;
    }
//    heap->used = 0;
}


int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e, p;
    scanf("%d %d %d\n", &n, &e, &p);
    vertices = (Vertex**) calloc(n + 1, sizeof(Vertex*));
    heap = (VectorV*) calloc(1, sizeof(VectorV));
    int requests[p][2];
    for(int i = 0; i < p; i++) scanf("%d %d", &requests[i][0], &requests[i][1]);

//FIRST INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i] = (Vertex*) calloc(1, sizeof(Vertex));
        vertices[i]->num = i;
        vertices[i]->adjacent = NULL;
        vertices[i]->adjacent = (Vector*) calloc(1, sizeof(Vector));
    }

    for(int i = 0; i < e; i++){
        int row, column;
        long long distance;
        scanf("%d %d %lld", &row, &column, &distance);
        if(row == column) continue;
        Edge *from = (Edge*) calloc(1, sizeof(Edge));
        from->end = vertices[column];
        from->len = distance;
        from->num = (1 + i);
        addToVector(from, vertices[row]->adjacent);
    }

//ALL PAIRS
    for(int iter = 1; iter <= p; iter++){
        //SINGLE SOURCE
        int fromPoint, endPoint;
        fromPoint = requests[iter - 1][0];
        endPoint = requests[iter - 1][1];
        init(n);
//        for(int i = 1; i <= n; i++) addToHeap(vertices[i]);
        vertices[fromPoint]->distance = 0;
        vertices[fromPoint]->tripCount = 0;
        addToHeap(vertices[fromPoint]);
        while(1/* && newVert->adjacent != NULL*/){
            Vertex *newVert = extraxtMin();
            if(newVert == NULL) break;
            for(int i = 0; i < newVert->adjacent->used; i++){
                Edge *adj = newVert->adjacent->first[i];
                if(adj != NULL)
                    relax(newVert, adj);
            }
//            printf("num:%d distance:%d tripCount:%d\n", newVert->num, newVert->distance, newVert->tripCount);
        }
//PRINT
        Vertex *endOfPath = vertices[endPoint];
        if(endOfPath->distance < (long long) DOHULILLION){
            Vertex *ancestor = endOfPath;
            VectorInt *ancestors = (VectorInt *) calloc(1, sizeof(VectorInt));
            for(int i = 0; i < endOfPath->tripCount; i++){
                addToVectorInt(ancestor->inputTrip, ancestors);
                ancestor = ancestor->ancestor;
            }
            printf("quarantine %lld %d ", endOfPath->distance, ancestors->used);
            for (int b = 0; b < ancestors->used; b++) printf("%d ", ancestors->val[ancestors->used - b - 1]);
            printf("\r");
        } else printf("DOOMED\r");
    }
    return 0;
}