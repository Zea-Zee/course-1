#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 10000
#define RAND -1
#define DOHUYA 1000000000

// int* deleteCopies(int arr[], int *len){
//     int last = arr[0];
//     int res[*len], n = 1;
//     res[0] = last;
//     for(int i = 1; i < *len; i++){
//         if(arr[i] != last){
//             res[n] = arr[i];
//             n++;
//         }
//         last = arr[i];
//     }
//     len = &n;
//     return res;
// }

int compare(const void * x1, const void * x2){return ( *(int*)x1 - *(int*)x2 );}

int main(){
    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int a, b;
    scanf("%d", &a);
    int arr[a];
    for(int i = 0; i < a; i++) scanf("%d", &(arr[i]));
    scanf("%d", &b);
    int brr[b];
    for(int i = 0; i < b; i++) scanf("%d", &(brr[i]));
    qsort(arr, a, sizeof(int), compare);
    qsort(brr, b, sizeof(int), compare);
    

    int setA[a];
    int counterA = 1;
    int last = arr[0];
    setA[0] = last;
    for(int i = 1; i < a; i++){
        int el = arr[i];
        if(el != last){
        setA[counterA] = el;
        counterA++;
        last = el;
        }
    }

    int setB[b];
    int counterB = 1;
    last = brr[0];
    setB[0] = last;
    for(int i = 1; i < b; i++){
        int el = brr[i];
        if(el != last){
        setB[counterB] = el;
        counterB++;
        last = el;
        }
    }


    int res[100000];
    int c = 0, aI = 0, bI = 0, len = counterA + counterB;
    for(int i = 0; i < len; i++){
        if(aI >= counterA) break;
        if(bI < counterB){
            int al = setA[aI], bl = setB[bI];
            if(bl < al){
                bI++;
                continue;
            }
            else if(al < bl){
                res[c] = al;
                c++;
                aI++;
            } else if(bl == al){
                bI++;
                aI++;
            }
        } else {
            int al = setA[aI], bl = setB[counterB - 1];
            if(al == bl) aI++;
            else{
                res[c] = al;
                c++;
                aI++;
            }
        }
    }
    printf("%d\n", c);
    for(int i = 0; i < c; i++) printf("%d ", res[i]);
    return 0;
}