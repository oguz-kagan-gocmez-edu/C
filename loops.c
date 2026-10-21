//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int factorial(int n)
{
    if (n < 0)
    {
        printf("Please give a positive number to calculate.");
        return 1;
    }
    int sum = 1;
    for (int i = 2; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}

int main(int argc, char* argv[])
{
    int fac = factorial(5);
    printf("Result: %i\n", fac);

    int i = 1;
    while (i < 10)
    {
        printf("%i", i);
        i++;
    }
    printf("\n");

    char s;
    do
    {
        printf("Please enter the character 'a'\n");
        scanf(" %c", &s);
    } while (s != 'a');

    return 0;
}


