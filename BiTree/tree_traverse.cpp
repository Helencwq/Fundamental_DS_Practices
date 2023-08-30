#include <stdio.h>
#include "tree_traverse.h"
#include "queue.h"

void DFS(BiTree root){
    if(root){
        printf("%d ", root->data);
        if(root->lchild){
            DFS(root->lchild);
        }

        if(root->rchild){
            DFS(root->rchild);
        }
    }
}

void BFS(BiTree root){
    LinkQueue assistQ;
    InitQueue(assistQ);
    TNode curNode;

    if(root){
        Enqueue(assistQ, root);
        while(!QueueIsEmpty(assistQ)){
            Dequeue(assistQ, curNode);
            printf("%d ", curNode.data);
            if(curNode.lchild){
                Enqueue(assistQ, curNode.lchild);
            }

            if(curNode.rchild){
                Enqueue(assistQ, curNode.rchild);
            }
        }
    }
}

void LevelOrderTraverse(BiTree root){
    BFS(root);
}

void RecursivePreOrderTraverse(BiTree root){
    DFS(root);
}

void RecursiveInOrderTraverse(BiTree root){
    if(root){
        if(root->lchild)
            RecursiveInOrderTraverse(root->lchild);

        printf("%d ", root->data);

        if(root->rchild)
            RecursiveInOrderTraverse(root->rchild);
    }
}

void RecursivePostOrderTraverse(BiTree root){
    if(root){
        if(root->lchild)
            RecursivePostOrderTraverse(root->lchild);

        if(root->rchild)
            RecursivePostOrderTraverse(root->rchild);

        printf("%d ", root->data);
    }
}

//TODO:
void PreOrderTraverse(BiTree root){

}

//TODO:
void InOrderTraverse(BiTree root);

//TODO:
void PostOrderTraverse(BiTree root);

