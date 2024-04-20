#include "primes.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 10000020

static int *numOfPrimes;
static char *sieve;
static int *primes;
static char *isSieveComputed = 0;
static int primeCount = 0;

static void Eratosphen(){
    isSieveComputed = 1;
    sieve = (char*) calloc(N, 1);
    numOfPrimes = (int*) calloc(N, 4);
    primes = (int*) calloc(N, 4);
    for(int i = 0; i < N; i++) sieve[i] = 1;
    sieve[0] = sieve[1] = 0;
    numOfPrimes[0] = 0;
    for(int i = 2; i < N; i++){
        if(sieve[i]){
//            printf("%d ", i);
            primes[primeCount] = i;
            primeCount++;
            for(int j = i * i; i <= sqrt((double) N) && j < N; j += i){
                if(j >= N) break;
                sieve[j] = 0;
            }
        }
    }
//    for(int i = 1; i < N; i++){
//        if(sieve[i]) numOfPrimes[i] = numOfPrimes[i - 1] + 1;
//        else numOfPrimes[i] = numOfPrimes[i - 1];
//    }
    for(int i = 1; i < N; i++) numOfPrimes[i] = numOfPrimes[i - 1] + sieve[i];
}

static int binSearch(int x){
    int left = -1, right = primeCount, middle;
    int minCloset = primeCount - 1, minMiddle = right;
    int edgeCheck = 0;
    int last = primes[middle];
    while(left < right - 1){
        middle = (left + right) / 2;
//        if(middle < minMiddle) minMiddle = middle;
//        if(middle > )
        if(primes[middle] == x) return middle;
        if(primes[middle] > x){
            if(primes[middle] - x < primes[minCloset] - x) minCloset = middle;
            else break;
//            right--;
            right = middle;
        }
        else left = middle;//left++;
        if(primes[middle] == last) break;
        last = primes[middle];
    }
    return minCloset;
}

int isPrime(int x){
    if(!isSieveComputed) Eratosphen();
    return (int) sieve[x];
}
int findNextPrime(int x){
    if(!isSieveComputed) Eratosphen();
    if(x > 9999991) return 10000019;
    for(int i = x; i <= 10000019; i++){
        if(sieve[i]) return i;
    }
//    return primes[binSearch(x)];
}
int getPrimesCount(int l, int r){
    if(l > 9999991) return 0;
    if(!isSieveComputed) Eratosphen();
//    int leftPos = binSearch(l);
//    int rightPos = binSearch(r);
    int count = 0;
//    for(int i = l; i < )
//    printf("%d %d %d %d %d\n", l, r, numOfPrimes[l], numOfPrimes[r], numOfPrimes[r] - numOfPrimes[l]);
//    printf("%d %d %d %d %d\n", l, r, numOfPrimes[l], numOfPrimes[r], numOfPrimes[r] - numOfPrimes[l - 1]);
    if(l == r) return 0;
    if(l == 0) return numOfPrimes[r - 1];
    return numOfPrimes[r - 1] - numOfPrimes[l - 1];
}