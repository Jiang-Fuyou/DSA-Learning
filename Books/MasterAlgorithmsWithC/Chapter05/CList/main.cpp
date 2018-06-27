#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>

#include "clist.h"


static void print_list(const CList *clist)
{
    CListElmt *element;

    int *data, size, i;

    fprintf(stdout, "List size is %d (circling twice)\n", clist_size(clist));

    size = clist_size(clist);
    element = clist_head(clist);

    i = 0;
    while (i < size * 2) {
        data = (int *)clist_data(element);
        fprintf(stdout, "clist[%03d]=%03d\n", (i % size), *data);
        element = clist_next(element);
        i++;
    }
}

int main(int argc, char **argv)
{
    int tmpFlag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
    tmpFlag |= _CRTDBG_LEAK_CHECK_DF;
    _CrtSetDbgFlag(tmpFlag);

    CList clist;
    CListElmt *element;

    int *data, i;


    clist_init(&clist, free);


    element = clist_head(&clist);
    for (i = 0; i < 10; i++) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        *data = i + 1;
        if (clist_ins_next(&clist, element, data) != 0)
            return 1;
        if (element == NULL)
            element = clist_next(clist_head(&clist));
        else
            element = clist_next(element);
    }
    print_list(&clist);


    element = clist_head(&clist);
    for (i = 0; i < 10; i++)
        element = clist_next(element);
    data = (int *)clist_data(element);
    fprintf(stdout, "Circling and removing an element after the one containing "
            "%03d\n", *data);
    if (clist_rem_next(&clist, element, (void **)&data) != 0)
        return 1;
    free(data);
    print_list(&clist);


    element = clist_head(&clist);
    for (i = 0; i < 15; i++)
        element = clist_next(element);
    data = (int *)clist_data(element);
    fprintf(stdout, "Circling and inserting 011 after the element containing "
            "%03d\n", *data);
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 11;
    if (clist_ins_next(&clist, element, data) != 0)
        return 1;
    print_list(&clist);


    fprintf(stdout, "Destroying the clist\n");
    clist_destroy(&clist);


    return 0;
}
