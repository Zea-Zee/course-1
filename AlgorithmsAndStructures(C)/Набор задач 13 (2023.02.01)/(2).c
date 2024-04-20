#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int n;
void print2Matrice(double arr[n][n + 1], int n);

double swap(double arr[n][n + 1], int x, int y, int n){
    double tmp[n];
    memcpy(tmp, arr[x], sizeof(double) * n);
    memcpy(arr[x], arr[y], sizeof(double) * n);
    memcpy(arr[y], tmp, sizeof(double) * n);
    return 0;
}

double straight(double arr[n][n + 1], int start, int n){
//    printf("DELETE:\n");
    for(int i = start + 1; i < n; i++){
        double k = arr[i][start] / arr[start][start] * (-1);
//        printf("KOEF: %lf\n", k);
        for(int j = start; j <= n; j++){//MAY BE J = 0
//            printf("%lf ", arr[i][j]);
            arr[i][j] = arr[start][j] * k + arr[i][j];
//            printf("%lf\n", arr[i][j]);
        }
//        print2Matrice(arr, n);
    }
}

double back(double arr[n][n + 1], int end, int n){
    double xs[n];
    for(int i = n - 1; i >= 0; i--){
//        for(int j = n - 1; j >= 0; j--){
//            if(j == i){
//                double sum = 0;
//                for(int l = j + 1; l <= n; l++){
//                    sum += arr[i][l] * xs[l];
//                }
//                xs[j] = -1 * sum + arr[i][n];
//                printf("%lf\n", xs[j]);
//            }
//        }
        int j = i;
        double sum = 0;
        for(int l = j + 1; l < n; l++){
            sum += arr[i][l] * xs[l];
        }
        xs[j] = (-1 * sum + arr[i][n]) / arr[i][j];
//                printf("i: %d j: %d sum: %lf b: %lf x: %lf\n", i, j, sum, arr[i][n], xs[j]);
    }
    for(int i = 0; i < n; i++){printf("%.10lf\n", xs[i]);}
}

void print2Matrice(double arr[n][n + 1], int n){
    printf("___MATRICE WILL BE DOWN___\n");
    for(int i = 0; i < n; i++){//fill extended matrix
        for(int j = 0; j < n; j++){printf("%lf ", arr[i][j]);}
        printf("%lf\n", arr[i][n]);
    }
}

long long binpow(long long a, long long n, long long m){
    long long res = 1;
    while (n)
        if (n & 1) {
            res *= a;
            res = res % m;
            n--;
        }
        else {
            a *= a;
            n >>= 1;
            a = a % m;
        }
    return res;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    long long m;
    scanf("%d %lld", &n, &m);
    for(int i = 0; i < n; i++){
        long long a;
        scanf("%lld", &a);
        long long res = binpow(a, m - 2, m);
//        if(res > m){
//            res = res % m;
//        }
//        res = fabs(res);
        if(res >= m || res <= 0 || (a * res) % m != 1) res = -1;
        printf("%lld\n", res);
    }
    return 0;
}