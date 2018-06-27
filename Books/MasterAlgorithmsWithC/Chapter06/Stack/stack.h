// 实际上，stack可以通过数组实现，也可以通过链表实现。通过链表实现的时候，stack的push和pop
// 都是在链表头上操作。因此这里可以使用list，将其重定义为stack，重新定义stack的push和pop
// 操作即可。

#pragma once

#include <stdlib.h>

#include "list.h"

typedef List Stack;

typedef ListElmt StackElmt;

#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

// 查看栈顶元素包含的数据
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

#define stack_top list_head