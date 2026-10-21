#include <stdio.h>

extern int A; // coming from main.c

int main(int argc, char const *argv[])
{
    /* 4 types of storage classes 
    -automatic storage class (auto)
    -register storage class (register)
    -static storage class (static)
    -external storage class (extern)

    */
    register int hf = 12;
    printf("%i\n", A);

    return 0;
}
