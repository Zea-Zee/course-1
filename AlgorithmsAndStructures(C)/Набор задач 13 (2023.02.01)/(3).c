#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	char str[10001];
	gets(str);
	// printf("%s", str);
	char cache[10000];
	cache[0] = '[';
	int i = 0;
	int j = 1;
	while(str[i] != '\000' && i < 101){
		char symb = str[i];
		if(str[i] == '\"'){
			i++;
			while(str[i] != '\"'){
				cache[j] = str[i];
				i++;
				j++;
			}
			i++;
			cache[j] = ']';
			j = 1;
			printf("%s\n", cache);
			memset(cache, '\0', 100);
			cache[0] = '[';
		} else if(str[i] != ' '){
			cache[j] = str[i];
			i++;
			j++;
			if(str[i] == ' ' || str[i] == '\000'){
				cache[j] = ']';
				j = 1;
				printf("%s\n", cache);
				memset(cache, '\0', 100);
				cache[0] = '[';
			}
		} else i++;
	}
	return 0;
}