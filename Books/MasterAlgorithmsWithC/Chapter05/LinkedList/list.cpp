#include "list.h"

void list_init(List *list, void(*destroy)(void *data))
{
    list->size = 0;
    list->head = NULL;
    list->tail = NULL;
    list->destroy = destroy;
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element;
    if ((new_element = (ListElmt *)malloc(sizeof(ListElmt))) == NULL)
        return -1;
    new_element->data = (void *)data;

    // ���������ͷ����ڵ�
    if (element == NULL) {
        // �������Ϊ��
        if (list->size == 0)
            list->tail = new_element;
        // �²���Ľڵ��nextָ��ָ������ͷ������ͷ����ָ���²���Ľڵ�
        new_element->next = list->head;
        list->head = new_element;
    } else { // ����������λ�ò���ڵ�
        // ���������β����ڵ�
        if (element->next == NULL)
            list->tail = new_element;
        // �²���Ľڵ��nextָ��ָ��element����һ���ڵ�
        // element��nextָ��ָ���²���Ľڵ�
        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;
    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
    // ��*dataȡ����ɾ���ڵ��data
    ListElmt *old_element;

    // ����ǿ�������ֱ�ӷ���
    if (list_size(list) == 0)
        return -1;

    // ���Ҫɾ���Ľڵ�λ������ͷ
    if (element == NULL) {
        // ��*dataȡ������ͷ��dataֵ
        *data = list->head->data;
        // ��old_elementָ��ָ������ͷ
        old_element = list->head;
        // ����ͷָ������ͷ����һ���ڵ�
        list->head = list->head->next;
        // ���ɾ���ڵ�ǰ����ֻ��һ���ڵ㣬��ôɾ��������Ϊ�գ���ʱ������βΪNULL
        if (list_size(list) == 1)
            list->tail = NULL;
    } else { // ���Ҫɾ���Ľڵ�λ����������λ��
        // ���Ҫɾ���Ľڵ�λ������β����һ������ֱ�ӷ���
        if (element->next == NULL)
            return -1;
        // ������*dataȡ��Ҫɾ���ڵ��dataֵ
        *data = element->next->data;
        // ��old_elementָ��Ҫɾ���Ľڵ�
        old_element = element->next;
        // ��element��nextָ��ָ��Ҫɾ���Ľڵ����һ���ڵ�
        element->next = element->next->next;
        // �����ɾ����������β����������βָ��Ϊelement
        if (element->next == NULL)
            list->tail = element;
    }
    // ����old_elementָ����ڴ�ռ�
    free(old_element);
    // ����ڵ���Ŀ��һ
    list->size--;
    return 0;
}

void list_destroy(List *list)
{
    void *data;
    // �������ǿ�
    while (list_size(list) > 0) {
        // ������ͷ��ʼɾ���ڵ㣬���ڵ�ֵȡ����*data��
        if (list_rem_next(list, NULL, (void **)&data) == 0
            && list->destroy != NULL) // ���������destroy
            list->destroy(data); // ʹ��destroy��������dataָ���ڴ�
    }
    // ���������ڴ�
    memset(list, 0, sizeof(List));
}