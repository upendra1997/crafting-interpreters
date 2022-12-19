#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_
{
    char *value;
    struct Node_ *next;
    struct Node_ *prev;
} Node;

typedef struct
{
    Node *head;
    Node *current;
    Node *tail;
} DLL;

DLL *new()
{
    DLL *result = malloc(sizeof(DLL));
    return result;
}

Node *new_node(char *string)
{
    Node *result = malloc(sizeof(Node));
    result->value = string;
    return result;
}

void add_first(DLL *dll, char *string)
{
    Node *node = new_node(string);
    if (dll->head == NULL)
    {
        dll->head = node;
        dll->current = node;
        dll->tail = node;
    }
    else
    {
        dll->head->prev = node;
        node->next = dll->head;
        dll->head = node;
        dll->current = node;
    }
}

int remove_first(DLL *dll)
{
    if (dll->head == NULL)
    {
        return 0;
    }
    Node *to_be_deleted = dll->head;
    dll->head = dll->head->next;
    dll->current = dll->current->next;
    free(dll->head);
    return 1;
}

void traverse(DLL *dll, void (*fp)(char *))
{
    Node *current = dll->head;
    while (current != NULL)
    {
        fp(current->value);
        current = current->next;
    }
}

void print_string(char *string)
{
    printf("%s\n", string);
}

int main()
{
    DLL *dll = new ();
    add_first(dll, "world");
    add_first(dll, "hello");
    traverse(dll, &print_string);
    printf("%d\n", remove_first(dll));
    traverse(dll, &print_string);
    printf("%d\n", remove_first(dll));
    traverse(dll, &print_string);
    printf("%d\n", remove_first(dll));
    add_first(dll, "world");
    add_first(dll, "hello");
    traverse(dll, &print_string);
    printf("%d\n", remove_first(dll));
    traverse(dll, &print_string);
    printf("%d\n", remove_first(dll));
    traverse(dll, &print_string);
    printf("%d\n", remove_first(dll));
}