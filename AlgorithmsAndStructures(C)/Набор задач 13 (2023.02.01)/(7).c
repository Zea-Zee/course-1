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

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
//	int n;
    scanf("%d", &n);
    double arr[n][n + 1];

    for(int i = 0; i < n; i++){//fill extended matrix
        for(int j = 0; j < n; j++){
            scanf("%lf", &(arr[i][j]));
//            printf("%lf ", arr[i][j]);
        }
        scanf("%lf", &(arr[i][n]));
//        printf("%lf\n", arr[i][n]);
    }

    for(int i = 0; i < n; i++){
        if(arr[i][i] == 0){
            for(int l = i + 1; l < n; l++){
                if(arr[l][i] != 0){
                    swap(arr, i, l, n + 1);
                    swap(arr, l, n - 1, n + 1);
                }
            }
            i--;
//            printf("SWAPED:\n");
//            print2Matrice(arr, n);
            continue;
        }
        straight(arr, i, n);
//        back(arr, 0, n);
    }
    back(arr, 0, n);
//    printf("BEBRA?");
//    print2Matrice(arr, n);
//    printf("BEBRA?");

   
}