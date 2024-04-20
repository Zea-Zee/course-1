#include <stdlib.h>
#include <stdio.h>
#include <math.h>
unsigned long long facs[21] = {1,1,2,6,24,120,720,5040, 40320, 362880, 3628800, 39916800, 479001600,6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000, 2432902008176640000};
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    double arr[n];
    for(int i = 0; i < 500000000; i++) 1;
    for(int i = 0; i < n; i++) scanf("%lf", &(arr[i]));
    for(int i = 0; i < n; i++){
        double angle = arr[i];
        double res = angle - pow(angle, 3) / (facs[3]) + pow(angle, 5) / (facs[5]) - pow(angle, 7) / (facs[7]) + pow(angle, 9) / (facs[9]) - pow(angle, 11) / (facs[11]) + pow(angle, 13) / (facs[13]) - pow(angle, 15) / (facs[15]) + pow(angle, 17) / (facs[17]) - pow(angle, 19) / (facs[19]);
        printf("%0.15lf\n", res);
    }
    return 0;
}



    // time_t start = clock();
    // pow(2, 1000);
    // for(int i = 0; i < 10000000; i++) pow(13, 18);
    // time_t end = clock();
    // printf("%lf ms", double(double(end - start) / CLOCKS_PER_SEC) * 1000);