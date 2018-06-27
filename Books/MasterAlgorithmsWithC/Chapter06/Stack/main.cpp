#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "stack.h"

static void print_stack(const Stack *stack)
{
    StackElmt *element;
    int *data, i;

    printf("Stack size is %d.\n", stack_size(stack));

    // �����ж�i < stack_size(stack)����˲���Ҫ������
    //if (stack_size(stack) == 0)
    //    return;

    i = 0;
    element = stack_top(stack);
    while (i < stack_size(stack)) {
        data = (int *)list_data(element);
        printf("stack[%03d] = %03d\n", i, *data);
        element = list_next(element);
        i++;
    }
}

int main()
{
    Stack stack;
    int *data, i;


    stack_init(&stack, free);


    fprintf(stdout, "Pushing 10 elements\n");
    for (i = 0; i < 10; i++) {
        if ((data = (int *)malloc(sizeof(int))) == NULL)
            return 1;
        *data = i + 1;
        if (stack_push(&stack, data) != 0)
            return 1;
    }
    print_stack(&stack);


    fprintf(stdout, "Popping 5 elements\n");
    for (i = 0; i < 5; i++) {
        if (stack_pop(&stack, (void **)&data) == 0)
            free(data); // pop��data��ָ����ڴ棬��pop�����ݵĵ�ַ�ͷ�
        else
            return 1;
    }
    print_stack(&stack);


    // ��push���ݵ�ʱ����ҪΪdata�����ڴ�
    fprintf(stdout, "Pushing 100 and 200\n");
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 100;
    if (stack_push(&stack, data) != 0)
        return 1;
    if ((data = (int *)malloc(sizeof(int))) == NULL)
        return 1;
    *data = 200;
    if (stack_push(&stack, data) != 0)
        return 1;
    print_stack(&stack);


    if ((data = (int *)stack_peek(&stack)) != NULL)
        fprintf(stdout, "Peeking at the top element...Value=%03d\n", *data);
    else
        fprintf(stdout, "Peeking at the top element...Value=NULL\n");
    print_stack(&stack);


    fprintf(stdout, "Popping all elements\n");
    while (stack_size(&stack) > 0) {
        if (stack_pop(&stack, (void **)&data) == 0)
            free(data);
    }
    // ���ջ������Ԫ��
    if ((data = (int *)stack_peek(&stack)) != NULL)
        fprintf(stdout, "Peeking at an empty stack...Value=%03d\n", *data);
    else
        fprintf(stdout, "Peeking at an empty stack...Value=NULL\n");
    print_stack(&stack);


    // ʵ���ϣ���ʱջ�Ѿ��ǿյ���
    fprintf(stdout, "Destroying the stack\n");
    stack_destroy(&stack);


    return 0;
}