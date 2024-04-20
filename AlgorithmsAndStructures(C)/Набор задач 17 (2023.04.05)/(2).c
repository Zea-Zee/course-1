#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 200000

//typedef struct ListEl{
//    int val;
//    struct ListEl *next;
//}ListEl;
//
//typedef struct List{
//    ListEl *first;
//    ListEl *last;
//}List;

typedef struct Vertex{
    char color; //1 - white; 0 - gray -1 - black
    int distance;
    int num;
    struct Queue *adjacent;
}Vertex;

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
    if(queue->first == NULL){
        queue->first = new;
    }else queue->last->next = new;
    queue->last = new;
}

QueueEl *extractFromQueue(Queue *queue){
    if(queue == NULL) return NULL;
    QueueEl *first = queue->first;
    if(first == NULL) return NULL;
    queue->first = first->next;
    return first;
}

//void addToList(int val, List* list){
//    ListEl *new = calloc(1, sizeof(ListEl));
//    new->val = val;
//    new->next = NULL;
//    if(list->first == NULL){
//        list->first = new;
//        list->last = new;
//    }
//    list->last->next = new;
//    list->last = new;
//}
//
//ListEl *getFromList()

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, e;
    scanf("%d %d", &n, &e);
    Queue *queue = (Queue*) calloc(1, sizeof(Queue));
    Vertex *vertices = (Vertex*) calloc(n + 1, sizeof(Vertex));

    int verticesRel[n+1][2];
    int lens[N+1] = {0};
    //INITIALIZE
    for(int i = 1; i <= n; i++){
        vertices[i].color = 1;
        vertices[i].distance = -1;
        vertices[i].num = i;
        vertices[i].adjacent = (Queue*) calloc(1, sizeof(Queue));
//        lens[i] = INT_MAX;
    }
    for(int i = 0; i < e; i++){
        int from, to;
        scanf("%d %d", &from, &to);
        addToQueue(&vertices[to], (vertices[from].adjacent));
    }
    vertices[1].color = 0;
    vertices[1].distance = 0;
    addToQueue(&vertices[1], queue);
//    for(int i = 0; i < 200; i++){
//        addToQueue(i, queue);
//    }
    QueueEl *tmp = extractFromQueue(queue);
    while(tmp != NULL){
        QueueEl *tmp2 = extractFromQueue(tmp->val->adjacent);
        while(tmp2 != NULL){
            if(tmp2->val->color == 1){
                tmp2->val->color = 0;
                tmp2->val->distance = tmp->val->distance + 1;
                addToQueue(tmp2->val, queue);
            }
            tmp->val->color = -1;
            tmp2 = extractFromQueue(tmp->val->adjacent);
        }
        tmp = extractFromQueue(queue);
    }
    for(int i = 1; i <= n; i++){
        printf("%d\n", vertices[i].distance);
    }
    return 0;
}