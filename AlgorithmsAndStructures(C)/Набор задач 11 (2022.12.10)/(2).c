#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Elem_s{
    int value;
    struct Elem_s *next;
} Elem;

typedef struct{
    int len;
    Elem *first;
    Elem *last;
} List;

void addElem(List *list, int value){
    Elem *tmp = (Elem*) malloc(sizeof(Elem));
    tmp->value = value;
    list->last->value = value;
    list->last->next = tmp;
    list->last = tmp;
    list->len++;
    // new.value = value;
    // list.len++;
    // list.last = (Elem*) malloc(sizeof(Elem));
}

void showList(Elem *el, int counter, int len){
    if(counter == len) return;
    Elem element = *el;
    printf("%d\n", element.value);
    // Elem tmp = *(el.next);
    showList(element.next, counter + 1, len);
}
typedef void (*callback)(int *sum, int*val);

void isEven(int *sum, int* val){
    if(*val % 2 == 0){
        int tmp = *val;
        *sum = *sum + tmp;
        // printf("%d:\n", *val);
    }
};
callback isEvenButStupid = isEven;
void arrayForeach (int *sum, callback func, int * arr , int n ){
    for(int i = 0; i < n; i++) func(sum, &(arr[i]));
    return;
}

void listForeach (int *sum, callback func, Elem *elem, List list){
    if(list.len == 0) return;
    func(sum, &(elem->value));
    list.len--;
    listForeach(sum, func, elem->next, list);
}

int main(){
    Elem first;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int arr[n];
    int tmp;
    scanf("%d", &tmp);
    arr[0] = tmp;
    first.value = tmp;

    List list;
    list.len = 0;
    Elem last;
    // last.value = 10;
    list.first = &first;
    list.last = &last;
    (list.first)->next = list.last;
    list.len++;

    for(int i = 1; i < n; i++){
        scanf("%d", &tmp);
        arr[i] = tmp;
        addElem(&list, tmp);
    }

    int sum = 0;
    arrayForeach(&sum, isEvenButStupid, arr, n);
    printf("%d ", sum);
    sum = 0;
    listForeach(&sum, isEvenButStupid, list.first, list);
    printf("%d", sum);
    // showList(list.first, 0, list.len);
    return 0;
}



// typedef struct Elem_s{
//     int value;
//     struct Elem_s *next;
// } Elem;

// typedef struct{
//     int len;
//     Elem *first;
//     // Elem *last;
// } List;

// void addElem(List *list, Elem *el, int value){
//     Elem tmp;
//     tmp.value = value;
//     el->next = &tmp;
//     list->len++;
//     // new.value = value;
//     // list.len++;
//     // list.last = (Elem*) malloc(sizeof(Elem));
// }

// void showList(Elem *el, int counter, int len){
//     if(counter == len) return;
//     Elem element = *el;
//     printf("%d\n", element.value);
//     // Elem tmp = *(el.next);
//     showList(element.next, counter + 1, len);
// }

// int main(){
//     List list;
//     list.len = 0;
//     Elem first;
//     first.value = 1;
//     // Elem last;
//     // last.value = 10;
//     list.first = &first;
//     // list.last = &last;
//     // (list.first)->next = list.last;
//     list.len++;

//     addElem(&list, list.first, 2);
//     addElem(&list, 3);
//     // addElem(&list, 4);

//     showList((list.first), 0, list.len);
//     // a.first = cache;
//     return 0;
// }