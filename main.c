#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main (int argc, char *argv[])
{
    int n = 50;
    int *pn = &n;
    printf("Pointer address: %p \n", pn);
    printf("Value: %i \n", n);
    printf("Value: %i \n", *pn);

    printf("-------------------------------\n");

    int *x;
    int *y;

    x = malloc(sizeof(int));

    *x = 42;
    y = x;
    *y = 13;

    printf("Pointer x:%p\n", x);
    printf("Value x:%i\n", *x);
    printf("Pointer y:%p\n", y);
    printf("Value x:%i\n", *y);

    return 0;
}