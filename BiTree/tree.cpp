#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "queue.h"

int TreeIsEmpty(BiTree root){
    if(root == NULL)
        return 1;
    return 0;
}

int InsertBiTreeLevelOrder(BiTree root, ElemType key){
    BiTree newNode = (BiTree) malloc(sizeof (TNode));
    newNode->data = key;
    newNode->lchild = NULL;
    newNode->rchild = NULL;

    if(root == NULL){
        root = CreateBiTreeLevelOrder(&key, 1);
    }else{
        LinkQueue q;
        InitQueue(q);
        Enqueue(q, root);
        BiTree curNode;
        while(!QueueIsEmpty(q)){
            curNode = GetFront(q);
            if(curNode->lchild == NULL){
                curNode->lchild = newNode;
                return 1;
            }else if(curNode->rchild == NULL){
                curNode->rchild = newNode;
                return 1;
            }

            if(curNode->lchild){
                Enqueue(q,curNode->lchild);
            }

            if(curNode->rchild){
                Enqueue(q,curNode->rchild);
            }
            Dequeue(q);
        }
    }


    return 0;
}

//TODO:
int DeleteBiTreeLevelOrder(BiTree root, ElemType key){
    return 1;
}

BiTree CreateBiTreeLevelOrder(ElemType str[], int len){
    if(len < 0){
        printf("invalid input array\n");
        return 0;
    }else if(len == 0){
        return NULL;
    }else{
        //len > 0
        BiTree root = NULL;
        BiTree newNode = NULL;
        BiTree curNode;

        LinkQueue assistQ;
        InitQueue(assistQ);
        for(int i = 0; i < len; i++){
            newNode = (BiTree) malloc(sizeof (TNode));
            newNode->data = str[i];
            newNode->lchild = NULL;
            newNode->rchild = NULL;

            Enqueue(assistQ, newNode);

            if(root == NULL){
                //tree is empty
                root = newNode;
//                Enqueue(assistQ, root);
            }else{
                //insert to leaves
//                Enqueue(assistQ, newNode);
                curNode = GetFront(assistQ);
                if(curNode->lchild == NULL){
                    curNode->lchild = newNode;
                }else if(curNode->rchild == NULL){
                    curNode->rchild = newNode;
                    Dequeue(assistQ);
                }
            }
        }
        return root;
    }
}

