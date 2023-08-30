#ifndef _TREE_H
#define _TREE_H

typedef int ElemType;

typedef struct TNode{
    ElemType data;
    struct TNode *lchild, *rchild;
}TNode, *BiTree;

extern int TreeIsEmpty(BiTree root);
extern int InsertBiTreeLevelOrder(BiTree root, ElemType key);
extern int DeleteBiTreeLevelOrder(BiTree root, ElemType key);
extern BiTree CreateBiTreeLevelOrder(ElemType str[], int len);

#endif