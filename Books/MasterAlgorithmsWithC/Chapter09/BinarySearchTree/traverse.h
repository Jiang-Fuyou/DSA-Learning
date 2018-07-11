#pragma once

#include "bitree.h"
#include "list.h"

int preorder(const BinaryTreeNode *node, List *list);

int inorder(const BinaryTreeNode *node, List *list);

int postorder(const BinaryTreeNode *node, List *list);