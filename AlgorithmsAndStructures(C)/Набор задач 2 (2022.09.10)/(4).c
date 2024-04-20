#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int w1, h1, w2, h2, w3, h3;
	scanf("%d %d %d %d %d %d", &w1, &h1, &w2, &h2, &w3, &h3);


//	printf("%d %d %d ", h2 <= w1, h3 <= w1, (w2 + w3) <= h1);
//	printf("%d %d %d %d %d %d ", w1, h1, w2, h2, w3, h3);
	if (w1 == 0 || h1 == 0) {
		printf("%3s", "NO");
		return 0;
	}

	if (h2 <= h1 && (w2 + h3) <= w1 && w3 <= h1) {
		printf("%3s", "YES");
		return 0;
	}
	else if (h2 <= h1 && h3 <= h1 && (w2 + w3) <= w1) {
		printf("%3s", "YES");
		return 0;
	}
	else if (h2 <= w1 && h3 <= w1 && (w2 + w3) <= h1) {
		printf("%3s", "YES");
		return 0;
	} 
	else if (w2 <= h1 && h3 <= h1 && (h2 + w3) <= w1) {
		printf("%3s", "YES");
		return 0;
	}
	else if (w2 <= w1 && w3 <= w1 && (h2 + h3) <= h1) {
		printf("%3s", "YES");
		return 0;
	}
	else {
		int ch = w1, cw = h1;
		h1 = ch;
		w1 = cw;
		if (h2 <= h1 && (w2 + h3) <= w1 && w3 <= h1) {
			printf("%3s", "YES");
			return 0;
		}
		else if (h2 <= h1 && h3 <= h1 && (w2 + w3) <= w1) {
			printf("%3s", "YES");
			return 0;
		}
		else if (h2 <= w1 && h3 <= w1 && (w2 + w3) <= h1) {
			printf("%3s", "YES");
			return 0;
		}
		else if (w2 <= h1 && h3 <= h1 && (h2 + w3) <= w1) {
			printf("%3s", "YES");
			return 0;
		}
		else if (w2 <= w1 && w3 <= w1 && (h2 + h3) <= h1) {
			printf("%3s", "YES");
			return 0;
		}
	}
	
	
	
	
	printf("%2s", "NO");
	return 0;
}