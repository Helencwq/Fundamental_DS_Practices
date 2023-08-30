#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitQueue(LinkQueue &q){
    //Empty queue head
    q.front = (AssistQueue*) malloc(sizeof (AssistQueue));
    q.rear = q.front;
    q.front->next = NULL;
}

int QueueIsEmpty(LinkQueue q){
    if(q.front == q.rear)
        return 1;
    return 0;
}

void Enqueue(LinkQueue &q, TNode *node){
    AssistQueue *newNode = (AssistQueue*) malloc(sizeof (AssistQueue));
    newNode->node = node;
    newNode->next = NULL;
    q.rear->next = newNode;
    q.rear = newNode;
}

int Dequeue(LinkQueue &q, TNode &node){
    if(!QueueIsEmpty(q)){
        AssistQueue *buf = q.front->next;
        node = *buf->node;
        q.front->next = buf->next;
        if(q.rear == buf)
            q.rear = q.front;
        free(buf);
    }else{
        printf("ERROR: Queue is empty. Dequeue failed.\n" );
        return 0;
    }

    return 1;
}

int Dequeue(LinkQueue &q){
    if(!QueueIsEmpty(q)){
        AssistQueue *buf = q.front->next;
        q.front->next = buf->next;
        if(q.rear == buf)
            q.rear = q.front;
        free(buf);
    }else{
        printf("ERROR: Queue is empty. Dequeue failed.\n" );
        return 0;
    }

    return 1;
}

TNode* GetFront(LinkQueue &q){
    //return NULL if empty?
    return q.front->next->node;
}