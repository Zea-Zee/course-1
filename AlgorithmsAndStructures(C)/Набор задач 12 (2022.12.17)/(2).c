#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rightNode tree[2 * start + 2]

typedef struct tnode_s
{
    struct tnode_s *left;
	long long count;
    struct tnode_s *right;
	unsigned long long field;
} tnode;

tnode shuffle(int *arr, int i, int j, int *array, int n){
	int tmp = arr[i];
	tnode root;
	if (n > 1){
        for (int i = 0; i < n - 1; i++){
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    } else arr[i] = arr[j];
	arr[j] = tmp;
	return root;
}

tnode searchRight(int *tree, int start, int k){
	tnode ans;
	if(start >= k) return ans;
	if(k == 2){
		if(tree[0] < tree[1]) return ans;
		else{
			shuffle(tree, 0, 1, tree, 1);
			return ans;
		}
	}
	if(tree[2 * start + 2] <= tree[2 * start + 1] && tree[start] > tree[2 * start + 2] && start * 2 + 2 < k){
		shuffle(tree, start * 2 + 2, start, tree, 1);
		searchRight(tree, start * 2 + 2, k);
	}else if(tree[2 * start + 1] < tree[2 * start + 2] && tree[start] > tree[2 * start + 1] && start * 2 + 1 < k){
		shuffle(tree, start * 2 + 1, start, tree, 1);
		searchRight(tree, start * 2 + 1, k);
	}
	return ans;
}

int getTreeElem(int *tree, int k){
	int res = tree[0];
	shuffle(tree, 0, k - 1, tree, 1);
	k--;
	searchRight(tree, 0, k);
	return res;
}

tnode searchLeft(int *tree, int start){
	int st = tree[start];
	int stM = tree[(start - 1) / 2];
	tnode ans;
	while(tree[start] < tree[(start - 1) / 2] && (start - 1) / 2 >= 0){
		shuffle(tree, start, (start - 1) / 2, tree, 1);
    	start = (int)((start - 1) / 2);
	}
	return ans;
}

tnode makeNewRoot(int *tree, int el, int k){
	tnode root;
	root.left = NULL;
	root.right = NULL;
	root.count = 1;
	tree[k - 1] = el;
	searchLeft(tree, k - 1);
}

int main(){
	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");
	int n;
	fread(&n, sizeof(int), 1, input);
	int *tree = (int*) calloc(n + 1000000,sizeof(int));
	int *controlTree = (int*) calloc(n + 1000000,sizeof(int));
	int k = 0;
	for(int i = 0; i < n; i++){
		int cache;
		fread(&cache, sizeof(int), 1, input);
		k++;
		makeNewRoot(tree, cache, k);
	}
	for(int i = k; i > 0; i--){
		int cache = getTreeElem(tree, i);
		fwrite(&cache, sizeof(int), 1, output);
	}
	return 0;
}