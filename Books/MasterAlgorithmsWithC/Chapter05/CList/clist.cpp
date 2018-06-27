#include <stdlib.h>
#include <string.h>

#include "clist.h"


void clist_init(CList *clist, void(*destroy)(void *data))
{
    clist->size = 0;
    clist->destroy = destroy;
    clist->head = NULL;
}

void clist_destroy(CList *clist)
{
    void *data;

    while (clist_size(clist) > 0) {
        if (clist_rem_next(clist, clist->head, (void **)&data) == 0 
            && clist->destroy != NULL) {
            clist->destroy(data);
        }
    }

    memset(clist, 0, sizeof(CList));
}

int clist_ins_next(CList *clist, CListElmt *element, const void *data)
{
    CListElmt *new_element;

    if ((new_element = (CListElmt *)malloc(sizeof(CListElmt))) == NULL)
        return -1;

    new_element->data = (void *)data;

    if (clist_size(clist) == 0) {
        new_element->next = new_element;
        clist->head = new_element;
    } else {
        new_element->next = element->next;
        element->next = new_element;
    }

    clist->size++;
    return 0;
}

int clist_rem_next(CList *clist, CListElmt *element, void **data)
{
    CListElmt *old_element;

    if (clist_size(clist) == 0)
        return -1;

    *data = element->next->data;

    if (element->next == element) {
        old_element = element->next;
        clist->head = NULL;
    } else {
        old_element = element->next;
        element->next = element->next->next;
    }

    free(old_element);
    clist->size--;

    return 0;
}
