#include <stdio.h>

union Point
{
    int x;
    int y;
};



int main(int argc, char const *argv[])
{
    union Point p;
    p.x = 10;
    p.y = 20;

    // 20 20
    printf("%i %i \n", p.x, p.y); 
    p.x = 30;
    // 30 30
    printf("%i %i \n", p.x, p.y);
    
    return 0;
}
