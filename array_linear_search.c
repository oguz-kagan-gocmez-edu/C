#include <stdio.h>

// returns the index of the target value in a specified array.
// when we pass 'int array[]' it behaves like a 'int* array' !!!
int search(int array[], int len, int target) 
{
    int i;
    for (i = 0; i < len; i++) 
    {
        if (array[i] == target) return i;
    }
    return -1;
}

int search_with_pointer(int* array, int len, int target) 
{
    int i;
    for (i = 0; i < len; i++) 
    {
        if (target == *(array + i)) 
            return i;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int len, n[] = {2,56,32,10,65,84,39};
    len = sizeof(n) / sizeof(int);
    int index = search(n, len, 56);
    if (index == -1)
    {
        printf("Value not found.\n");
        return 1;
    }
    printf("Value found at position: %i\n", index);

    int index_p = search_with_pointer(n, len, 56);
    if (index_p == -1)
    {
        printf("Value not found.\n");
        return 1;
    }
    printf("Value found at position: %i\n", index_p);
    
    return 0;
}
