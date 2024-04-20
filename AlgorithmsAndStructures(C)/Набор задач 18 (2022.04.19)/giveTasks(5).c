#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long min(long long a, long long b){
    if(a < b) return a;
    return b;
}

typedef struct Vertex{
    int amount;
    int num;
    char group;
    char color;
    struct Vector *adjacent;
    struct Vertex *ancestor;
//    long long inCap;
//    long long inFlow;
    struct Edge *inEdge;
}Vertex;

typedef struct Edge{
    int num;
    long long flow;
//    int backFlow;
    long long cap;
    struct Edge *reverse;
    Vertex *end;
    Vertex *start;
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

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, e;
    scanf("%d %d %d\n", &a, &b, &e);
    Vertex **tasks;
    Vertex **students;
    students = (Vertex**) calloc(a + 1, sizeof(Vertex*));
    tasks = (Vertex**) calloc(b + 1, sizeof(Vertex*));
//    Vertex *students[a];
//    Vertex *tasks[b];
    Edge **edges = (Edge**) calloc(e, sizeof(Edge*));

    Vertex t;
    t.color = 1;
    t.num = -1;
    t.group = 'T';
    t.adjacent = (Vector*) calloc(1, sizeof(Vector));
    Vertex s;
    s.color = 1;
    s.num = 0;
    s.group = 'S';
    s.adjacent = (Vector*) calloc(1, sizeof(Vector));

//FIRST INITIALIZE
    for(int i = 1; i <= a; i++){
//        memset(students[i], 0, sizeof(Vertex));
//        addToVector()
        students[i] = (Vertex*) calloc(1, sizeof(Vertex));
        students[i]->adjacent = (Vector*) calloc(1, sizeof(Vector));
//        vertices[i]->num = i;
        students[i]->color = 1;
        students[i]->num = i;
        students[i]->group = 'A';
//        vertices[i]->amount = 0;

        Edge *src = (Edge*) calloc(1, sizeof(Edge));
        src->end = students[i];
        src->start = &s;
        src->cap = 1;
        addToVector(src, s.adjacent);

        Edge *rev = (Edge*) calloc(1, sizeof(Edge));
        rev->end = &s;
        rev->start = students[i];
        rev->cap = 1;
        rev->flow = 1;//!!!!!
        addToVector(rev, students[i]->adjacent);
        src->reverse = rev;
        rev->reverse = src;
    }
    for(int i = 1; i <= b; i++){
//        memset(tasks[i], 0, sizeof(Vertex));

        tasks[i] = (Vertex*) calloc(1, sizeof(Vertex));
        tasks[i]->color = 1;
        tasks[i]->num = i;
        tasks[i]->group = 'B';
        tasks[i]->adjacent = (Vector*) calloc(1, sizeof(Vector));

        Edge *sink = (Edge*) calloc(1, sizeof(Edge));
        sink->end = &t;
        sink->start = tasks[i];
        sink->cap = 1;
        addToVector(sink, tasks[i]->adjacent);

        Edge *rev = (Edge*) calloc(1, sizeof(Edge));
        rev->end = tasks[i];
        rev->start = &t;
        rev->cap = 1;
        rev->flow = 1;//!!!!!
        addToVector(rev, t.adjacent);
        sink->reverse = rev;
        rev->reverse = sink;
    }

    for(int i = 0; i < e; i++){
        int row, column;
        long long distance;
        scanf("%d %d", &row, &column);
        Edge *from = (Edge*) calloc(1, sizeof(Edge));
        from->start = students[row];
        from->end = tasks[column];
        from->cap = 1;
//        from->flow = 0;
        from->num = i;
        addToVector(from, students[row]->adjacent);
        edges[i] = from;

        Edge *to = (Edge*) calloc(1, sizeof(Edge));
        to->start = tasks[column];
        to->end = students[row];
        to->cap = 1;
        to->flow = 1;//!!!!!!!!!!!
//        from->num = (1 + i);
        addToVector(to, tasks[column]->adjacent);
        from->reverse = to;
        to->reverse = from;
    }

    long long answ = 0;
    while(1){
        for(int i = 1; i <= a; i++) students[i]->color = 1;
        for(int i = 1; i <= b; i++) tasks[i]->color = 1;
        t.color = 1;
//        vertices[1]->color = 0;
        Queue *queue = (Queue*) calloc(1, sizeof(Queue));
        addToQueue(&s, queue);
        while(queue != NULL && queue->first != NULL){
            Vertex *u = extractFromQueue(queue)->val;
            for(int i = 0; i < u->adjacent->used; i++){
                Edge *tmp = u->adjacent->first[i];
                if(tmp->cap - tmp->flow > 0 && tmp->end->color){
                    tmp->end->color = 0;
                    addToQueue(tmp->end, queue);
                    tmp->end->ancestor = u;
                    tmp->end->inEdge = tmp;
//                    tmp->flow = 1;//!!!
//                    tmp->reverse->flow = 0;//!!!
                }
            }
        }
        free(queue);
        if(t.color == 1) break;

        long long CAP = LONG_LONG_MAX;
        Vertex *tmp = &t;
//        printf("BACK PATH: %d ", tmp->num);
        while(tmp != &s){
            Vertex *anc = tmp->ancestor;
            CAP = min(CAP, tmp->inEdge->cap - tmp->inEdge->flow);
//            printf("%d ", anc->num);
            tmp = anc;
        }
//        printf("/end\n");
        tmp = &t;
        while(tmp != &s){
            Vertex *anc = tmp->ancestor;
//            if(tmp == &t) answ += CAP;
            tmp->inEdge->flow += CAP;
//            if(tmp->group != 'T'
//            && tmp->group != 'S'
//            && tmp->inEdge->end->group != 'T'
//            && tmp->inEdge->end->group != 'S'
//            && tmp->inEdge->start != NULL)
            tmp->inEdge->reverse->flow -= CAP;
            tmp = anc;
            answ++;
        }
    }
    answ = 0;
    for(int i = 0; i < e; i++) if(edges[i] != NULL && edges[i]->flow == 1) answ++;
    printf("%lld\n", answ);
    for(int i = 0; i < e; i++)
        if(edges[i] != NULL && edges[i]->flow == 1)
//            printf("%c:%d %c:%d\n", edges[i]->start->group, edges[i]->start->num, edges[i]->end->group, edges[i]->end->num);
            printf("%d %d\n", edges[i]->start->num, edges[i]->end->num);
    return 0;
}
