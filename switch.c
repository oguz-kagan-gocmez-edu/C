//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x;
    printf("Please enter a value: \n");
    scanf("%d",&x);

    switch (x)
    {
    case 1: printf("Did you enter 1?\n");
        break;
    case 1000: printf("Did you enter 1000?\n");
        break;
    default: printf("I am not taught to know this.");
    }

    return 0;
}
