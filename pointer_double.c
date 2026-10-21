#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 10;
    int *pA = &a;
    int **ppA = &pA;

    printf("Value of a: %i\n", a);
    printf("Pointer of a: %p\n", pA);
    printf("Pointer of a: %p\n", &a);
    printf("Value of a: %i\n", *pA);
    printf("Double pointer of a: %p\n", ppA);
    printf("Double pointer of a: %p\n", &pA);
    printf("Value of a: %i\n", **ppA);

    /*
    Value of a: 10
    Pointer of a: 0x16db6ac5c
    Pointer of a: 0x16db6ac5c
    Value of a: 10
    Double pointer of a: 0x16db6ac50
    Double pointer of a: 0x16db6ac50
    Value of a: 10 
    */

    return 0;
}