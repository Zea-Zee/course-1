#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int f1, p1, j1, f2, p2, j2, j;
	scanf("%d %d %d %d %d", &f1, &f2, &p2, &j2, &j);
//  printf("%d\n", 52 % (j * (p2 - 1) + j2));
	while (f2 % (j * (p2 - 1) + j2) != 0) ++f2;
	int n = f2 / (j * (p2 - 1) + j2);
	int SB;
  if(f1 % n == 0) SB = f1 / n;
  else SB = f1 / n + 1;
	if(SB % j == 0) p2 = SB / j;
  else p2 = SB / j + 1;
	j2 = SB - (p2 - 1) * j;
//  printf("%d\n", p2);

	printf("%d %d", p2, j2);

	return 0;
}