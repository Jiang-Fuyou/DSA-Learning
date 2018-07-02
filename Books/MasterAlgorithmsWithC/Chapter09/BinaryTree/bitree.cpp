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
        position = &bitree->root; /* 此时，bitree->root即*position */
    } else {
        if (node->left != NULL)
            return -1;
        position = &node->left; /* 此时，node->left即*position */
    }
    /* 之后只要使*position指向新插入的节点，就实现了插入操作 */

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
            移除当前节点的左子节点与右子节点后，将当前节点包含的数据对于的指针释放，
            之后将指向当前节点的指针释放。
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
    // 用merge初始化一个树，并且调用left（或right）的destroy
    bitree_init(merge, left->destroy);

    // 如果merge插入有问题，则销毁merge，返回
    if (bitree_ins_left(merge, NULL, data) != 0) {
        bitree_destroy(merge);
        return -1;
    }

    merge->root->left = left->root;
    merge->root->right = right->root;

    merge->size = merge->size + left->size + right->size;
    
    // 这里左树和右树已经挂到merge树上了，因此左、右树的根节点置空，size置0
    left->root = NULL;
    left->size = 0;
    right->root = NULL;
    right->size = 0;

    return 0;
}