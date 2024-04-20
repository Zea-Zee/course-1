#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 16

typedef struct Label_s{
	char name[16]; //имя автора (заканчивается нулём)
	int age;	   //возраст автора (сколько лет)
} Label;

typedef struct NameStats_s {
	int cntTotal; //сколько всего подписей
	int cntLong; //сколько подписей с именами длиннее 10 букв
} NameStats ;

typedef struct AgeStats_s {
	int cntTotal ; //сколько всего подписей
	int cntAdults ; //сколько подписей взрослых (хотя бы 18 лет)
	int cntKids ; //сколько подписей детей (меньше 14 лет)
} AgeStats ;

int calcStats (const Label * arr, int cnt, NameStats * oNames, AgeStats * oAges){
	//*oNames = {0, 0};
	//*oAges = {0, 0 ,0};
	for(int i = 0; i < cnt; i++){
		oNames->cntTotal += 1;
		if(strlen(arr[i].name) > 10) oNames->cntLong += 1;
		oAges->cntTotal += 1;
		if(arr[i].age >= 18) oAges->cntAdults += 1;
		else if(arr[i].age < 14) oAges->cntKids += 1;
		//printf("ages: %d names:%d\n", arr[i].age, strlen(arr[i].name));
	}
	//printf("%d", oNames->cntTotal);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, age;
	char str[MX] = "\0", cache;
	scanf("%d ", &n);
	Label arr[n];// = {"hui", 0};
	for(int i = 0; i < n; i++){
		int j = 0;
		while (scanf("%c", &cache) == 1 && cache >= 'A' && cache <= 'z' && cache != ' ' && cache != '\n'){
			str[j] = cache;
			j++;
		}
		scanf("%d", &age);
		scanf("%c%c%c%c%c", &cache, &cache, &cache, &cache, &cache);
		Label obj;
		obj.age = age;
		// obj.name = "abcd";
		strcpy(obj.name, str);
		//printf("%s\n", obj.name);
		arr[i] = obj;
		for(int i = 0; i < 16; i++) str[i] = '\0';
	}
	NameStats names;
	names.cntTotal = 0;
	names.cntLong = 0;
	AgeStats ages;// = {0, 0, 0};
	ages.cntTotal = 0;
	ages.cntAdults = 0;
	ages.cntKids = 0;
	calcStats(arr, n, &names, &ages);
	printf("names: total = %d\nnames: long = %d\nages: total = %d\nages: adult = %d\nages: kid = %d\n", names.cntTotal, names.cntLong, ages.cntTotal, ages.cntAdults, ages.cntKids);
}