//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int main (int argc, char *argv[])
{
    int x = 100;
    printf("Value : %d\n", x);
    printf("Address: %p\n", &x);
    // u stands for unsigned integer
    printf("Address: %u\n", &x);

    float y = 3.1415926;
    printf("y = %f\n", y);

    char ch = 'a';
    printf("ch = %c\n", ch);

    char ch1 = 'as';
    printf("ch1 = %c\n", ch1);

    char *ch2 = "selamun aleykum";
    printf("ch2 = %s\n", ch2);

    return 0;
}
