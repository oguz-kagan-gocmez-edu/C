#include <stdio.h>

void print_array(char *arr[], int length)
{
    for (int i = 0; i < length; i++) 
    {
        printf("%s\n", arr[i]);
    }
}

int main(int argc, char const *argv[])
{
    char *names[] = {"Oğuz Kağan", "Mete Han", "Teoman", "Tuğrul", "Battal Gazi", "Ertuğrul", "Süleyman"};
    int length = sizeof(names) / sizeof(names[0]);
    print_array(names, length);
    return 0;
}
