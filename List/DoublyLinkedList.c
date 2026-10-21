#include <stdio.h>
#include <stdlib.h>

struct DoublyNode {
    int data;
    struct DoublyNode *previous;
    struct DoublyNode *next;
};

struct DoublyLinkedList {
    struct DoublyNode *head;
    struct DoublyNode *tail;
    size_t length;

    void (*insert_first)(struct DoublyLinkedList *self, int data);
    void (*insert_last)(struct DoublyLinkedList *self, int data);
    void (*print)(struct DoublyLinkedList *self);

};

static void insert_first(struct DoublyLinkedList *self, int data) 
{
    if (self == NULL) {
        printf("DoublyLinkedlist given is null while inserting first!\n");
        return;
    }

    struct DoublyNode *new = (struct DoublyNode *) calloc(1, sizeof(struct DoublyNode));
    if (new == NULL)
    {
        printf("The creation of the doubly node(data:%i) while inserting first is failed!\n", data);
        return;
    }
    
    new->data = data;
    new->next = self->head;
    self->head = new;

    if (self->tail == NULL)
    {
        self->tail = new;
    }

    self->length++;
}

static void insert_last(struct DoublyLinkedList *self, int data) 
{
    if (self == NULL) {
        printf("DoublyLinkedlist given is null while inserting last!\n");
        return;
    }
    
    struct DoublyNode *new = (struct DoublyNode *) calloc(1, sizeof(struct DoublyNode));

    if (new == NULL)
    {
        printf("The creation of the doubly node(data:%i) while inserting last is failed!\n", data);
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

static void print(struct DoublyLinkedList *self) 
{
    if (self == NULL) 
    {
        printf("DoublyLinkedlist given is null while printing.\n");
        return;
    }

    struct DoublyNode *temp = self->head;

    while (temp != NULL)
    {
        printf("%i ", temp->data);
        temp = temp->next;
    }
    printf("\n");

}

struct DoublyLinkedList new_doublylinkedlist() 
{
    struct DoublyLinkedList list;
    list.head = NULL;
    list.tail = NULL;
    list.length = 0;

    list.insert_first = insert_first;
    list.insert_last = insert_last;
    list.print = print;

    return list;
}

int main(int argc, char const *argv[])
{
    struct DoublyLinkedList my_list = new_doublylinkedlist();
    struct DoublyLinkedList *p_my_list = &my_list;
    int i;
    for (i = 0; i < 33; i++) 
    {
        my_list.insert_last(p_my_list, i);
    }
    my_list.print(p_my_list);
    
    return 0;
}

