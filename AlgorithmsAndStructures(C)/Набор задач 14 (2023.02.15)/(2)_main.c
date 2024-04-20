#include "modular.h" //в этом хедере должны быть объявления
#include <assert.h>
int main()
{
    MOD = 13; //устанавливаем глобальный модуль
    int a = 45;
    a = pnorm (a );
    assert ( a == 6);
    assert(pnorm(-1) == 12);
//    assert(padd(-1, -2) == 10);
//    assert(padd(20, 30) == 11);
    assert(padd(10, 10) == 7);
    assert(psub(1, 2) == 12);
    int x = pmul ( padd (7 , psub (2 , 3)) , 5);
    assert ( x == 4);
    int y = pdiv (7 , x );
    assert ( pmul (x , y) == 7);
    MOD = 2; //меняем модуль на другой
    assert ( pnorm (5) == 1);
    MOD = 2147483647;
//    assert(pmul(2147483646, 2147483646) == 1);
    assert(pdiv(2147483646, 2147483646) == 1);
    MOD = 2;
    assert(pnorm(-944789451) == 1);
    return 0;
//    return 0;
}