#include <stdio.h>
#include <math.h>

// typedef Datatype newName

typedef int INT;

typedef struct {
    int x;
    int y;
} point;

double calculate_distance(point *p1, point *p2) 
{
    // two different use cases : just for practice
    //return sqrt(pow((*p1).x - (*p2).x, 2) + pow((*p1).y - (*p2).y, 2));
    return sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2));
}

int main(int argc, char const *argv[])
{
    INT x = 8;
    printf("%i\n", x);
    
    point z = {1,2};
    point y = {4,6};
    double dist = calculate_distance(&z, &y);
    printf("The distance: %lf\n", dist);


    return 0;
}
