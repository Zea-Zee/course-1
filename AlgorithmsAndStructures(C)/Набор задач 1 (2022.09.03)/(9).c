#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    int maxV, sqrt3;
    long long count = 0;
    fscanf(input, "%d", &maxV);
    sqrt3 = pow(maxV, (double)1 / 3);
    int sqrt2 = sqrt(maxV);
    for (int a = 1; a <= sqrt3 + 1; a++)
    {
        for (int b = a; b <= sqrt2; b++)
        {
            /*fprintf(output, "%d %d %d\n", maxV / (a * b), 1, (int)(maxV / (a * b)) - b + 1);*/
            int cc = (int)(maxV / (a * b)) - b + 1;
            if (cc > 0)
                count += cc;
        }
    }

    fprintf(output, "%lld", count);
    return 0;
}

//
// int main() {
//	FILE* input = fopen("input.txt", "r");
//	FILE* output = fopen("output.txt", "w");
//
//	int f1, f2, p2, j2, j; //100ая квартира 50ая квартира подезь
//	fscanf(input, "%d %d %d %d %d", &f1, &f2, &p2, &j2, &j);
//
//	int FpB = ceil((double)f2 / (j2 + (j * (p2 - 1)))); //Количество квартир на лестничной площадке
//	int css = ceil((double)f1 / FpB); //На какой площадке по счету
//	int p1 = 1 + floor((double)css / j); //В каком подъезде
//	int j1 = css % j; //На каком этаже
//
//
//
//	fprintf(output, "%d %d", p1, j1);
//}
//
//
//
//
//
//
//
////int n, minus = 0, plus = 0, zero = 0, cache;
////fscanf(input, "%d", &n);
//
////for (int i = 0; i < n; i++) {
////	fscanf(input, "%d", &cache);
////	if (cache < 0) minus++;
////	else if (cache == 0) zero++;
////	else plus++;
////}
////fprintf(output, "%0.5lf %0.5lf %0.5lf", (double)minus / n, (double)zero / n, (double)plus / n);

// int main()
//{
//     FILE* insert;
//     int N, P, K, pl, et;
//     FILE* outist;
//     insert = fopen("input.txt", "r");
//     outist = fopen("output.txt", "w");
//     int lad, map;
//     pl = 1;
//     fscanf(insert, "%d %d %d %d %d", &N, &map, &P, &K, &lad);
//     int i = map / ((P - 1) * lad + (K - 1));
//     while (N - i * lad * (pl - 1) > i * lad) pl++;
//     if ((N - i * lad * (pl - 1)) % i == 0) et = (N - i * lad * (pl - 1)) / i;
//     else et = (N - i * lad * (pl - 1)) / i + 1;
//     fprintf(outist, "%d %d", pl, et);
//     return 0;
// }