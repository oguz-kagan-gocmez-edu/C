#include <stdio.h>

int main(int argc, char const *argv[])
{
    // datatype array_name[size];
    // datatype array_name[size] = {list_of_values};
    int i , numbers[] = {1,4,8,3,5,8};
    int *pNumbers = &numbers; // just for trial purposes

    for (i = 0; i < sizeof(numbers) / sizeof(int); i++) 
    {
        printf("%i\n", numbers[i]);
    }

    // just for trial purposes
    for (i = 0; i < sizeof(numbers) / sizeof(int); i++) 
    {
        printf("%i\n", *(pNumbers + i));
    }
    return 0;
}
