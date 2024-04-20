#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 100001

typedef struct Elems{
	double value;
	int next;
} Elem;

int cLog(const Elem *list, int pointer){
	if(pointer == -1) return 0;
	printf("%3.3lf\n", list[pointer].value);
	cLog(list, list[pointer].next);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int pointer = 0, n = 0;
	Elem list[MX];
	scanf("%d %d", &n, &pointer);
	for (int i = 0; i < n; i++){
		Elem el;
		scanf("%lf %d", &el.value, &el.next);
		list[i] = el;
	}
	cLog(list, pointer);
	return 0;
}