#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MX 127

typedef struct DateTime_s {
	int year, month, day, hours, minutes, seconds;
} DateTime;

DateTime mini (const DateTime *arr, int cnt){
	DateTime min = arr[cnt - 1];
	for(int i = cnt - 2; i >= 0; i--){
		DateTime cur = arr[i];
		if(min.year < cur.year) continue;
		else if (min.year > cur.year){
			min = cur;
			continue;
		}
		if(min.month < cur.month) continue;
		else if(min.month > cur.month){
			min = cur;
			continue;
		}
		if(min.day < cur.day) continue;
		else if(min.day > cur.day){
			min = cur;
			continue;
		}
		if(min.hours < cur.hours) continue;
		else if(min.hours > cur.hours){
			min = cur;
			continue;
		}
		if(min.minutes < cur.minutes) continue;
		else if(min.minutes > cur.minutes){
			min = cur;
			continue;
		}
		if(min.seconds < cur.seconds) continue;
		else if(min.seconds > cur.seconds){
			min = cur;
			continue;
		}
	}
	return min;
}


int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, y, m, d, h, minutes, s;
	scanf("%d", &n);
	DateTime arr[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d %d %d %d %d", &y, &m, &d, &h, &minutes, &s);
		DateTime obj = {y, m, d, h, minutes, s};
		arr[i] = obj;
	}
	DateTime res = mini(arr, n);
	printf("%d %d %d %d %d %d", res.year, res.month, res.day, res.hours, res.minutes, res.seconds);
	return 0;
}