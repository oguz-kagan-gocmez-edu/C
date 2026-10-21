#include <stdio.h>
#include <stdlib.h>
int sum_to(int n) 
{
    if (n == 1) return 1;
    else return n + sum_to(n - 1);
}

int main(int argc, char const *argv[])
{
    if (argc != 2) 
    {
        printf("Usage ./sum to number\n");
        return 1;
    }
    int sum = sum_to(atoi(argv[1]));
    printf("%i\n", sum);
    return 0;
}
