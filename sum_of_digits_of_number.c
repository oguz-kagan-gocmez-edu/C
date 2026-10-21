//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int n;
    printf("Give us a number: \n");
    scanf("%i", &n);

    if (n == -1)
    {
        perror("You have entered very big number");
        return 1;
    }

    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n /= 10;
    }

    printf("Sum of digits of that number is: %i\n", sum);
    return 0;
}
