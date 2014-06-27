#ifndef DTL_LIST_H
#define DTL_LIST_H

#include <malloc.h>

typedef struct node_t
{
    struct node_t* next;
    struct node_t* prev;
    void* value;
} node;

node*       dtl_list_alloc(void);
node*       dtl_list_append(node* n);
void        dtl_list_free(node*);
unsigned    dtl_list_length(node*);
node*       dtl_list_prepend(node* n);

#define     dtl_list_get(node, type) *((type*)(node->value))

#endif

#ifdef DTL_LIST_IMPLEMENTATION
node* dtl_list_alloc(void)
{
    node* n = malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->value = NULL;

    return n;
}

node* dtl_list_append(node* n)
{
    node* new_node = malloc(sizeof(node));
    node* old_next = n->next;

    new_node->next = old_next;
    new_node->prev = n;

    n->next = new_node;

    if(old_next)
    {
        old_next->prev = new_node;
    }

    return new_node;
}

void dtl_list_free(node* n)
{
    while (n != NULL)
    {
        node* old = n;
        n = n->next;

        free(old->value);
        free(old);
    }
}

unsigned dtl_list_length(node* n)
{
    unsigned l = 0;
    while (n != NULL)
    {
        l++;
        n = n->next;
    }
    return l;
}

node* dtl_list_prepend(node* n)
{
    node* new_node = malloc(sizeof(node));
    node* old_prev = n->prev;

    new_node->next = n;
    new_node->prev = old_prev;

    n->prev = new_node;

    if (old_prev)
    {
        old_prev->next = new_node;
    }

    return new_node;
}
#endif

