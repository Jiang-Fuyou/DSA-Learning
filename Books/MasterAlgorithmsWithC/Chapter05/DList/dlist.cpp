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

    // 当链表非空
    while (dlist_size(dlist) > 0) {
        // 如果dlist_remove正常运行并且dlist->destroy函数指针存在
        if (dlist_remove(dlist, dlist_tail(dlist), (void **)&data) == 0
            && dlist->destroy)
            dlist->destroy(data);
        // 通过dlist_remove将尾节点删除，将尾节点中的数据取出到data，销毁data
    }

    memset(dlist, 0, sizeof(DList));
}

int dlist_ins_next(DList *dlist, DListElmt *element, const void *data)
{
    DListElmt *new_element;

    // 因为是双向链表，因此在链表头结点前插入节点不需要ins_next操作，而是需要ins_prev操作
    // 因此这里不需要像单向链表那样element=NULL，然后插入头结点
    if (element == NULL && dlist_size(dlist) != 0)
        return -1;

    if ((new_element = (DListElmt *)malloc(sizeof(DListElmt))) == NULL)
        return -1;
    new_element->data = (void *)data;

    if (!dlist_size(dlist)) { // 链表为空
        dlist->head = new_element;
        dlist->tail = new_element;
        dlist->head->next = NULL;
        dlist->head->prev = NULL;
    } else {
        // 链表非空
        // 将新节点的next指针指向element的下一个节点，prev指针指向next
        // 这里element->next可以是NULL，即element是尾节点
        new_element->next = element->next;
        new_element->prev = element;

        // 如果element是尾节点，那么将dlist的尾指针指向新插入的元素
        if (!element->next)
            // 此时，尾节点的next指针指向NULL，没有prev指针
            dlist->tail = new_element;
        else
            // 否则，element下一个节点的prev指针指向新节点
            element->next->prev = new_element;
        // element的next指针指向新节点
        element->next = new_element;
    }
    // 链表节点数目增加
    dlist->size++;
    return 0;
}

int dlist_ins_prev(DList *dlist, DListElmt *element, const void *data)
{
    // 和ins_next类似的操作
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
    // 首先判断element地址正确并且链表中节点数目不为0
    if (!element || !dlist_size(dlist))
        return -1;

    // 用*data取得element中data的地址
    *data = element->data;

    // 如果要删除第一个节点
    if (element == dlist->head) { // ！！！注意，这里不要写错element = dlist->head
        dlist->head = element->next; // 将链表的头指针指向第一个节点的下一个节点
        if (!element->next) // 如果第一个节点的下一个节点为NULL，则此时链表为空
            dlist->tail = NULL;
        else // 否则，element->next的prev指针指向NULL
            element->next->prev = NULL; 
    } else {
        // 不删除头节点，因此element->prev存在，element->prev->next指向element的下一个
        // 节点
        element->prev->next = element->next;

        // 如果element的下一个节点为NULL，即element为尾节点
        if (!element->next)
            dlist->tail = element->prev;
        else
            element->next->prev = element->prev;
    }
    // 此时，element前面的节点与element后面的节点已经双向链接了，因此可以删除element
    free(element);
    dlist->size--;
    return 0;
}