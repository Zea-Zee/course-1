#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int n;
extern void Init (const int*, int);
extern int64_t Sum (int, int);
extern int Query(int, int64_t);

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r;
    scanf("%d %d", &n, &r);
    int *arr = (int*) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)scanf("%d", &arr[i]);
    Init(arr, n);
    for(int i = 0; i < r; i++){
        int l;
        uint64_t s;
        scanf("%d %lld", &l, &s);
        printf("%d\n", Query(l, s));
    }
    return 0;
}