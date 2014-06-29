#define DTL_LIST_IMPLEMENTATION
#include "../list.h"
#include "../test.h"

void test_append(void)
{
    dtl_list_node* n = dtl_list_alloc();
    dtl_list_node* new_node = dtl_list_append(n);

    unsigned l = dtl_list_length(n);
    test(l == 2);
    test(n->next == new_node);
    test(n->next->next == NULL);
    test(n->prev == NULL);
    test(n->next->prev == n);

    dtl_list_node* new_new_node = dtl_list_append(n);

    l = dtl_list_length(n);
    test(l == 3);
    test(n->next == new_new_node);
    test(new_new_node->next == new_node);
    test(new_node->prev == new_new_node);
    test(new_new_node->prev == n);

    dtl_list_free(n);
}

void test_prepend(void)
{
    dtl_list_node* n = dtl_list_alloc();
    n = dtl_list_prepend(n);

    unsigned l = dtl_list_length(n);
    test(l == 2);

    dtl_list_free(n);
}

void test_get(void)
{
    dtl_list_node* n = dtl_list_alloc();
    int* five = malloc(sizeof(int));
    *five = 5;
    n->value = five;
    int i = dtl_list_get(n, int);
    test(i == 5);
    dtl_list_free(n);
}

void test_length(void)
{
    dtl_list_node* n = dtl_list_alloc();
    unsigned l = dtl_list_length(n);
    test(l == 1);
    dtl_list_free(n);
}

void test_list(void)
{
    dtl_list_node* n = dtl_list_alloc();

    int* five = malloc(sizeof(int));
    int* three = malloc(sizeof(int));
    int* ten = malloc(sizeof(int));
    *five = 5; *three = 3; *ten = 10;

    n->value = five;

    dtl_list_node* new_node = dtl_list_append(n);
    new_node->value = three;

    dtl_list_node* last_node = dtl_list_append(new_node);
    last_node->value = ten;

    dtl_list_node* temp = n;
    test(dtl_list_get(temp, int) == 5);
    temp = temp->next;
    test(dtl_list_get(temp, int) == 3);
    temp = temp->next;
    test(dtl_list_get(temp, int) == 10);

    dtl_list_free(n);
}

int main(void)
{
    test_length();
    test_get();
    test_append();
    test_prepend();
    test_list();

    return 0;
}

