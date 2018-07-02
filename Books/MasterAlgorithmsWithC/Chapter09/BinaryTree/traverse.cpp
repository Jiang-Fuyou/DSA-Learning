#include "traverse.h"

// ÏÈĞò±éÀú£¬¸ù->×ó->ÓÒ
int preorder(const BinaryTreeNode *node, List *list)
{
    if (node) {
        if (list_ins_next(list, list->tail, node->data) != 0)
            return -1;
        
        if (node->left)
            if (preorder(node->left, list) != 0)
                return -1;

        if (node->right)
            if (preorder(node->right, list) != 0)
                return -1;
    }

    return 0;
}

// ÖĞĞò±éÀú£¬×ó->¸ù->ÓÒ
int inorder(const BinaryTreeNode *node, List *list)
{
    if (node) {
        if (node->left)
            if (inorder(node->left, list) != 0)
                return -1;

        if (list_ins_next(list, list->tail, node->data) != 0)
            return -1;

        if (node->right)
            if (inorder(node->right, list) != 0)
                return -1;
    }

    return 0;
}

// ºóĞò±éÀú£¬×ó->ÓÒ->¸ù
int postorder(const BinaryTreeNode *node, List *list)
{
    if (node) {
        if (node->left)
            if (postorder(node->left, list) != 0)
                return -1;

        if (node->right)
            if (postorder(node->right, list) != 0)
                return -1;

        if (list_ins_next(list, list->tail, node->data) != 0)
            return -1;
    }

    return 0;
}