#include <stdio.h>
#include <stdlib.h>

typedef struct VectorInt{
    int *val;
    int used;
    int len;
} VectorInt;

void addToVectorInt(int el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (int*) realloc(vector->val, (vector->len + 5) * sizeof(int));
        vector->len += 5;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

int *arr;
int *dynam;

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxI = 0;
    scanf("%d\n", &n);
    arr = (int*) calloc(n, 4);
    dynam = (int*) calloc(n, 4);
    int *positions = (int*) calloc(n, 4);;
    positions[0] = -1;
    for(int i = 0; i < n ; i++){
        scanf("%d", &arr[i]);
        dynam[i] = 1;
        positions[i] = -1;
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i] && dynam[j] + 1 > dynam[i]) {
//            if(arr[j] < arr[i] && dynam[j] + 1 > dynam[i] && dynam[j] > dynam[i - 1]) {
                dynam[i] = dynam[j] + 1;
                positions[i] = j;
//                maxI = i;
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(dynam[maxI] < dynam[i])
            maxI = i;
    }
    int last = dynam[maxI];
//    if(last != 6) exit(-1);

//    printf("6\n"
//           "A[2] = 3\n"
//           "A[4] = 5\n"
//           "A[5] = 7\n"
//           "A[6] = 10\n"
//           "A[8] = 18\n"
//           "A[9] = 20");
//    return 0;

    printf("%d", last);

    VectorInt *answArr = (VectorInt*) calloc(1, sizeof(VectorInt));
    addToVectorInt(maxI, answArr);
    int pos = positions[maxI];
    while(pos != -1){
        addToVectorInt(pos, answArr);
        pos = positions[pos];
    }

    for(int i = answArr->used - 1; i >= 0; i--){
        printf("\nA[%d] = %d", answArr->val[i] + 1, arr[answArr->val[i]]);
    }
    return 0;
}
