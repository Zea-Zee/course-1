//#include "main.c"
typedef struct Factors {
    int k ; //сколько различных простых в разложении
    int primes [32]; //различные простые в порядке возрастания
    int powers [32]; //в какие степени надо эти простые возводить
} Factors ;

void Factorize ( int X , Factors * res ){
    int i = 2;
    int k = 0;
    res->primes[k] = 0;
    res->powers[k] = 0;
//    long long tmp = (long long) i * i;
    while(i*i <= X){
        if(i == 1) break;
        while((X % i == 0) && i != 1){
            X /= i;
            res->primes[k] = i;
            res->powers[k]++;
        }
        if(res->powers[k]){
//            j++;
                k++;
//            res->k = res->k + 1;
//            i = 1;
//            res->primes[k] = 0;
//            res->powers[k] = 0;
        }
        i++;
//        tmp = (long long) i * i;
    }
//    if(res->primes[0] == 0){
//        res->primes[0] = X;
//        res->powers[0] = 1;
//    }
//    if(X == 1 && k == 0){
//        res->k = 1;
//        res->primes[k] = 1;
//        res->powers[k] = 0;
//    }
    if(X > 1){
        res->k = k + 1;
        res->primes[k] = X;
        res->powers[k] = 1;
    } else{ res->k = k;}
}