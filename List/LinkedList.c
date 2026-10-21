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

    void (*insertFirst)(struct LinkedList *self, int data);
    void (*insertLast)(struct LinkedList *self, int data);
    void (*print)(const struct LinkedList *self);

};

// A static variable inside a function does not die when the function terminates.
// When we insert 'static' keyword in front of a function or global variable;
// that will just be private to the .c file it has been written to.

static void insertFirst (struct LinkedList *self, int data) 
{
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


struct LinkedList new_linkedList () 
{
    struct LinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;

    return list;
};


int main(int argc, char const *argv[])
{
    struct LinkedList my_list = new_linkedList();
    // z denotes size_t, u denotes unsigned 10 based.
    printf("%zu\n", my_list.length);
    
    return 0;
}
