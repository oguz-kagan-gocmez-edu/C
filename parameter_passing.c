#include <stdio.h>

void swap_fake(int a, int b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void swap_real(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(int argc, char const *argv[])
{
    int x = 5;
    int y = 8;

    printf("The values of x and y before change: %i-%i\n", x, y);
    swap_fake(x,y);
    printf("The values of x and y  after change: %i-%i\n", x, y);


    printf("The values of x and y before change: %i-%i\n", x, y);
    swap_real(&x, &y);
    printf("The values of x and y  after change: %i-%i\n", x, y);
    return 0;
}