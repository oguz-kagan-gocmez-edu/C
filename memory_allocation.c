#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // malloc()

    int i, n = 5;
    int *arr;

    arr = (int *) malloc(sizeof(int) * n);
    if (arr == NULL) 
    {
        printf("Array creation is failed\n");
        return 1;
    }

    for (i = 0; i < n; i++) 
    {
        printf("arr[%i]: %i\n", i, *(arr + i));
    }

    for (i = 0; i < n; i++) 
    {
        *(arr + i) = (i + 1) * 10;
    }

    printf("Values stored on the array via malloc()\n");
    for (i = 0; i < n; i++) 
    {
        printf("Value at index %i of pointer %p is % i\n", i , arr + i, *(arr + i));
    }

    free(arr);
    arr = NULL; // it is good practice to keep them as NULL.

    // calloc()
    arr = (int *) calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation is failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) 
    {
        printf("arr[%i]: %i\n", i, *(arr + i));
    }
    
    free(arr);
    arr = NULL;

    arr = (int *) malloc(sizeof(int) * n);
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    *(arr) = 10;
    *(arr + 1) = 20;

    printf("Allocation of 2 elements:\n%i,%i\n", *(arr), *(arr + 1));
    int *temp = (int *) realloc(arr, sizeof(int) * 1);
    if (temp == NULL)
    {
        printf("Reallocation failed\n");
        free(arr);
        return 1;
    }

    arr = temp;
    
    printf("\nAfter realloc: (Note that size has been decreased to 1.)\n");
    for (int i = 0; i < 4; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);
    arr = NULL;

    return 0;
}
