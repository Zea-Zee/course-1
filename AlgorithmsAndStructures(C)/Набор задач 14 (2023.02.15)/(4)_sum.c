#include <stdlib.h>
#include <stdint.h>
static int64_t *sums;
void Init (const int *arr, int n){
    sums = (int64_t*) calloc(n + 1, sizeof(int64_t));
    for(int i = 0; i < n; i++) sums[i + 1] = sums[i] + arr[i];
    sums[0];
}
int64_t Sum (int l, int r){ return sums[r] - sums[l];}
