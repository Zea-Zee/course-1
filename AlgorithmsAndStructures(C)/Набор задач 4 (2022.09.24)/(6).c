	#define _CRT_SECURE_NO_WARNINGS
	#include <stdlib.h>
	#include <stdio.h>
	#include <math.h>
	#include <string.h>
	#define MX 20

	int readTime (char * iStr , int * oHours , int * oMinutes , int * oSeconds){
		if(strlen(iStr) > 9){
			*oHours = -1;
			*oMinutes = -1;
			*oSeconds = -1;
			return 0;
		}
		for(int i = 0; i < strlen(iStr); i++){
			if(iStr[i] == '|'){
			*oHours = -1;
			*oMinutes = -1;
			*oSeconds = -1;
			return 0;
			}
		}
		//printf("SDf");
		int numCache = 1000, parts = 0;
		for(int i = strlen(iStr) - 1; i >= 0; i--) if(iStr[i] == ':') parts++;
		for(int i = strlen(iStr) - 1; i >= 0; i--){
			if(iStr[i] == ':'){
				if(parts >= 2) *oSeconds = numCache;
				else if(parts >= 1) *oMinutes = numCache;
				numCache = 1000;
				parts--;
				//printf("%d\n", *oSeconds);
			}else{
				if(numCache != 1000) numCache += 10 * (iStr[i] - '0');
				else numCache = (iStr[i] - '0');
			}
		}
		*oHours = numCache;
		if(*oHours > 23 || *oMinutes > 59 || *oSeconds > 59){
			*oHours = -1;
			*oMinutes = -1;
			*oSeconds = -1;
			return 0;
		}
		return 1;
	}

	int main(){
		//FILE * input = fopen("input.txt", "r");
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		int h = 0, m = 0, s = 0;
		char str[MX] = {'\0'}, n;
		memset(str, '\0', MX);
		for(int i = 0; i < 20; i++){
			if(scanf("%c", &n) == 1){
				if(n == ' ' || n == '\n'){
					str[i] = '\0';
					break;
			}
			else str[i] = n;
			}
		}//printf("%d\n", strlen(str));
		int res = readTime(str, &h, &m, &s);
		printf("%d %d %d %d\n", res, h, m, s);
		printf("%d %d %d\n", res, h, m);
		printf("%d %d", res, h);
		//printf("%d %d %d %d", strlen(str), h, m, s);
		return 0;
	}