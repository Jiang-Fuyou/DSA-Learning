#pragma once

#include <stdlib.h>

typedef struct BinaryTreeNode_
{
    void *data;
    BinaryTreeNode_ *left;
    BinaryTreeNode_ *right;
} BinaryTreeNode;

typedef struct BinaryTree_
{
    int size;
    BinaryTreeNode *root;
    void(*destroy)(void *data);
    int (*compare)(const void *key1, const void *key2);
} BinaryTree;

void bitree_init(BinaryTree *bitree, void(*destroy)(void *data));

void bitree_destroy(BinaryTree *bitree);

int bitree_ins_left(BinaryTree *bitree, BinaryTreeNode *node, const void *data);

int bitree_ins_right(BinaryTree *bitree, BinaryTreeNode *node, 
                     const void *data);

void bitree_rem_left(BinaryTree *bitree, BinaryTreeNode *node);

void bitree_rem_right(BinaryTree *bitree, BinaryTreeNode *node);

int bitree_merge(BinaryTree *bitree, BinaryTree *left, BinaryTree *right, 
                 const void *data);

#define bitree_size(tree) ((tree)->size)

#define bitree_root(tree) ((tree)->root)

#define bitree_is_eob(node) ((node) == NULL)

#define bitree_is_leaf(node) ((node)->left == NULL && (node)->right == NULL)

#define bitree_data(node) ((node)->data)

#define bitree_left(node) ((node)->left)

#define bitree_right(node) ((node)->right)