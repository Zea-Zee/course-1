#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma comment(linker, "/STACK:50000000")

typedef struct Vertex{
    char color; //1 - white; 0 - gray -1 - black
    int distance;
    int x,y;
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
    QueueEl  *new = (QueueEl*) malloc(sizeof(QueueEl));
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

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int h,w;
    scanf("%d %d", &h, &w);

    Vertex *startPointer, *finishPointer;
    int xs, ys, xf, yf;
    Queue *queue = (Queue*) malloc(sizeof(Queue));
    queue->first = NULL;
    queue->last = NULL;
    Vertex **vertices = (Vertex**) malloc(h * sizeof(Vertex*));
    //INITIALIZE
    for(int i = 0; i < h; i++){
        vertices[i] = (Vertex*) malloc(w * sizeof(Vertex));
        for(int j = 0; j < w; j++){
            char tmp;
            scanf("%c", &tmp);
            if(tmp == '.' || tmp == 'S' || tmp == 'F'){
                vertices[i][j].color = 1;
                vertices[i][j].distance = -1;
                vertices[i][j].adjacent = (Queue*) malloc(sizeof(Queue));
                vertices[i][j].adjacent->first = NULL;
                vertices[i][j].adjacent->last = NULL;
                vertices[i][j].x = j;
                vertices[i][j].y = i;
                if(tmp == 'S'){
                    startPointer = &vertices[i][j];
                    startPointer->color = 0;
                    startPointer->distance = 0;
                    addToQueue(startPointer, queue);
                    xs = j;
                    ys = i;
                }
                if(tmp == 'F'){
                    finishPointer = &vertices[i][j];
                    xf = j;
                    yf = i;
                }
            }
            else if(tmp == 'X')  vertices[i][j].color = -1;
            else j--;
        }
    }

    //FILL ADAJACENT QUE
    if(xs > 0) if(vertices[ys][xs - 1].color == 1) addToQueue(&vertices[ys][xs - 1], startPointer->adjacent);
    if(xs < w - 1) if(vertices[ys][xs + 1].color == 1) addToQueue(&vertices[ys][xs + 1], startPointer->adjacent);
    if(ys > 0) if(vertices[ys - 1][xs].color == 1) addToQueue(&vertices[ys - 1][xs], startPointer->adjacent);
    if(ys < h - 1) if(vertices[ys + 1][xs].color == 1) addToQueue(&vertices[ys + 1][xs], startPointer->adjacent);

    //INITIALIZE ROOT

    //BREADTH FIRST SEARCH
    QueueEl *tmp = extractFromQueue(queue);
    while(tmp != NULL){
        QueueEl *tmp2 = extractFromQueue(tmp->val->adjacent);
        while(tmp2 != NULL){
            if(tmp2->val->color == 1){
                tmp2->val->color = 0;
                tmp2->val->distance = tmp->val->distance + 1;
                if(tmp2->val == finishPointer || (tmp2->val->x == xf && (tmp2->val->y == yf))){
                    printf("%d", tmp2->val->distance);
                    return 0;
                }
                Vertex *v = tmp2->val;
                if(v->x > 0) if(vertices[v->y][v->x - 1].color == 1) addToQueue(&vertices[v->y][v->x - 1], v->adjacent);
                if(v->x < w - 1) if(vertices[v->y][v->x + 1].color == 1) addToQueue(&vertices[v->y][v->x + 1], v->adjacent);
                if(v->y > 0) if(vertices[v->y - 1][v->x].color == 1) addToQueue(&vertices[v->y - 1][v->x], v->adjacent);
                if(v->y < h - 1) if(vertices[v->y + 1][v->x].color == 1) addToQueue(&vertices[v->y + 1][v->x], v->adjacent);
                addToQueue(tmp2->val, queue);
            }
            tmp->val->color = -1;
            tmp2 = extractFromQueue(tmp->val->adjacent);
        }
        tmp = extractFromQueue(queue);
    }

    //PRINT
    printf("-1");
    return 0;
}