#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int d, m, y, k;
	int weekArr[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int weekVisArr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int vis = 0;
	scanf("%d %d %d %d", &d, &m, &y, &k);
	//printf("%d %d %d %d\n", D, M, Y, K);


	//FIRST OPERATION
	//printf("%d\n", k - (weekArr[m - 1] - d));
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) vis = 1;
	if (vis) {
		if (k > weekVisArr[m - 1] - d) {
			k -= (weekVisArr[m - 1] - d);
			d = 1;
			if (m < 12) m++;
			else {
				m = 1;
				y++;
			}
//			printf("%s", "bebra1");
		} else{
			d += k;
			k = 0;
		}
	} else {
		if (k > weekArr[m - 1] - d) {
			k -= (weekArr[m - 1] - d);
			d = 1;
			if (m < 12) m++;
			else {
				m = 1;
				y++;
			}
//			printf("%s", "bebra2");
		} else{
			d += k;
			k = 0;
		}
	}

	//CYCLE OPERATIONS
	while (k > 0) {
		//printf("%d\n", k);
		if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) vis = 1;
		else vis = 0;
		if (vis) {
			if (k < weekVisArr[m - 1]) {//Oops
				d = k;
				k = 0;
				break;
			}

			k -= weekVisArr[m - 1]; //Oops
			if (m < 12) m++;
			else {
				m = 1;
				y++;
			}
		} else {
			if (k < weekArr[m - 1]) {//Oops
				d = k;
				k = 0;
				break;
			}

			k -= weekArr[m - 1]; //Oops
			if (m < 12) m++;
			else {
				m = 1;
				y++;
			}
		}
	}

	printf("%d %d %d", d, m, y);
	return 0;
}