#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char cur, last, prl = 'y';
	scanf("%c", &last);
	scanf("%c", &cur);

	while (1) {
		if (cur == '/' && last == '/') {
			while (cur != '\n') {
				last = cur;
				if (scanf("%c", &cur) != 1) goto suck;
			}
			//printf("%c", '\n');
			goto cont;
		}
		if (cur == '*' && last == '/') {
			int flag = 1, cn = 0;
			while (flag) {
				//if (prl == '/' && last == '*' && cur == '/') continue;
				if (cur == '\n') printf("%c", cur);
				if (cur == '/' && last == '*') flag = 0;
				if (cn == 1) flag = 1;
				cn++;
				//prl = last;
				last = cur;
				if (scanf("%c", &cur) != 1) goto suck;
			}
			goto cont;
		}
		printf("%c", last);
		cont:
		last = cur;
		if (scanf("%c", &cur) != 1) {
			printf("%c", last);
			break;
		}
	}
	suck:


	return 0;
}