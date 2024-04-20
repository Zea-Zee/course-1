#include <stdio.h>
#include <stdlib.h>

typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 50) * sizeof(int));
        vector->len += 50;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

typedef struct Vertex{
//    int amount;
    int num;
    char color;
    struct Vector *adjacent;
    struct Vertex *ancestor;
//    long long inCap;
//    long long inFlow;
    struct Edge *inEdge;
}Vertex;

typedef struct Edge{
//    int num;
    long long flow;
//    int backFlow;
    long long cap;
    struct Edge *reverse;
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

typedef struct QueueEl{
    Vertex *val;
    struct QueueEl *next;
} QueueEl;

typedef struct Queue{
    QueueEl *first;
    QueueEl *last;
} Queue;

void addToQueue(Vertex *val, Queue *queue){
    QueueEl  *new = (QueueEl*) calloc(1, sizeof(QueueEl));
    new->val = val;
    new->next = NULL;
    if(queue->first == NULL) queue->first = new;
    else queue->last->next = new;
    queue->last = new;
}

QueueEl *extractFromQueue(Queue *queue){
    if(queue == NULL) return NULL;
    QueueEl *first = queue->first;
    if(first == NULL) return NULL;
    queue->first = first->next;
    return first;
}

Vertex **vertices;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e, s, t;
    scanf("%d %d\n", &n, &e);//, &s, &t);
    s = 1;
    t = n;
    vertices = (Vertex**) calloc(n + 1, sizeof(Vertex*));
    VectorInt *explosivePaths = (VectorInt*) calloc(1, sizeof(VectorInt));

//FIRST INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i] = (Vertex*) calloc(1, sizeof(Vertex));
        vertices[i]->num = i;
        vertices[i]->color = 1;
//        vertices[i]->amount = 0;
        vertices[i]->adjacent = (Vector*) calloc(1, sizeof(Vector));
    }

    for(int i = 0; i < e; i++){
        int row, column;
        long long distance;
        scanf("%d %d %lld", &row, &column, &distance);
//        if(row == column) continue;
        Edge *from = (Edge*) calloc(1, sizeof(Edge));
        from->end = vertices[column];
        from->cap = distance;
        from->flow = 0;

        Edge *to = (Edge*) calloc(1, sizeof(Edge));
        to->end = vertices[row];
        to->cap = distance;
        to->flow = 0;

        from->reverse = to;
        to->reverse = from;
        addToVector(from, vertices[row]->adjacent);
        addToVector(to, vertices[column]->adjacent);
    }

    long long answ = 0;
    while(1){
        for(int i = 1; i < n + 1; i++) vertices[i]->color = 1;
        vertices[s]->color = 0;
        Queue *queue = (Queue*) calloc(1, sizeof(Queue));
        addToQueue(vertices[s], queue);
        while(queue != NULL && queue->first != NULL){
            Vertex *u = extractFromQueue(queue)->val;
            for(int i = 0; i < u->adjacent->used; i++){
                if(u->adjacent->first[i]->cap - u->adjacent->first[i]->flow > 0 && u->adjacent->first[i]->end->color){
                    u->adjacent->first[i]->end->color = 0;
                    addToQueue(u->adjacent->first[i]->end, queue);
                    u->adjacent->first[i]->end->ancestor = u;
                    u->adjacent->first[i]->end->inEdge = u->adjacent->first[i];
                }
            }
        }
        free(queue);
        if(vertices[t]->color == 1) break;

        long long CAP = LONG_LONG_MAX;
        Vertex *tmp = vertices[t];
//        printf("BACK PATH: %d ", tmp->num);
        int explosiveStart, explosiveEnd;
        while(tmp != vertices[s]){
            Vertex *anc = tmp->ancestor;
            if(CAP > tmp->inEdge->cap - tmp->inEdge->flow){
                CAP = tmp->inEdge->cap - tmp->inEdge->flow;
                explosiveEnd = tmp->num;
                explosiveStart = anc->num;
            }
            tmp = anc;
//            printf("%d ", tmp->num);
        }
//        printf("explose %d->%d ", explosiveStart, explosiveEnd);
        addToVectorInt(explosiveStart, explosivePaths);
        addToVectorInt(explosiveEnd, explosivePaths);

        tmp = vertices[t];
        while(tmp != vertices[s]){
            Vertex *anc = tmp->ancestor;
            if(tmp == vertices[t]) answ += CAP;
            tmp->inEdge->flow += CAP;
            tmp->inEdge->reverse->flow -= CAP;
//            if(anc == vertices[s]) printf("current:%d ", tmp->inEdge->flow);
            tmp = anc;
        }
//        printf("add:%d\n", CAP);
    }
    printf("%d", answ);
    return 0;
    printf("%lld %d\n", answ, (int) explosivePaths->used / 2);
    for(int i = 0; i < explosivePaths->used; i += 2){
        printf("%d %d\n", explosivePaths->val[i], explosivePaths->val[i + 1]);
//        if(explosivePaths->val[i] > explosivePaths->val[i + 1]) printf("%d %d\n", explosivePaths->val[i + 1], explosivePaths->val[i]);
//        else printf("%d %d\n", explosivePaths->val[i], explosivePaths->val[i + 1]);
    }
    return 0;
}
