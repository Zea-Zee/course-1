#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 100000

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int m, n, gor, vert, flag = 1, flag2 = 1, flag3 = 1, check[MX], check2[MX];
	scanf("%d %d", &m, &n);
	int x[n], y[m];
	for(int l = 0; l < MX; l++) check[l] = 0;
	for(int k = 0; k < MX; k++) check2[k] = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &gor, &vert);
		y[i] = vert;
		check2[vert] = check2[vert] + 1;
		x[i] = gor;
		check[gor] = check[gor] + 1;
	}
	for (int i = 0; i < MX; i++) if (check[i] > 1) flag = 0;
	if (flag) printf("1 ");
	else{
		printf("0 ");
		return 0;
	}
	for (int i = 0; i < MX; i++) if (check2[i] > 1) flag3 = 0;
	if (n == m) printf("2 ");
	if (flag3) printf("3 ");
	if (flag3 && n == m) printf("4 5");
	printf(" \n");
	fclose(stdin);
	fclose(stdout);
	return 0;//
}