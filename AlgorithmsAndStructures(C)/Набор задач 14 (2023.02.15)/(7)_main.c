#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include "primes.h"

int main () {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    assert(isPrime(20) == 0);
    assert(isPrime(0) == 0);
    assert(isPrime(1) == 0);
    assert(isPrime(2) == 1);
    assert(isPrime(3989) == 1);
    assert(isPrime(9999991) == 1);
    assert(isPrime(9999990) == 0);
    assert(isPrime(10000000)==0);

    assert(findNextPrime(0) == 2);
    assert(findNextPrime(7) == 7);
    assert(findNextPrime(6) == 7);
    assert(findNextPrime(12) == 13);
    assert(findNextPrime(14) == 17);
    assert(findNextPrime(9999991) == 9999991);
    assert(findNextPrime(10000000) == 10000019);

    assert(getPrimesCount(2, 3) == 1);
    assert(getPrimesCount(2, 9999991) == 664578);
    assert(getPrimesCount(0, 9999992) == 664579);
    assert(getPrimesCount(10000000, 10000000) == 0);
    assert(getPrimesCount(9999991, 9999991) == 0);
    assert(getPrimesCount(2, 11) == 4);
    assert(getPrimesCount(2, 12) == 5);
    assert(getPrimesCount(3, 12) == 4);

    assert(getPrimesCount(4, 12) == 3);
    assert(getPrimesCount(4, 11) == 2);
    assert(getPrimesCount(4, 10) == 2);

    assert(getPrimesCount(4, 4) == 0);
    assert(getPrimesCount(0, 0) == 0);
    assert(getPrimesCount(1, 1) == 0);
    assert(getPrimesCount(1218, 1222) == 0);
    assert(getPrimesCount(1218, 1223) == 0);
    assert(getPrimesCount(1218, 1224) == 1);
    assert(getPrimesCount(1218, 1225) == 1);

    assert(getPrimesCount(0,10000000)==664579);
    assert(getPrimesCount(0,9999992)==664579);
//    assert(getPrimesCount(0,9999991)==664578);






    assert(isPrime(20) == 0);
    assert(isPrime(0) == 0);
    assert(isPrime(1) == 0);
    assert(isPrime(2) == 1);
    assert(isPrime(3989) == 1);
    assert(isPrime(9999991) == 1);
    assert(isPrime(9999990) == 0);
    assert(isPrime(10000000)==0);

    assert(findNextPrime(0) == 2);
    assert(findNextPrime(7) == 7);
    assert(findNextPrime(6) == 7);
    assert(findNextPrime(12) == 13);
    assert(findNextPrime(14) == 17);
    assert(findNextPrime(9999991) == 9999991);
    assert(findNextPrime(10000000) == 10000019);

    assert(getPrimesCount(2, 3) == 1);
    assert(getPrimesCount(2, 9999991) == 664578);
    assert(getPrimesCount(0, 9999991) == 664578);
    assert(getPrimesCount(10000000, 10000000) == 0);
    assert(getPrimesCount(9999991, 9999991) == 0);
    assert(getPrimesCount(2, 11) == 4);
    assert(getPrimesCount(2, 12) == 5);
    assert(getPrimesCount(3, 12) == 4);

    assert(getPrimesCount(4, 12) == 3);
    assert(getPrimesCount(4, 11) == 2);
    assert(getPrimesCount(4, 10) == 2);

    assert(getPrimesCount(4, 4) == 0);
    assert(getPrimesCount(0, 0) == 0);
    assert(getPrimesCount(1, 1) == 0);
    assert(getPrimesCount(1218, 1222) == 0);
    assert(getPrimesCount(1218, 1223) == 0);
    assert(getPrimesCount(1218, 1224) == 1);
    assert(getPrimesCount(1218, 1225) == 1);

    assert(getPrimesCount(0,10000000)==664579);

    return 0;
}