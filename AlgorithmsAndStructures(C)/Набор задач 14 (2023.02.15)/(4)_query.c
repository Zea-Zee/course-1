#include <stdint.h>
extern int n;
extern int64_t Sum (int l, int r);
int Query(int l, int64_t sum) {
    int left = 0, right = n, middle = (left + right) / 2;
    while(right >= left){
//        if(sum >= Sum(l, middle)) left = middle + 1;
//        else right = middle - 1;
        if(sum < Sum(l, middle)) right = middle - 1;
        else left = middle + 1;
        middle = (right + left) * (1. / 2);
    }
    if(Sum(l, n) <= sum || l == n) return n;
    while(sum >= Sum(l, middle)) ++middle;
    return --middle;
}