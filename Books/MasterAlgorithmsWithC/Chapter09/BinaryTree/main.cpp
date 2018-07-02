#include <stdio.h>
#include <stdlib.h>

#include "bitree.h"
#include "traverse.h"


static void print_preorder(const BinaryTreeNode *node)
{
    if (!bitree_is_eob(node)) {

        fprintf(stdout, "Node=%03d\n", *(int *)bitree_data(node));

        if (!bitree_is_eob(bitree_left(node)))
            print_preorder(bitree_left(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_preorder(bitree_right(node));
    }
}


static void print_inorder(const BinaryTreeNode *node)
{
    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            print_inorder(bitree_left(node));

        fprintf(stdout, "Node=%03d\n", *(int *)bitree_data(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_inorder(bitree_right(node));
    }
}


static void print_postorder(const BinaryTreeNode *node)
{
    if (!bitree_is_eob(node)) {

        if (!bitree_is_eob(bitree_left(node)))
            print_postorder(bitree_left(node));

        if (!bitree_is_eob(bitree_right(node)))
            print_postorder(bitree_right(node));

        fprintf(stdout, "Node=%03d\n", *(int *)bitree_data(node));
    }
}


static int insert_int(BinaryTree *bitree, int i)
{
    BinaryTreeNode *node, *prev;
    int direction, *data;

    // 初始node为二叉树root节点
    node = bitree->root;
    direction = 0;

    // 如果node为空，则跳过
    // 向左或者向右搜索的时候，一直搜索到分支结束为止
    while (!bitree_is_eob(node)) {
        prev = node;

        // 如果新插入的数据和node包含的数据相同，则返回-1
        if (i == *(int *)bitree_data(node)) {
            return -1;
        } else if (i < *(int *)bitree_data(node)) {
            // 递归搜索i的位置，i小于node包含的数据，则向左搜索
            node = bitree_left(node);
            direction = 1;
        } else {
            // 递归搜索i的位置，i大于node包含的数据，则向右搜索
            node = bitree_right(node);
            direction = 2;
        }
    }

    if ((data = (int *)malloc(sizeof(int))) == NULL) return -1;

    *data = i;

    // pre记录要插入的位置，direction记录要插入的方向（左、右）
    // 如果node为空，则插入节点作为根节点
    if (direction == 0) return bitree_ins_left(bitree, NULL, data);
    if (direction == 1) return bitree_ins_left(bitree, prev, data);
    if (direction == 2) return bitree_ins_right(bitree, prev, data);

    return -1;
}


static BinaryTreeNode *search_int(BinaryTree *bitree, int i)
{
    BinaryTreeNode *node;

    node = bitree_root(bitree);

    while (!bitree_is_eob(node)) {
        if (i == *(int *)bitree_data(node)) {
            return node;
        } else if (i < *(int *)bitree_data(node)) {
            node = bitree_left(node);
        } else {
            node = bitree_right(node);
        }
    }

    return NULL;
}


int main(int argc, char **argv)
{
    BinaryTree bitree;
    BinaryTreeNode *node;
    int i;


    bitree_init(&bitree, free);

    /*
                    20
                   /   \
                 10     30
                /  \    /  \
               5    15 25   70
                      /  \    \
                     23   26   80
    */
    fprintf(stdout, "Inserting some nodes\n");
    if (insert_int(&bitree, 20) != 0) return 1;
    if (insert_int(&bitree, 10) != 0) return 1;
    if (insert_int(&bitree, 30) != 0) return 1;
    if (insert_int(&bitree, 15) != 0) return 1;
    if (insert_int(&bitree, 25) != 0) return 1;
    if (insert_int(&bitree, 70) != 0) return 1;
    if (insert_int(&bitree, 80) != 0) return 1;
    if (insert_int(&bitree, 23) != 0) return 1;
    if (insert_int(&bitree, 26) != 0) return 1;
    if (insert_int(&bitree, 5 ) != 0) return 1;

    fprintf(stdout, "Tree size is %d\n", bitree_size(&bitree));
    fprintf(stdout, "(Preorder traversal)\n");
    print_preorder(bitree_root(&bitree));
    fprintf(stdout, "(Inorder traversal)\n");
    print_inorder(bitree_root(&bitree));

#if 0
    i = 30;

    if ((node = search_int(&bitree, i)) == NULL) {

        fprintf(stdout, "Could not find %03d\n", i);

    }

    else {

        fprintf(stdout, "Found %03d...Removing the left bitree below it\n", i);
        bitree_rem_left(&bitree, node);
        fprintf(stdout, "Tree size is %d\n", bitree_size(&bitree));
        fprintf(stdout, "(Preorder traversal)\n");
        print_preorder(bitree_root(&bitree));

    }

    i = 99;

    if ((node = search_int(&bitree, i)) == NULL) {

        fprintf(stdout, "Could not find %03d\n", i);

    }

    else {

        fprintf(stdout, "Found %03d...Removing the right bitree below it\n", i);
        bitree_rem_right(&bitree, node);
        fprintf(stdout, "Tree size is %d\n", bitree_size(&bitree));
        fprintf(stdout, "(Preorder traversal)\n");
        print_preorder(bitree_root(&bitree));

    }

    i = 20;

    if ((node = search_int(&bitree, i)) == NULL) {

        fprintf(stdout, "Could not find %03d\n", i);

    }

    else {

        fprintf(stdout, "Found %03d...Removing the right bitree below it\n", i);
        bitree_rem_right(&bitree, node);
        fprintf(stdout, "Tree size is %d\n", bitree_size(&bitree));
        fprintf(stdout, "(Preorder traversal)\n");
        print_preorder(bitree_root(&bitree));

    }

    i = bitree_is_leaf(bitree_root(&bitree));
    fprintf(stdout, "Testing bitree_is_leaf...Value=%d (0=OK)\n", i);
    i = bitree_is_leaf(bitree_left((bitree_root(&bitree))));
    fprintf(stdout, "Testing bitree_is_leaf...Value=%d (0=OK)\n", i);
    i = bitree_is_leaf(bitree_left(bitree_left((bitree_root(&bitree)))));
    fprintf(stdout, "Testing bitree_is_leaf...Value=%d (1=OK)\n", i);
    i = bitree_is_leaf(bitree_right(bitree_left((bitree_root(&bitree)))));
    fprintf(stdout, "Testing bitree_is_leaf...Value=%d (1=OK)\n", i);

    fprintf(stdout, "Inserting some nodes\n");

    if (insert_int(&bitree, 55) != 0)
        return 1;

    if (insert_int(&bitree, 44) != 0)
        return 1;

    if (insert_int(&bitree, 77) != 0)
        return 1;

    if (insert_int(&bitree, 11) != 0)
        return 1;

    fprintf(stdout, "Tree size is %d\n", bitree_size(&bitree));
    fprintf(stdout, "(Preorder traversal)\n");
    print_preorder(bitree_root(&bitree));
    fprintf(stdout, "(Inorder traversal)\n");
    print_inorder(bitree_root(&bitree));
    fprintf(stdout, "(Postorder traversal)\n");
    print_postorder(bitree_root(&bitree));

    /*****************************************************************************
    *                                                                            *
    *  Destroy the binary bitree.                                                  *
    *                                                                            *
    *****************************************************************************/

    fprintf(stdout, "Destroying the bitree\n");
    bitree_destroy(&bitree);
#endif // 0

    return 0;
}
