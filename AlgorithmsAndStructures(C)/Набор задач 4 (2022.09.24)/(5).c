#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 1000000

int fuckNSUts(short yesOrNo){
  	char cache = '/', str[MX];
	int len, upCount, i, flag = 0;

	while(scanf("%c", &cache) == 1 && cache != '\n'){	//Вывод полученного слова если наткнулся на .,;:
		if((cache == '.' || cache == ',' || cache == ';' || cache == ':' || cache == ' ') && flag == 1){
			flag = 0;
      if(i > 0){
        			printf("%d/%d ", upCount, i);
			for(int j = 0; j < i; j++){
				printf("%c", str[j]);
			}
			printf("\n");
			i = 0;
			len = 0;
			upCount = 0;
      }
		} else if(cache != '.' && cache != ',' && cache != ';' && cache != ':' && cache != ' '){//Добавление символа к слову
			flag = 1;
			str[i] = cache;
			i++;
			if(cache >= 'A' && cache <= 'Z') upCount++;
		}
	}
	if(flag == 1){
		printf("%d/%d ", upCount, i);
		for(int j = 0; j < i; j++){
			printf("%c", str[j]);
		}
	}
	printf("\n");
  return 0;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
  fuckNSUts(1);
	return 0;
}