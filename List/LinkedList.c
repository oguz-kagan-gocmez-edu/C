#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
    struct Node *tail;
    size_t length;

    void (*insert_first)(struct LinkedList *self, int data);
    void (*insert_last)(struct LinkedList *self, int data);
    void (*print)(struct LinkedList *self);

};

// A static variable inside a function does not die when the function terminates.
// When we insert 'static' keyword in front of a function or global variable;
// that will just be private to the .c file it has been written to.

static void insert_first (struct LinkedList *self, int data) 
{
    if (self == NULL) {
        printf("Linkedlist given is null while inserting first!\n");
        return;
    }
    //struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    struct Node *new = (struct Node *) calloc (1, sizeof(struct Node));

    if (new == NULL) {
        printf("The creation of the node(data:%i) while inserting first is failed!\n", data);
        return;
    }
    new->data = data; // (*new).data = data; -educational purposes-
    
    new->next = self->head;
    self->head = new;

    if (self->tail == NULL)
    {
        self->tail = new;
    }
    self->length++;
}

static void insert_last(struct LinkedList *self, int data) 
{
    if (self == NULL) {
        printf("Linkedlist given is null while inserting last!\n");
        return;
    }
    
    struct Node *new = (struct Node *) calloc(1, sizeof(struct Node));

    if (new == NULL) 
    {
        printf("The creation of the node(data:%i) while inserting last is failed!\n", data);
        return;
    }
    new->data = data;
    
    if (self->head == NULL)
    {
        self->head = new;

    } else {
        self->tail->next = new;
    }
    self->tail = new;
    self->length++;
}

static void print(struct LinkedList *self) 
{
    if (self == NULL) 
    {
        printf("Linkedlist given is null while printing.\n");
        return;
    }
    struct Node *temp = self->head;
    while (temp != NULL)
    {
        printf("%i ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct LinkedList new_linkedList () 
{
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;

    list.insert_first = insert_first;
    list.insert_last = insert_last;
    list.print = print;

    return list;
};


int main(int argc, char const *argv[])
{
    struct LinkedList my_list = new_linkedList();
    // z denotes size_t, u denotes unsigned 10 based.
    int i;
    for (i = 0; i < 22; i++) 
    {
        insert_last(&my_list, i);
    }
    
    print(&my_list);
    printf("%zu\n", my_list.length);
    return 0;
}
