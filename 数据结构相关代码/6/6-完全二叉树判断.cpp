#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef  char TElemType;  //本例子假设二叉树每个结点的值为char 
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *LChild,*RChild;
}BiTNode,*BiTree;

//以下是教材上的建立二叉树代码 
void CreateBiTree(BiTree *T){
  char ch;
  ch=getchar();
  if (ch==' ') (*T)=NULL;                    /* #代表空指针*/
  else {
    (*T)=(BiTree) malloc(sizeof(BiTNode));/*申请结点   */
    (*T)->data=ch;                        /*生成根结点  */
    CreateBiTree(&(*T)->LChild) ;         /*构造左子树  */
    CreateBiTree(&(*T)->RChild) ;         /*构造右子树  */
   }
}

int IsCompleteBT(BiTree T){
	BiTNode  *Queue[MAX],*p;   //用一个很大的数组模拟队列      
  	int front,rear,tag=1;

    front=rear=0;  //初始化队列为空 

    if(T==NULL)  return 1;  //空树是完全二叉树
	
	Queue[rear++]=T;           /*根结点入队列*/

    while (front!=rear){       /*当队列非空*/
      	p=Queue[front++];        /*队首元素出队列，并访问这个结点*/
	    
      	if (p->LChild!=NULL) 
		{
		   if(tag==0) return 0; //如果在此之前已经碰到过空，则可确定不是完全二叉树 
		   else  Queue[rear++]=p->LChild; /*左子树非空，则入队列*/
		}
      	else tag=0;  //记录左孩子第一次碰到空的情况，设置tag为0
		   
      	if (b->RChild!=NULL)  
		{
			if(tag==0) return 0;   //如果在此之前已经碰到过空，则可确定不是完全二叉树 
			else Queue[rear++]=p->RChild; /*右子树非空，则入队列*/
		}
		else  tag=0; //记录右孩子第一次碰到空的情况，设置tag为0    	
    }
    
    return 1;
}

//调用队列操作 
//int IsCompleteBT(BiTree T){
//	Queueu Q;
//	BiTNode *p;     
//  int tag=1;
//
//  InitQueue(&Q); //初始化队列为空 
//
//  if(T==NULL)  return 1;  //空树是完全二叉树
//	
//	EnterQueue(&Q,T);         /*根结点入队列*/
//
//  while (!IsEmpty(&Q)){       /*队列非空*/
//      DeleteQueue(&Q,&p);    /*队首元素出队列，并访问这个结点*/
//	    
//      if (p>LChild!=NULL) 
//		{
//		   if(tag==0) return 0; //如果在此之前已经碰到过空，则可确定不是完全二叉树 
//		   else  EnterQueue(&Q,p->LChild;; /*左子树非空，则入队列*/
//		}
//      else tag=0;  //记录左孩子第一次碰到空的情况，设置tag为0
//		   
//      if (p->RChild!=NULL)  
//		{
//			if(tag==0) return 0;   //如果在此之前已经碰到过空，则可确定不是完全二叉树 
//			else EnterQueue(&Q,p->RChild); /*右子树非空，则入队列*/
//		}
//		else  tag=0; //记录右孩子第一次碰到空的情况，设置tag为0    	
//    }
//    
//    return 1;
//}
//

//自己就写一个主函数，把各个函数功能测试一下,OK了。 
int main(){
	BiTree T=NULL;
	int b;
	
	printf("\nCreate a Binary Tree,# means NULL\n");
	CreateBiTree(&T);  /*建立一棵二叉树T*/

  	printf("%d",IsCompleteBT(T));     /*层次遍历二叉树*/  	
  
  	return 1;
}

