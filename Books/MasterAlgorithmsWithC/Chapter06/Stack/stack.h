// ʵ���ϣ�stack����ͨ������ʵ�֣�Ҳ����ͨ������ʵ�֡�ͨ������ʵ�ֵ�ʱ��stack��push��pop
// ����������ͷ�ϲ���������������ʹ��list�������ض���Ϊstack�����¶���stack��push��pop
// �������ɡ�

#pragma once

#include <stdlib.h>

#include "list.h"

typedef List Stack;

typedef ListElmt StackElmt;

#define stack_init list_init

#define stack_destroy list_destroy

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

// �鿴ջ��Ԫ�ذ���������
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

#define stack_size list_size

#define stack_top list_head