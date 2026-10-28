#include <stdio.h>

int main(int argc, char const *argv[])
{
    // run from -5 to 4 (both inclusive) and got the result of false for x = 0
    int x;
    for (x = -1000; x != 1000 ; x++) 
    {
        if (x) {
            continue;
        } else {
            printf("for {%i} : false\n", x);
        }
    }
    // false for only x = 0

    return 0;
}
