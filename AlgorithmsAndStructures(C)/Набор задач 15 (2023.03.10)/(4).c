#include <stdio.h>
#include <math.h>

double c1[4];
double xt(double x, double l);
double c2[4];
double yt(double y, double l);
double c3[4];
double zt(double z, double l);
//double computePolynom(double l, double z, double *c){
//    return c[1] + (c[2] * (z - l) * 2) + (c[3] * (z - l) * (z - l) * 3);
//}

double funct(double t, double l);

int main() {
 freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
 int N;
 double l, r;
 scanf("%d", &N);

 double sum = 0;
 for (int i = 0; i < N; i++) {
     scanf("%lf %lf %lf %lf %lf %lf", &l, &r, &c1[0], &c1[1], &c1[2], &c1[3]);
     double tmpSum = 0;
  scanf("%lf %lf %lf %lf", &c2[0], &c2[1], &c2[2], &c2[3]);
     double step = 10000;
  scanf("%lf %lf %lf %lf", &c3[0], &c3[1], &c3[2], &c3[3]);
  double dx = (r - l) / step;
  for (int i = 1; i <= step; i += 2) {
   tmpSum += funct(l + i * dx, l) * 4;
   tmpSum += funct(l + (i + 1) * dx, l) * 2;
  }
  sum += (dx/3)*(funct(l, l)+tmpSum - funct(r, l));
 }
 printf("%0.20lf", sum);
 return 0;
}

double xt(double x, double l) {
    return c1[1] + (c1[2] * (x - l) * 2) + (c1[3] * (x - l) * (x - l) * 3);
}
double yt(double y, double l) {
    return c2[1] + (c2[2] * (y - l) * 2) + (c2[3] * (y - l) * (y - l) * 3);
}
double zt(double z, double l) {
    return c3[1] + (c3[2] * (z - l) * 2) + (c3[3] * (z - l) * (z - l) * 3);
}

double funct(double t, double l) {
    return sqrt(pow(xt(t, l), 2) + pow(yt(t, l), 2) + pow(zt(t, l), 2));
//    return sqrt(computePolynom(l, ) * xt(t) + yt(t) * yt(t) + zt(t) * zt(t));
}