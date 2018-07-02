#pragma once

#include <stdlib.h>

typedef struct SetMember_
{
    void *data;
    SetMember_ *next;
} SetMember;

typedef struct Set_ 
{
    int size;
    SetMember *head;
    SetMember *tail;
    int(*match)(const void *key1, const void *key2);
    void(*destroy)(void *data);
} Set;

void set_init(Set *set,
              int(*match)(const void *key1, const void *key2),
              void(*destroy)(void *data));

void set_destroy(Set *set);

int set_insert(Set *set, const void *data);

int set_remove(Set *set, void **data);

int set_is_member(const Set *set, const void *data);