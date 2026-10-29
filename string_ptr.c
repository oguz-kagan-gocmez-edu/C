#include <stdio.h>


int main(int argc, char const *argv[])
{
    char *name = "Oguz Kagan";
    char surname[] = "Gocmez";
    printf("%d\n", name == &(*name));

    printf("%s\n", name);
    printf("%s\n", surname);
    // study the - string literals -

    // at compilation it generates an error.
    // name[0] = "G"; 
    printf("%s\n", name);
    printf("%s\n", surname);


    return 0;
}
