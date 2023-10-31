#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int elemType;

typedef struct
{
    elemType element[MAXSIZE];
    int front, rear, tag;
} SeqQueue;

void InitQueue(SeqQueue *Q)
{
    Q->front = Q->rear = 0;
    Q->tag = 0;
}

int EnterQueue(SeqQueue *Q, elemType x)
{
    if (Q->front == Q->rear && Q->tag == 1)
        return 0;
    Q->element[Q->rear] = x;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    if (Q->rear == Q->front)
        Q->tag = 1; /* 设置标志 */
    return 1;       /* 操作成功 */
}

int DeleteQueue(SeqQueue *Q, elemType *x)
{
    if (Q->front == Q->rear && Q->tag == 0)
        return 0;
    *x = Q->element[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    if (Q->front == Q->rear)
        Q->tag = 0; /* 设置标志 */
    return 1;       /* 操作成功 */
}