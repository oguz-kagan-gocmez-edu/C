//
// Created by Oguz Kagan Gocmez on 17.10.2026.
//
#include <stdio.h>

int main(int argc, char* argv[])
{
    int x,y,z,max;
    printf("Enter the three number\n");
    scanf("%d%d%d", &x, &y, &z);

    if (x > y)
    {
        if (x > z)
        {
            printf("Maximum of those numbers is x\n");
        }
    } else if (y > z)
    {
        printf("Maximum of those numbers is y\n");
    } else
    {
        printf("Maximum of those numbers is z\n");
    }

    printf("Enter the three number\n");
    scanf("%d%d%d", &x, &y, &z);

    max = x > y ? (x > z ? x : z) : (y > z ? y : z);
    printf("Maximum of those numbers is %i\n", max);

    return 0;
}
