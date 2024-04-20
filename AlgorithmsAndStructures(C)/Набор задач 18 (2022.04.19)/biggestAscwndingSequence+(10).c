#include <stdio.h>
#include <stdlib.h>

long long upperBound(long long *arr, long long x, long long n){
//    n++;
    long long left = 0, right = n, middle;
    while(left < right){
        if(middle == left + (long long) (right - left) / 2) return left;
        middle = left + (long long) (right - left) / 2;
        if(arr[middle] > x) right = middle;
        else left = middle + 1;
    }
    return left;
}

typedef struct VectorInt{
    long long *val;
    long long used;
    long long len;
} VectorInt;

void addToVectorInt(long long el, VectorInt *vector){
    if(vector->used == vector->len){
        vector->val = (long long*) realloc(vector->val, (vector->len + 5) * sizeof(long long));
        vector->len += 5;
    }
    vector->val[vector->used] = el;
    vector->used++;
}

long long *arr;
long long *dynam;
long long *positions;
long long *prev;

long long main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long long n;
    scanf("%lld", &n);
//    if(n > 5 && n != 12)
    arr = (long long*) calloc(n + 1, 8);
    dynam = (long long*) calloc(n + 1, 8);
    positions = (long long*) calloc(n + 1, 8);
    prev = (long long*) calloc(n + 1, 8);

    long long len = 0;
    positions[0] = -1;
    dynam[0] = -1 * LLONG_MAX;
    for(int i = 1; i <= n; i++) dynam[i] = LLONG_MAX;
    for(int i = 0; i < n; i++) scanf("%lld", &arr[i]);
//    for(int i = 0; i < n; i++) if(arr[])
    for(int i = 0; i < n; i++){
        long long j = upperBound(dynam, arr[i], n);
        if(dynam[j - 1] < arr[i] && arr[i] < dynam[j]){
            dynam[j] = arr[i];
            positions[j] = i;
            prev[i] = positions[j - 1];
            len = len > j ? len : j;
        }
    }

//    if(len >= n) exit(-1);

    printf("%lld", len);
    VectorInt *answArr = (VectorInt*) calloc(1, sizeof(VectorInt));
    long long pos = positions[len];
    while(pos != -1){
        addToVectorInt(pos, answArr);
        pos = prev[pos];
    }
    for(int i = answArr->used - 1; i >= 0; i--){
//        if(i > 0 && answArr->val[i] >= answArr->val[i - 1]) exit(-1);
//        if(i > 0 && arr[answArr->val[i]] >= arr[answArr->val[i - 1]]) exit(-2);
        printf("\nA[%lld] = %lld", answArr->val[i] + 1, arr[answArr->val[i]]);
    }
    return 0;
}
