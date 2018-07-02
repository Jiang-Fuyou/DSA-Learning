#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bitree.h"

void bitree_init(BinaryTree *bitree, void(*destroy)(void *data))
{
    bitree->root = NULL;
    bitree->size = 0;
    bitree->destroy = destroy;
}

void bitree_destroy(BinaryTree *bitree)
{
    bitree_rem_left(bitree, NULL);
    memset(bitree, 0, sizeof(BinaryTree));
}

int bitree_ins_left(BinaryTree *bitree, BinaryTreeNode *node, const void *data)
{
    BinaryTreeNode *new_node;
    BinaryTreeNode **position;

    if (node == NULL) {
        if (bitree->size > 0)
            return -1;
        position = &bitree->root; /* ��ʱ��bitree->root��*position */
    } else {
        if (node->left != NULL)
            return -1;
        position = &node->left; /* ��ʱ��node->left��*position */
    }
    /* ֮��ֻҪʹ*positionָ���²���Ľڵ㣬��ʵ���˲������ */

    if ((new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode))) == NULL)
        return -1;
    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;
    *position = new_node;

    bitree->size++;
    return 0;
}

int bitree_ins_right(BinaryTree *bitree, BinaryTreeNode *node, const void *data)
{
    BinaryTreeNode *new_node;
    BinaryTreeNode **position;

    if (bitree->root == NULL) {
        if (bitree->size > 0)
            return -1;
        position = &bitree->root;
    } else {
        if (node->right != NULL)
            return -1;
        position = &node->right;
    }

    if ((new_node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode))) == NULL)
        return -1;

    new_node->data = (void *)data;
    new_node->left = NULL;
    new_node->right = NULL;

    *position = new_node;

    bitree->size++;
    return 0;
}

void bitree_rem_left(BinaryTree *bitree, BinaryTreeNode *node)
{
    BinaryTreeNode **position;

    if (bitree->size == 0)
        return;

    if (node == NULL)
        position = &bitree->root;
    else
        position = &node->left;

    if (*position != NULL) {
        /* 
            �Ƴ���ǰ�ڵ�����ӽڵ������ӽڵ�󣬽���ǰ�ڵ���������ݶ��ڵ�ָ���ͷţ�
            ֮��ָ��ǰ�ڵ��ָ���ͷš�
        */
        bitree_rem_left(bitree, *position);
        bitree_rem_right(bitree, *position);

        if (bitree->destroy != NULL)
            bitree->destroy((*position)->data);
        free(*position);
        *position = NULL;

        bitree->size--;
    }
}

void bitree_rem_right(BinaryTree *bitree, BinaryTreeNode *node)
{
    BinaryTreeNode **position;

    if (bitree->size == 0)
        return;
    
    if (node == NULL)
        position = &bitree->root;
    else
        position = &node->right;

    if (*position != NULL) {
        bitree_rem_left(bitree, *position);
        bitree_rem_right(bitree, *position);

        if (bitree->destroy != NULL)
            bitree->destroy((*position)->data);
        free(*position);
        *position = NULL;

        bitree->size--;
    }
}

int bitree_merge(BinaryTree *merge, BinaryTree *left, BinaryTree *right,
                 const void *data)
{
    // ��merge��ʼ��һ���������ҵ���left����right����destroy
    bitree_init(merge, left->destroy);

    // ���merge���������⣬������merge������
    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destroy(merge);
        return -1;
    }

    merge->root->left = left->root;
    merge->root->right = right->root;

    merge->size = merge->size + left->size + right->size;
    
    // ���������������Ѿ��ҵ�merge�����ˣ�����������ĸ��ڵ��ÿգ�size��0
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}