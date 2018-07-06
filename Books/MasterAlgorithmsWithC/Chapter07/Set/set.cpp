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
        // matchΪ1��not matchΪ0
        if (set->match(data, member->data) != 0)
            return 1;
    }
    return 0;
}

int set_remove(Set *set, void **data)
{
    SetMember *member, *prev;

    // ��ʼ��prevΪnullptr��Ϊset->head��ǰһ��Ԫ��
    prev = nullptr;
    for (member = set->head; member != nullptr; member = member->next) {
        // ���match����break����ʱprev����member��ǰһ��Ԫ��
        if (set->match(*data, member->data))
            break;
        prev = member;
    }

    // ���û�ҵ����򷵻�-1
    if (member == nullptr)
        return -1;

    return list_rem_next(set, prev, data);
}

int set_union(Set *set, const Set *set1, const Set *set2)
{
    SetMember *member;
    void *data;

    // ��init�ŵ�����
    // set_init(set, set1->match, NULL);
    // ԭ������и��������insertʧ�ܷ��ط�0��ʱ��destroy��set������-1

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

// ����set1���ڼ���set2�Ĳ
// �����Ҫ�����������в�ͬ��Ԫ�أ�����ʹ�� D = U - I ����
int set_difference(Set *set, const Set *set1, const Set *set2)
{
    SetMember *member;
    void *data;

    // �ҵ���set1�е�����set2�е�Ԫ�ء�
    for (member = set1->head; member != nullptr; member = member->next) {
        if (!set_is_member(set2, member->data))
            set_insert(set, member->data);
    }

    return 0;
}

// set1��set2���Ӽ�
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

// ��set1��set2Ԫ�ظ�����ȵ�����£����set1��set2���Ӽ�����ô������set���
int set_is_equal(const Set *set1, const Set *set2)
{
    if (set1->size != set2->size)
        return 0;

    return set_is_subset(set1, set2);
}