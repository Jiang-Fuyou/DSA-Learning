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

    // 如果在链表头插入节点
    if (element == NULL) {
        // 如果链表为空
        if (list->size == 0)
            list->tail = new_element;
        // 新插入的节点的next指针指向链表头，链表头重新指向新插入的节点
        new_element->next = list->head;
        list->head = new_element;
    } else { // 在链表其他位置插入节点
        // 如果在链表尾插入节点
        if (element->next == NULL)
            list->tail = new_element;
        // 新插入的节点的next指针指向element的下一个节点
        // element的next指针指向新插入的节点
        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;
    return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data)
{
    // 用*data取出被删除节点的data
    ListElmt *old_element;

    // 如果是空链表，则直接返回
    if (list_size(list) == 0)
        return -1;

    // 如果要删除的节点位于链表头
    if (element == NULL) {
        // 用*data取出链表头的data值
        *data = list->head->data;
        // 用old_element指针指向链表头
        old_element = list->head;
        // 链表头指向链表头的下一个节点
        list->head = list->head->next;
        // 如果删除节点前仅仅只有一个节点，那么删除后链表为空，此时置链表尾为NULL
        if (list_size(list) == 1)
            list->tail = NULL;
    } else { // 如果要删除的节点位于链表其他位置
        // 如果要删除的节点位于链表尾的下一个，则直接返回
        if (element->next == NULL)
            return -1;
        // 否则，用*data取出要删除节点的data值
        *data = element->next->data;
        // 用old_element指向要删除的节点
        old_element = element->next;
        // 将element的next指针指向要删除的节点的下一个节点
        element->next = element->next->next;
        // 如果被删除的是链表尾，则置链表尾指针为element
        if (element->next == NULL)
            list->tail = element;
    }
    // 清理old_element指向的内存空间
    free(old_element);
    // 链表节点数目减一
    list->size--;
    return 0;
}

void list_destroy(List *list)
{
    void *data;
    // 如果链表非空
    while (list_size(list) > 0) {
        // 从链表头开始删除节点，将节点值取出到*data中
        if (list_rem_next(list, NULL, (void **)&data) == 0
            && list->destroy != NULL) // 如果定义了destroy
            list->destroy(data); // 使用destroy函数销毁data指向内存
    }
    // 重置链表内存
    memset(list, 0, sizeof(List));
}