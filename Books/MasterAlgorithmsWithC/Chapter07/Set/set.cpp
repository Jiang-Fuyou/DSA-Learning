#include "set.h"

void set_init(Set *set,
              int(*match)(const void *key1, const void *key2),
              void(*destroy)(void *data))
{
    set->size = 0;
    set->head = NULL;
    set->tail = NULL;
    set->destroy = destroy;
    set->match = match;
}

void set_destroy(Set *set)
{

}

int set_insert(Set *set, const void *data)
{
    if (set_is_member(set, data))
        return 1;

    SetMember *member;
    member = (SetMember *)malloc(sizeof(SetMember));

    member->data = (int *)data;
    member->next = NULL;

    if (set->size == 0) {
        set->head = member;
        set->tail = member;
    } else {
        set->tail->next = member;
        set->tail = member;
    }

    set->size++;

    return 0;
}

int set_is_member(const Set *set, const void *data)
{
    SetMember *member;
    for (member = set->head; member != NULL; member = member->next) {
        if (set->match(data, member->data) != 0)
            return 1;
    }
    return 0;
}