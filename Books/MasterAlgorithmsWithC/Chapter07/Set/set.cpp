#include "set.h"

void set_init(Set *set,
              int(*match)(const void *key1, const void *key2),
              void(*destroy)(void *data))
{
    list_init(set, destroy);
    set->match = match;
}

void set_destroy(Set *set)
{
    list_destroy(set);
}

int set_insert(Set *set, const void *data)
{
    if (set_is_member(set, data))
        return 1;

    return list_ins_next(set, set->tail, data);
}

int set_is_member(const Set *set, const void *data)
{
    SetMember *member;
    for (member = set->head; member != nullptr; member = member->next) {
        // match为1，not match为0
        if (set->match(data, member->data) != 0)
            return 1;
    }
    return 0;
}

int set_remove(Set *set, void **data)
{
    SetMember *member, *prev;

    // 初始的prev为nullptr，为set->head的前一个元素
    prev = nullptr;
    for (member = set->head; member != nullptr; member = member->next) {
        // 如果match，则break，此时prev保持member的前一个元素
        if (set->match(*data, member->data))
            break;
        prev = member;
    }

    // 如果没找到，则返回-1
    if (member == nullptr)
        return -1;

    return list_rem_next(set, prev, data);
}

int set_union(Set *set, const Set *set1, const Set *set2)
{
    SetMember *member;
    void *data;

    // 把init放到外面
    // set_init(set, set1->match, NULL);
    // 原书代码中给出了如果insert失败返回非0的时候，destroy掉set并返回-1

    for (member = set1->head; member != nullptr; member = member->next) {
        set_insert(set, member->data);
    }
    for (member = set2->head; member != nullptr; member = member->next) {
        set_insert(set, member->data);
    }

    return 0;
}

int set_intersection(Set *set, const Set *set1, const Set *set2)
{
    SetMember *member;
    void *data;

    for (member = set1->head; member != nullptr; member = member->next) {
        if (set_is_member(set2, member->data))
            set_insert(set, member->data);
    }

    return 0;
}

// 集合set1对于集合set2的差集
// 如果是要找两个集合中不同的元素，可以使用 D = U - I 来找
int set_difference(Set *set, const Set *set1, const Set *set2)
{
    SetMember *member;
    void *data;

    // 找到在set1中但不在set2中的元素。
    for (member = set1->head; member != nullptr; member = member->next) {
        if (!set_is_member(set2, member->data))
            set_insert(set, member->data);
    }

    return 0;
}

// set1是set2的子集
int set_is_subset(const Set *set1, const Set *set2)
{
    SetMember *member;

    if (set1->size > set2->size)
        return 0;

    for (member = set1->head; member != nullptr; member = member->next) {
        if (!set_is_member(set2, member->data))
            return 0;
    }

    return 1;
}

// 在set1与set2元素个数相等的情况下，如果set1是set2的子集，那么这两个set相等
int set_is_equal(const Set *set1, const Set *set2)
{
    if (set1->size != set2->size)
        return 0;

    return set_is_subset(set1, set2);
}