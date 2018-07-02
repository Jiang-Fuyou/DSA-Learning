#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "set.h"

static void print_set(const Set *set)
{
    SetMember *member;
    int *data, i;

    member = set->head;
    for (size_t i = 0; i < set->size; i++) {
        data = (int *)member->data;
        printf("set[%03d] = %03d\n", *data);
        member = member->next;
    }
}

int match_int(const void *key1, const void *key2)
{
    return !memcmp(key1, key2, sizeof(int));
}

int main()
{
    Set set;

}