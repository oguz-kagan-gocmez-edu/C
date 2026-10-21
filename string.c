#include <stdio.h>
#include <string.h>

void strrev(char string[]) 
{
    int i, length = strlen(string);
    for (i = 0; i < length / 2; i++) 
    {
        char temp = string[i];
        string[i] = string[length - i - 1];
        string[length - i - 1] = temp;
    }
}

void strrev_ptr(char* string) // sizeof -> sizeof pointer - studied before strlen() = # of chars till '\0' 
{
    int i, length = strlen(string);

    for (i = 0; i < length / 2; i++) 
    {
        char temp = *(string + i);
        *(string + i) = *(string + length - 1 - i);
        *(string + length - 1 - i) = temp;
    }
}

void strrev_ptr_len(char* string, int length) // sizeof -> sizeof pointer - studied before strlen() = # of chars till '\0' 
{
    int i;
    for (i = 0; i < length / 2; i++) 
    {
        char temp = *(string + i);
        *(string + i) = *(string + length - 1 - i);
        *(string + length - 1 - i) = temp;
    }
}

int main(int argc, char const *argv[])
{
    char *name = "OguzKagan";
    char surname[] = "Gocmez";

    int i;
    for (i = 0; i < 20; i++) 
    {
        printf("%c", name[i]);
    }
    printf("\n");
    //OguzKaganGocmez%c is printed out.

    for (i = 0; i < 20; i++) 
    {
        printf("%u ", name[i]);
    }
    printf("\n");
    //79 103 117 122 75 97 103 97 110 0 71 111 99 109 101 122 0 37 99 0 is printed out. ASCII
    for (i = 0; i < 20; i++) 
    {
        printf("%c", surname[i]);
    }
    printf("\n");
    //GocmeztŊ03Uo is printed out. You can see which ones are garbage value.

    char example[8] = "Tom"; // The rest are all '\0'
    for (i = 0; i < 8; i++) 
    {
        printf("%c ", example[i]);
    }
    printf("\n\n");

    printf("------------GETTING STRING-----------------\n");
    // to read strings, -scanf(), -gets(), -getchar().
    // use fgets(str, sizeof(str), stdin) not gets(str). (no size denotion, no support)
    // if we enter more characters for str, the program's behaviour may get unpredictable(*).
    // buffer overflow-buffer size same-but the exceeded chars written to the next(*) memory address. '\0' is at the end
  /*char str[10];
    printf("Enter any string whose length is less than 10\n");
    scanf("%s ", str); // cannot have space when entering the string.
    printf("%s\n", str);
    */
    char uni[10];
    printf("Enter any string whose length is less than 10\n");
    //gets(uni);
    fgets(uni, sizeof(uni), stdin); // does not ignore space
    printf("%s\n", uni);

    // those were to get strings. now display them.
    // printf() - puts() - putchar() 
    // printf() : Prints formatted output; may read out of bounds if the string lacks '\0'.
    // puts()    : Prints a string and adds '\n'; may read out of bounds if the string lacks '\0'.
    // putchar() : Prints a single character; does not cause buffer overflow by itself.
    printf("------------PRINTING STRING-----------------\n");
    char* greeting = "hello guys how r u doin";
    printf("%s\n", greeting);
    puts(greeting);

    printf("------------string.h features-----------------\n");
    char* by = "Bye bye!";
    printf("Length: %lu\n", strlen(by)); // strlen has return type unsigned long - %lu in short.
    char bye[8];
    printf("Enter the 'bye' string\n");
    scanf("%s", bye);
    printf("Length: %lu\n", strlen(bye));

    char bye_last[100];
    printf("Enter the 'bye_last' string\n");
    scanf("%s", bye_last);
    printf("Length: %lu\n", strlen(bye_last));

    char copy[strlen(bye_last) + 1]; // +1 is for '\0'
    strcpy(copy, bye_last);
    printf("%s\n", copy);

    if(strcmp(copy, bye_last) == 0) // for successful comparison, returns zero. 
    {
        printf("'copy' & 'bye_last' are same string in comparison\n");
    }

    char destination[11] = "selam";
    char source[6] = "SELAM";
    printf("%s\n", destination);
    printf("%s\n", source);
    strcat(destination, source); // cat1 + cat2 is assigned to cat1
    printf("%s\n", destination);
    printf("%s\n", source);

    //strrev() is used for char name[] not thprugh a pointer
    // not part of standard C library 
    // totally depends on our own local machine.

    strrev(surname);
    printf("%s\n", surname);
    strrev_ptr(surname);
    printf("%s\n", surname);
    strrev_ptr_len(surname, strlen(surname));
    printf("%s\n", surname);
    
    return 0;
}
