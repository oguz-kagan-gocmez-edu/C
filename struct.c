#include <stdio.h>
#include <stddef.h> // this is for offsetof() function.
#include <stdalign.h> // the number that the offset number needs to be divided(,) with 0 remainder.

struct Employee
{
    int age;
    char name[50];
    float salary;
};

struct Employee2
{
    int age;
    float salary;
    char name[50];
};

struct Point {
    int x;
    int y;
};

void print_point(struct Point *ptr) 
{
    printf("x:%i\ny:%i\n", ptr->x, ptr->y);
}

int main(int argc, char const *argv[])
{
    printf("%zu\n",alignof(struct Employee));
    struct Employee e = {25, "Oguz Kagan Gocmez", 25000};
    printf("Size of employee struct is:%lu\n", sizeof(struct Employee));
    printf("Age: %i\n", e.age);
    printf("Name: %s\n", e.name);
    printf("Salary: %f\n", e.salary);
    // size_t için %zu kullanılır.
    printf("Struct size: %zu\n", sizeof(struct Employee));
    printf("Struct new size: %zu\n", sizeof(struct Employee2));
    printf("age offset: %zu\n", offsetof(struct Employee, age));
    printf("name offset: %zu\n", offsetof(struct Employee, name));
    printf("salary offset: %zu\n", offsetof(struct Employee, salary));
    printf("---------------------------------------------\n");

    struct Employee x[3] = {
        {21, "Oguz Kagan", 950000},
        {23, "Mete Han", 12000000},
        {25, "Teoman", 300000}
    };
    int length = sizeof(x) / sizeof(x[0]);
    for (int i = 0; i < length; i++) {
        printf("%p\n", &x[i]);
        printf("x[%d] -> Hex: %p | Onluk: %lu\n", i, (void *)&x[i], (uintptr_t)&x[i]);
    }

    struct Point point = {1, 6};
    print_point(&point);

    printf("Hex: %p Dec: %lu\n", &point.x, (uintptr_t)&point.x);
    printf("Hex: %p Dec: %lu\n", &point.y, (uintptr_t)&point.y);

    printf("%i\n", *&point.x);
    printf("%i\n", *&point.y);

    struct Employee kagan = {21, "Oguz Kagan", 1230000};
    struct Employee *pKagan = &kagan;
    printf("Address of the emp: %p : %lu\n", (void *)pKagan, (uintptr_t)((void *)pKagan));
    printf("Age address of the emp: %p : %lu\n", &((*pKagan).age), (uintptr_t)(&((*pKagan).age)));
    printf("Age of the emp: %i\n", (*pKagan).age);
    printf("Age of the emp: %i\n", kagan.age);
    printf("Age of the emp: %i\n", pKagan->age);

    printf("Name address of the emp: %p : %lu\n", &((*pKagan).name), (uintptr_t)(&((*pKagan).name)));
    printf("Name of the emp: %s\n", (*pKagan).name);
    printf("Name of the emp: %s\n", kagan.name);
    printf("Name of the emp: %s\n", pKagan->name);

    printf("Salary address of the emp: %p : %lu \n", &(*pKagan).salary, (uintptr_t)(&(*pKagan).salary));
    printf("Salary of the emp: %f\n", (*pKagan).salary);
    printf("Salary of the emp: %f\n", kagan.salary);
    printf("Salary of the emp: %f\n", pKagan->salary);

        

    return 0;
}
