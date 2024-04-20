//#include "factorize.c"
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
//#include <math.h>
//#include <time.h>

typedef struct Factors {
    int k ; //сколько различных простых в разложении
    int primes[32]; //различные простые в порядке возрастания
    int powers[32]; //в какие степени надо эти простые возводить
} Factors;

void Factorize ( int X , Factors * res );
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);



//    int cN = 1000000001;
//    char *primes = calloc(cN, 1);
//    primes [1] = 0;
//    primes[0] = primes [1];
//    for(long long i = 2; i < cN; i++){
//        if(primes[i] && i ^ 2 < cN){
//            for (int j=i*i; j<=cN; j+=i)
//                primes[j] = 0;
//        }
//    }
//
//    int prime[]


    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        int X;
        scanf("%d", &X);
        printf("%d = ", X);
        Factors a;
        memset(&(a.primes), 0, 32);
        memset(&(a.powers), 0, 32);
        a.k = 0;
//        a.primes = calloc(32, 4);
//        a.powers = calloc(32, 4);
        Factorize(X, &a);
        int j = 0;
//        if(a.primes[0] == 0) printf("1");
//        while(a.primes[j] != 0){
//            printf("%d^%d ", a.primes[j], a.powers[j]);
//            if(j < 31 && a.primes[j + 1] != 0) printf("* ");
//            j++;
//        }
//        int k = a.k;
        if(a.k == 0 || a.primes[0] == 1 || a.primes[0] == 0) printf("1");
        else{
            for(int k = 0; k < a.k; k++){
                printf("%d^%d", a.primes[k], a.powers[k]);
                if(k + 1 < a.k) printf(" * ");
            }
        }
        if(i + 1 < n) printf("\n");
    }
    return 0;
}