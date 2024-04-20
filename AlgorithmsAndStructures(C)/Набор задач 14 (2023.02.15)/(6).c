#include <stdio.h>
//#define EPS 0.000000001
//#include "func.c"

//#include <assert.h>
//#include <string.h>
//#include <stdlib.h>

double Function ( double x);

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    double EPS = 0.00000001;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        double x;
        scanf("%lf\n", &x);
        if(x >= 1 - EPS){
            double yDiff = Function(x) - Function(x - EPS);
            double diff = yDiff / (double)EPS;
            printf("%0.15lf\n", diff);
            continue;
        }
//        double y = Function(x);
//        double yEps = Function(x + 0.00000001);
        double yDiff = Function(x + EPS) - Function(x);
        double diff = yDiff / (double)EPS;
        printf("%0.15lf\n", diff);
    }
    return 0;
}