#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//struct Str
//{
//	char str[8];
//};
//typedef struct Str Str;

typedef int KEY;
typedef double VALUE;

struct val_key
{
	VALUE val;
	KEY key;
	//hash = hashfun(key);
};
typedef struct val_key val_key;

struct Vec
{
	val_key* arr;
	int size;
	int cap;
};
typedef struct Vec Vec;

void Vec_init(Vec* v)
{
	v->cap = 8;
	v->size = 0;
	v->arr = malloc(v->cap * sizeof(val_key));
}

void Vec_push_back(Vec* v, val_key x)
{
	if (v->size + 1 > v->cap)
	{
		v->cap *= 2;
		v->arr = realloc(v->arr, v->cap * sizeof(val_key));
	}
	v->arr[v->size] = x;
	v->size += 1;
}

val_key Vec_pop_back(Vec* v)
{
	v->size -= 1;
	return v->arr[v->size];
}

typedef size_t HASH;
HASH hashfun(KEY v)
{
	size_t i = 0;
	size_t hash = 0;
	while (i != 1) {
		hash += v;
		hash += hash << 10;
		hash ^= hash >> 6;
		i++;
	}
	hash += hash << 3;
	hash ^= hash >> 11;
	hash += hash << 15;
	return hash;
}

#define N 1000
struct HashTable
{
	Vec table[N];
};
typedef struct HashTable HashTable;

void HashTable_init(HashTable* h)
{
	for (size_t i = 0; i < N; i++)
	{
		Vec_init(&(h->table[i]));
	}
}

VALUE NOT_EXIST = -2000000000;	// проверьте что таких значений нет в задачи
VALUE HashTable_get(HashTable* h, KEY key)
{
	HASH hash = hashfun(key);
	size_t index = hash % N;
	Vec* current = &(h->table[index]);
	for (size_t i = 0; i < current->size; i++)
	{
		if (current->arr[i].key == key)
		{
			return current->arr[i].val;
		}
	}
	return NOT_EXIST;
}

void HashTable_add(HashTable* h, val_key v)
{
	HASH hash = hashfun(v.key);
	size_t index = hash % N;
	Vec* current = &(h->table[index]);
	for (size_t i = 0; i < current->size; i++)
	{
		if (current->arr[i].key == v.key)
		{
			// перезаписать значение
			current->arr[i].val = v.val;
		}
	}
	// создать новый
	Vec_push_back(current, v);
}

void HashTable_delete(HashTable* h, KEY key)
{
	HASH hash = hashfun(key);
	size_t index = hash % N;
	Vec* current = &(h->table[index]);
	for (size_t i = 0; i < current->size; i++)
	{
		if (current->arr[i].key == key)
		{
			// перезаписать значение
			current->arr[i].val = NOT_EXIST;
		}
	}
}

int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	FILE* input = fopen("input.bin", "rb");
	FILE* output = fopen("output.bin", "wb");

	HashTable hashtable;
	HashTable_init(&hashtable);
	val_key a, b;
	a.key = 5;
	a.val = 5.5;
	b.key = 3;
	b.val = 3.3;

  int n;
  // scanf("%d", &n);
	fread(&n, sizeof(int), 1, input);
  int arr[n];
  int brr[n];
  int count = 0;
  for(int i = 0; i < n; i++){
    int cache;
    // scanf("%d", &cache);
    fread(&cache, sizeof(int), 1, input);
    val_key c;
    c.key = cache;
    c.val = cache;
    if(HashTable_get(&hashtable, cache) == NOT_EXIST){
      HashTable_add(&hashtable, c);	//вместо arr[a.key] = a.val;
      brr[count] = cache;
      count++;
    }
  }

  // for(int i = 0; i < count; i++) printf("%d\n", brr[i]);
  fwrite(&count, sizeof(int), 1, output);
  fwrite(brr, sizeof(int), count, output);

	// HashTable_add(&hashtable, a);	//вместо arr[a.key] = a.val;
	// VALUE x = HashTable_get(&hashtable, 5); //вместо x = arr[a.key];

	// assert(HashTable_get(&hashtable, 5) == 5.5);
	// assert(HashTable_get(&hashtable, 3) == NOT_EXIST);

	// HashTable_add(&hashtable, b);
	// assert(HashTable_get(&hashtable, 3) == 3.3);

	// HashTable_delete(&hashtable, 3);
	// assert(HashTable_get(&hashtable, 3) == NOT_EXIST);

	return 0;
}