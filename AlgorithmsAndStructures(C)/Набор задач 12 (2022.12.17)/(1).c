#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *arr, int i, int j){
	int tmp = arr[i];
	// int tmp2 = arr[j];
	arr[i] = arr[j];
	arr[j] = tmp;
}

// void addElem(int *tree, int k, int elem){
// 	tree[k++] = elem;
// 	shiftUp(k - 1);
// }

int siftDown(int *tree, int start, int k){
	// printf("stInd/%d stEl/%d\n", start, tree[start]);
	if(start >= k) return 0;
	if(k == 2){
		if(tree[0] < tree[1]) return 0;
		else{
			swap(tree, 0, 1);
			return 0;
		}
	}
	if(tree[2 * start + 2] <= tree[2 * start + 1] && tree[start] > tree[2 * start + 2] && start * 2 + 2 < k){
		swap(tree, start * 2 + 2, start);
		// int debug[2] = {tree[start], tree[start * 2 + 1]};
		// printf("/ELSE/start index:%d start elem:%d start2 index:%d start2 elem: %d\n", start, start * 2 + 1, tree[start, tree[start * 2 + 1]]);
		siftDown(tree, start * 2 + 2, k);
	}else if(tree[2 * start + 1] < tree[2 * start + 2] && tree[start] > tree[2 * start + 1] && start * 2 + 1 < k){
		swap(tree, start * 2 + 1, start);
		// int debug[2] = {tree[start], tree[start * 2 + 1]};
		// printf("/ELSE/start index:%d start elem:%d start2 index:%d start2 elem: %d\n", start, start * 2 + 1, tree[start, tree[start * 2 + 1]]);
		siftDown(tree, start * 2 + 1, k);
	}
	// printf("/END/start index:%d start elem:%d start2 index:%d start2 elem: %d\n", tree[start, tree[start * 2 + 2]]);
	// siftDown(tree, start, k);
	return 0;
}

int extractMin(int *tree, int k){
	// if(k == 2){
	// 	if(tree[1] < tree[0]){
	// 		// swap(tree, 1, 0);
	// 		return tree[1];
	// 	} else{
	// 		int tmp = tree[0];
	// 		tree[0] = tree[1];
	// 		return tmp;
	// 	}
	// }
	// if(k == 1) return tree[0];
	int res = tree[0];
	swap(tree, 0, k - 1);
	k--;
	// tree[k] = -1;
	siftDown(tree, 0, k);
	return res;
}

int siftUp(int *tree, int start){
	int st = tree[start];
	int stM = tree[(start - 1) / 2];
	while(tree[start] < tree[(start - 1) / 2] && (start - 1) / 2 >= 0){
		swap(tree, start, (start - 1) / 2);
    	start = (int)((start - 1) / 2);
	}
	// if(*tree)
	return 0;
}

void add(int *tree, int el, int k){
	tree[k - 1] = el;
	siftUp(tree, k - 1);
}

int main(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");
	int n;
	// scanf("%d", &n);
	fread(&n, sizeof(int), 1, input);
	int *tree = (int*) calloc(n + 1000000,sizeof(int));//[n];// = {3, 6, 4, 9, 8, 12, 7, 11, 9};
	// for(int i = 0; i < n; i++) tree[i] = (int)pow(2, 31) - 1;
	int k = 0;
	// int i = 9;
	for(int i = 0; i < n; i++){
		k++;
		int cache;
		// scanf("%d", &cache);
		fread(&cache, sizeof(int), 1, input);
		add(tree, cache, k);
	}

	for(int i = k; i > 0; i--){
		int cache = extractMin(tree, i);
		fwrite(&cache, sizeof(int), 1, output);
		// printf("%d\n", cache);
	}
	// if(tree[0] > tree[1]){
	// 	printf("%d\n", tree[1]);
	// 	printf("%d\n", tree[0]);
	// 	fwrite(&(tree[1]), 4, 1, output);
	// 	fwrite(&(tree[0]), 4, 1, output);
	// } else{
	// 	printf("%d\n", tree[0]);
	// 	printf("%d\n", tree[1]);
	// 	fwrite(&(tree[0]), 4, 1, output);
	// 	fwrite(&(tree[1]), 4, 1, output);
	// }
	return 0;
}