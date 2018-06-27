#include "dlist.h"

void dlist_init(DList *dlist, void(*destroy)(void *data))
{
    dlist->size = 0;
    dlist->destroy = destroy;
    dlist->head = NULL;
    dlist->tail = NULL;
}

void dlist_destroy(DList *dlist)
{
    void *data;

    // ������ǿ�
    while (dlist_size(dlist) > 0) {
        // ���dlist_remove�������в���dlist->destroy����ָ�����
        if (dlist_remove(dlist, dlist_tail(dlist), (void **)&data) == 0
            && dlist->destroy)
            dlist->destroy(data);
        // ͨ��dlist_remove��β�ڵ�ɾ������β�ڵ��е�����ȡ����data������data
    }

    memset(dlist, 0, sizeof(DList));
}

int dlist_ins_next(DList *dlist, DListElmt *element, const void *data)
{
    DListElmt *new_element;

    // ��Ϊ��˫���������������ͷ���ǰ����ڵ㲻��Ҫins_next������������Ҫins_prev����
    // ������ﲻ��Ҫ������������element=NULL��Ȼ�����ͷ���
    if (element == NULL && dlist_size(dlist) != 0)
        return -1;

    if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
        return -1;
    new_element->data = (void *)data;

    if (!dlist_size(dlist)) { // ����Ϊ��
        dlist->head = new_element;
        dlist->tail = new_element;
        dlist->head->next = NULL;
        dlist->head->prev = NULL;
    } else {
        // ����ǿ�
        // ���½ڵ��nextָ��ָ��element����һ���ڵ㣬prevָ��ָ��next
        // ����element->next������NULL����element��β�ڵ�
        new_element->next = element->next;
        new_element->prev = element;

        // ���element��β�ڵ㣬��ô��dlist��βָ��ָ���²����Ԫ��
        if (!element->next)
            // ��ʱ��β�ڵ��nextָ��ָ��NULL��û��prevָ��
            dlist->tail = new_element;
        else
            // ����element��һ���ڵ��prevָ��ָ���½ڵ�
            element->next->prev = new_element;
        // element��nextָ��ָ���½ڵ�
        element->next = new_element;
    }
    // ����ڵ���Ŀ����
    dlist->size++;
    return 0;
}

int dlist_ins_prev(DList *dlist, DListElmt *element, const void *data)
{
    // ��ins_next���ƵĲ���
    DListElmt *new_element;

    if (!element && dlist_size(dlist))
        return -1;

    if (!(new_element = (DListElmt *)malloc(sizeof(DListElmt))))
        return -1;

    new_element->data = (void *)data;

    if (!dlist_size(dlist)) {
        dlist->head = new_element;
        dlist->tail = new_element;
        dlist->head->next = NULL;
        dlist->head->prev = NULL;
    } else {
        new_element->next = element;
        new_element->prev = element->prev;

        if (!element->prev)
            dlist->head = new_element;
        else
            element->prev->next = new_element;

        element->prev = new_element;
    }

    dlist->size++;
    return 0;
}

int dlist_remove(DList *dlist, DListElmt *element, void **data)
{
    // �����ж�element��ַ��ȷ���������нڵ���Ŀ��Ϊ0
    if (!element || !dlist_size(dlist))
        return -1;

    // ��*dataȡ��element��data�ĵ�ַ
    *data = element->data;

    // ���Ҫɾ����һ���ڵ�
    if (element == dlist->head) { // ������ע�⣬���ﲻҪд��element = dlist->head
        dlist->head = element->next; // �������ͷָ��ָ���һ���ڵ����һ���ڵ�
        if (!element->next) // �����һ���ڵ����һ���ڵ�ΪNULL�����ʱ����Ϊ��
            dlist->tail = NULL;
        else // ����element->next��prevָ��ָ��NULL
            element->next->prev = NULL; 
    } else {
        // ��ɾ��ͷ�ڵ㣬���element->prev���ڣ�element->prev->nextָ��element����һ��
        // �ڵ�
        element->prev->next = element->next;

        // ���element����һ���ڵ�ΪNULL����elementΪβ�ڵ�
        if (!element->next)
            dlist->tail = element->prev;
        else
            element->next->prev = element->prev;
    }
    // ��ʱ��elementǰ��Ľڵ���element����Ľڵ��Ѿ�˫�������ˣ���˿���ɾ��element
    free(element);
    dlist->size--;
    return 0;
}