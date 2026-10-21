#include <stdio.h>

int addition(int a, int b) 
{
    return a + b;
}

int main(int argc, char const *argv[])
{
    int (*pAddition)(int, int) = &addition;
    int result = ((*pAddition)(4, 5));
    printf("Result: %i\n", result);

    // do some pointer arithmetic
    //char *name;
    char name[50];
    printf("Enter your name: ");
    fgets(name ,sizeof(name),stdin);
    char *character = &name;
    int i;
    for (i = 0; *(character + i) != '\0'; i++) 
    {
        printf("Character located at %i is: %c \n", i, *(character + i));
    }

    int n = 44;
    int *pN = &n;

    for (i = 0; i < 333; i++) 
    {
        printf("Value (maybe garbage): %i \n", *(pN + i));
    }

    pN = NULL;
    printf("Value: %i\n", *pN);

    return 0;
}
