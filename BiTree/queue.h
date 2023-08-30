#ifndef _QUEUE_H
#define _QUEUE_H
#include "tree.h"

typedef struct AssistQueue{
    TNode *node;
    struct AssistQueue *next;
}AssistQueue;

typedef struct LinkQueue{
    AssistQueue *front, *rear;
}LinkQueue;

extern void InitQueue(LinkQueue &q);
extern void Enqueue(LinkQueue &q, TNode *node);
extern int Dequeue(LinkQueue &q, TNode &node);
extern int Dequeue(LinkQueue &q);
extern TNode* GetFront(LinkQueue &q);
extern int QueueIsEmpty(LinkQueue q);

#endif