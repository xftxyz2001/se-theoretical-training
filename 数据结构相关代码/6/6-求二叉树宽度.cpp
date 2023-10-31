#include "stdio.h"
#include "stdlib.h"

#define TRUE 1
#define FALSE 0
#define MAXSIZE 50  /*队列的最大长度*/

typedef  char TElemType;
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

/*****************************/
typedef BiTNode* QueueElementType;
typedef struct
{
  QueueElementType  elem[MAXSIZE];  
  int  front;  
  int  rear ;  
}SeqQueue;

void InitQueue(SeqQueue *SQ)
{
  SQ->front=SQ->rear=0;
}

int IsEmpty(SeqQueue SQ)
{
    if(SQ.front==SQ.rear)  return 1;
    else return 0;
}
int EnterQueue(SeqQueue *SQ,QueueElementType x)
{
 	if( (SQ->rear+1)%MAXSIZE==SQ->front )
 	{printf("Queue is Full\n");return FALSE;}

 	SQ->elem[SQ->rear]=x;
 	SQ->rear=(SQ->rear+1)%MAXSIZE;
 	return TRUE;
}

int DeleteQueue(SeqQueue *SQ,QueueElementType *x)
{
  	if(SQ->front==SQ->rear)
  	{printf("Queue is NULL\n"); return FALSE;}

  	*x=SQ->elem[SQ->front];
  	SQ->front=(SQ->front+1)%MAXSIZE;
  	return TRUE;
}
int getHead(SeqQueue *SQ,QueueElementType *x)
{
  	if(SQ->front==SQ->rear)
  	{printf("Queue is NULL\n"); return FALSE;}

  	*x=SQ->elem[SQ->front];  	
  	return TRUE;
}

void CreateBiTree(BiTree *T){

  char ch;

  ch=getchar();
  if (ch==' ') (*T)=NULL;                    /* #代表空指针*/
  else {
    (*T)=(BiTree) malloc(sizeof(BiTNode));/*申请结点   */
    (*T)->data=ch;                        /*生成根结点  */
    CreateBiTree(&(*T)->lchild) ;         /*构造左子树  */
    CreateBiTree(&(*T)->rchild) ;         /*构造右子树  */
    }
}
int maxWidth(BiTree T){
 
   BiTNode *p;          
   SeqQueue Q;  
   int max=0,count=0;

   InitQueue(&Q); 
   if(T==NULL) return 0;
    
	EnterQueue(&Q,T); EnterQueue(&Q,NULL); //每层用NULL隔开 
    while (!IsEmpty(Q)){      
        DeleteQueue(&Q,&p);
		  
		if(p!=NULL)   //一层未结束，正常计数，进队 
		{
			count++;		  
			if (p->lchild!=NULL) 	EnterQueue(&Q,p->lchild);
		  	if (p->rchild!=NULL) 	EnterQueue(&Q,p->rchild);
       	}
       	else    //一层结束，进行判断 
       	{
			if(max < count) max=count;
			count=0;
			EnterQueue(&Q,NULL); //进NULL，隔开各层
			getHead(&Q,&p);
			if(p==NULL) break; //所有元素已经遍历完，结束 
		}
	}
	return max;
}

int main()
{
	BiTree bt;
	CreateBiTree(&bt);
	printf("maxWidth=%d",maxWidth(bt));
	
	return 1;
}
