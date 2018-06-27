#include "dlist.h"

#include <stdio.h>
#include <stdlib.h>


void print_dlist(const DList *dlist)
{
    DListElmt *element;
    int *data, i;

    printf("DList size is %d\n", dlist_size(dlist));

    // �������Ϊ�գ���ֱ�ӷ���
    if (dlist_size(dlist) == 0)
        return;

    i = 0;
    element = dlist->head;
    while (true) {
        data = (int *)dlist_data(element);
        printf("dlist[%03d] = %03d\n", i, *data);
        i++;

        if (dlist_is_tail(element))
            break;
        else
            element = dlist_next(element);
    }
}


int main(int argc, char const *argv[])
{
    DList dlist;
    DListElmt *element;
    int *data, i;


    dlist_init(&dlist, free);
    print_dlist(&dlist);

    
    element = dlist_head(&dlist);
    for (i = 10; i > 0; i--) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        *data = i;
        if (dlist_ins_prev(&dlist, dlist_head(&dlist), data) != 0)
            return 1;
    }
    print_dlist(&dlist);


    element = dlist_head(&dlist);
    for (i = 0; i < 8; i++)
        element = dlist_next(element);
    printf("Addr of data: %d, value of data: %d\n", data, *data);
    data = (int *)dlist_data(element);
    printf("Addr of data: %d, value of data: %d\n", data, *data);
    fprintf(stdout, "Removing an element after the one containing %03d\n",
            *data);
    if (dlist_remove(&dlist, element, (void **)&data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Inserting 011 at the tail of the list\n");
    *data = 11;
    if (dlist_ins_next(&dlist, dlist_tail(&dlist), data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Removing an element at the tail of the list\n");
    element = dlist_tail(&dlist);
    if (dlist_remove(&dlist, element, (void **)&data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Inserting 012 just before the tail of the list\n");
    *data = 12;
    if (dlist_ins_prev(&dlist, dlist_tail(&dlist), data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Iterating and removing the fourth element\n");
    element = dlist_head(&dlist);
    element = dlist_next(element);  // �����Ĳ������൱��elementָ�뻹������ͷ
    element = dlist_prev(element);
    element = dlist_next(element);
    element = dlist_prev(element);
    element = dlist_next(element);
    element = dlist_next(element);
    element = dlist_next(element);  // elementָ���˵��ĸ��ڵ�
    if (dlist_remove(&dlist, element, (void **)&data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Inserting 013 before the first element\n");
    *data = 13;
    if (dlist_ins_prev(&dlist, dlist_head(&dlist), data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Removing an element at the head of the list\n");
    if (dlist_remove(&dlist, dlist_head(&dlist), (void **)&data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Inserting 014 just after the head of the list\n");
    *data = 14;
    if (dlist_ins_next(&dlist, dlist_head(&dlist), data) != 0)
        return 1;
    print_dlist(&dlist);


    fprintf(stdout, "Inserting 015 two elements after the head of the list\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 15;
    element = dlist_head(&dlist);
    element = dlist_next(element);
    if (dlist_ins_next(&dlist, element, data) != 0)
        return 1;
    print_dlist(&dlist);


    i = dlist_is_head(dlist_head(&dlist));
    fprintf(stdout, "Testing dlist_is_head...Value=%d (1=OK)\n", i);
    i = dlist_is_head(dlist_tail(&dlist));
    fprintf(stdout, "Testing dlist_is_head...Value=%d (0=OK)\n", i);
    i = dlist_is_tail(dlist_tail(&dlist));
    fprintf(stdout, "Testing dlist_is_tail...Value=%d (1=OK)\n", i);
    i = dlist_is_tail(dlist_head(&dlist));
    fprintf(stdout, "Testing dlist_is_tail...Value=%d (0=OK)\n", i);


    fprintf(stdout, "Destroying the list\n");
    dlist_destroy(&dlist);


    return 0;
}