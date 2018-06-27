#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>

#include "list.h"


static void print_list(List *list)
{
    ListElmt *element = list_head(list);
    int *data;
    printf("List size is %d\n", list_size(list));

    int i = 0;
    while (element) {
        data = (int *)list_data(element);
        printf("list[%03d] = %03d\n", i, *data);
        i++;
        element = list_next(element);
    }
}


int main(int argc, const char *argv[])
{
    int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpFlag);

    List list;
    ListElmt *element;
    int *data, i;

    list_init(&list, free);
    printf("list size is %d\n", list.size);


    element = list_head(&list);
    for (int i = 10; i > 0; i--) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        *data = i;
        if (list_ins_next(&list, NULL, data) != 0)
            return 1;
    }
    print_list(&list);


    printf("Inserting 012 at the head of the list.\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 12;
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);


    element = list_head(&list);
    for (int i = 0; i < 7; i++)
        element = list_next(element);
    data = (int *)list_data(element);
    printf("Removing an element after the one containing %03d\n", *data);
    if (list_rem_next(&list, element, (void **)&data) != 0)
        return 1;
    print_list(&list);


    printf("Inserting 011 at the tail of the list.\n");
    *data = 11;
    if (list_ins_next(&list, list_tail(&list), data) != 0)
        return 1;
    print_list(&list);


    printf("Removing an element after the first element.\n");
    element = list_head(&list);
    if (list_rem_next(&list, element, (void **)&data) != 0)
        return 1;
    print_list(&list);


    printf("Inserting 013 at the head of the list.\n");
    *data = 13;
    if (list_ins_next(&list, NULL, data) != 0)
        return 1;
    print_list(&list);


    printf("Iterating and removoing the fourth element.\n");
    element = list_head(&list);
    element = list_next(element);
    element = list_next(element);
    if (list_rem_next(&list, element, (void **)&data) != 0)
        return 1;
    print_list(&list);


    printf("Inserting 014 after the first element.\n");
    *data = 14;
    if (list_ins_next(&list, list_head(&list), data) != 0)
        return 1;
    print_list(&list);


    i = list_is_head(&list, list_head(&list));
    printf("Testing list_is_head...Value = %d (1 = OK)\n", i);
    i = list_is_head(&list, list_tail(&list));
    printf("Testing list_is_head...Value = %d (0 = OK)\n", i);
    i = list_is_tail(list_tail(&list));
    printf("Testing list_is_tail...Value = %d (1 = OK)\n", i);
    i = list_is_tail(list_head(&list));
    printf("Testing list_is_tail...Value = %d (0 = OK)\n", i);


    printf("Destroying the list.\n");
    list_destroy(&list);


    return 0;
}