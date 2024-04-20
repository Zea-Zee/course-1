#include <stdio.h>
#include <stdlib.h>

long long usedMem;
long long freedMem;

typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 5) * sizeof(int));
        vector->len += 5;
        usedMem += 5 * sizeof(int);
    }
    vector->val[vector->used] = el;
    vector->used++;
}

typedef struct Vertex{
    int inFlow;
    int num;
    char color;
    struct Vector *adjacent;
    struct Vertex *ancestor;
//    long long inCap;
//    long long inFlow;
    struct Edge *inEdge;
}Vertex;

typedef struct Edge{
    int num;
    char isStraight;
    char flow;
//    int backFlow;
    int cap;
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
        vector->first = (Edge**) realloc(vector->first, (vector->len + 2) * sizeof(Edge*));
        vector->len += 2;
        usedMem += 2 * sizeof(Edge*);
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
    usedMem += sizeof(QueueEl);
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
    usedMem = 0;
    freedMem = 0;
    int n, e, o, s, t;
    scanf("%d%d%d%d%d", &n, &e, &o, &s, &t);
    vertices = (Vertex**) calloc(n + 1, sizeof(Vertex*));
    usedMem += (n + 1) * sizeof(Vertex*);

//FIRST INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i] = (Vertex*) calloc(1, sizeof(Vertex));
        usedMem += sizeof(Vertex);
        vertices[i]->num = i;
        vertices[i]->color = 1;
//        vertices[i]->amount = 0;
        vertices[i]->adjacent = (Vector*) calloc(1, sizeof(Vector));
        usedMem += sizeof(Vector);
    }

    for(int i = 0; i < e; i++){
        int row, column;
        scanf("%d %d", &row, &column);
//        if(row == column) continue;
        Edge *from = (Edge*) calloc(1, sizeof(Edge));
        usedMem += sizeof(Edge) * 2;
        from->end = vertices[column];
        from->cap = 1;
        from->flow = 0;
        from->num = i + 1;
        from->isStraight = 1;

        Edge *to = (Edge*) calloc(1, sizeof(Edge));
        to->end = vertices[row];
        to->cap = 1;
        to->num = i + 1;
        if(o){
            to->isStraight = 0;
            to->flow = 1;
        }
        else{
            to->isStraight = 1;
            to->flow = 0;
        }

        from->reverse = to;
        to->reverse = from;
        addToVector(from, vertices[row]->adjacent);
        addToVector(to, vertices[column]->adjacent);
    }


//    printf("3\n2\n1 4 8\n8 9 4\n2\n1 12 6\n6 10 4\n4\n1 15 7\n7 13 6\n6 8 3\n3 7 4\n");
//    return 0;


    int answ = 0;
    while(1){
        if(usedMem > 10000000) exit(-1);
        for(int i = 1; i < n + 1; i++) vertices[i]->color = 1;
        vertices[s]->color = 0;
        Queue *queue = (Queue*) calloc(1, sizeof(Queue));
        usedMem += sizeof(Queue);
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
//        free(queue->first);
        freedMem += sizeof(queue);
        free(queue);
        if(vertices[t]->color == 1) break;

        int CAP = INT_MAX;
        Vertex *tmp = vertices[t];
//        printf("BACK PATH: %d ", tmp->num);
        while(tmp != vertices[s]){
            Vertex *anc = tmp->ancestor;
            if(CAP < tmp->inEdge->cap - tmp->inEdge->flow) CAP = CAP;
            else{
                CAP = tmp->inEdge->cap - tmp->inEdge->flow;
            }
            tmp = anc;
//            printf("%d ", tmp->num);
        }

        tmp = vertices[t];
        while(tmp != vertices[s]){
            Vertex *anc = tmp->ancestor;
            if(tmp == vertices[t]) answ += CAP;
//            tmp->amount += CAP;
            tmp->inFlow += CAP;
//            anc->outFlow += CAP;
            tmp->inEdge->flow += CAP;
            tmp->inEdge->reverse->flow -= CAP;
//            if(anc == vertices[s]) printf("current:%d ", tmp->inEdge->flow);
            tmp = anc;
        }
//        printf("add:%d\n", CAP);
    }
    if(usedMem > 10000000) exit(-2);
    printf("%d\n", answ);
    int pathCounter = 0;
    while(pathCounter < answ){
        if(usedMem > 10000000) exit(-3);
        for(int i = 1; i < n + 1; i++) vertices[i]->color = 1;
        vertices[s]->color = 0;
        Queue *queue = (Queue*) calloc(1, sizeof(Queue));
        usedMem += sizeof(Queue);
        addToQueue(vertices[s], queue);
//        int numOfEdgesInPath = 0;
        while(queue != NULL && queue->first != NULL){
            Vertex *u = extractFromQueue(queue)->val;
//            numOfEdgesInPath++;
            int flag = 0;
            for(int i = 0; i < u->adjacent->used; i++){
                if(u->adjacent->first[i]->flow == 1
                && u->adjacent->first[i]->end->color
                && u->adjacent->first[i]->isStraight == 1
                && (u->inFlow > 0 || (u->num == s || u->num != t)))
                {
                    flag = 1;
                    u->adjacent->first[i]->end->color = 0;
//                    u->adjacent->first[i]->flow = 0;
                    u->adjacent->first[i]->end->ancestor = u;
                    u->adjacent->first[i]->end->inEdge = u->adjacent->first[i];
                    u->inFlow--;
                    if(u->adjacent->first[i]->end->num == t) break;
                    addToQueue(u->adjacent->first[i]->end, queue);
                }
            }
//            if(!flag) numOfEdgesInPath--;
        }
//        free(queue->first);
        freedMem += sizeof(queue);
        free(queue);
        if(vertices[t]->color == 1) break;
//        printf("%d\n", numOfEdgesInPath);
        VectorInt *path = (VectorInt*) calloc(1, sizeof(VectorInt));
        usedMem += sizeof(VectorInt);
        Vertex *tmp = vertices[t];
        int numOfEdgesInPath = 0;
        while(tmp != vertices[s]){
            Vertex *anc = tmp->ancestor;
            addToVectorInt(tmp->num, path);
            addToVectorInt(tmp->inEdge->num, path);
            addToVectorInt(tmp->ancestor->num, path);
            tmp->inEdge->flow = 0;
            tmp->inEdge->reverse->flow = 0;
            tmp->inFlow = 0;
            tmp = anc;
            numOfEdgesInPath++;
        }
                printf("%d\n", numOfEdgesInPath);
        for(int p = path->used - 1; p >= 0; p -= 3){
            printf("%d %d %d\n", path->val[p], path->val[p - 1], path->val[p - 2]);
        }
        pathCounter++;
        freedMem += sizeof(path->val) * path->used;
        free(path->val);
        freedMem += sizeof(path);
        free(path);
    }
    if(usedMem > 10000000) exit(-4);
//    printf("vertice mem:%d edge mem:%d", sizeof(Vertex), sizeof(Edge));
    int gFreed = freedMem;
    for(int i = 1; i <= n; i++){
        gFreed += sizeof(vertices[i]->adjacent->first) * vertices[i]->adjacent->used;
        free(vertices[i]->adjacent->first);
        gFreed += sizeof(vertices[i]->adjacent);
        free(vertices[i]->adjacent);
        gFreed += sizeof(vertices[i]->inEdge);
        free(vertices[i]->inEdge);
    }
    free(vertices);
    if(usedMem > 10000000) exit(-5);
//    printf("\ntotal used: %lld freed mem:%d global freed:%d", usedMem, freedMem, gFreed);
    return 0;
}
