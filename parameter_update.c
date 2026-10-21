#include <stdio.h>

void update(int alpha, int beta) 
{
    alpha = beta;
}

void update_real(int *alpha, int *beta) 
{
    *alpha = *beta;
}

int main(int argc, char const *argv[])
{
    int a = 9;
    int b = 19;

    printf("Before change a and b: %i-%i\n", a, b);
    update(a,b);
    printf("After  change a and b: %i-%i\n", a, b);

    printf("Before change a and b: %i-%i\n", a, b);
    update_real(&a, &b);
    printf("After  change a and b: %i-%i\n", a, b);

    return 0;
}
