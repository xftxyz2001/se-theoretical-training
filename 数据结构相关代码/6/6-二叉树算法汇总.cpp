// 给三叉链表中的每个结点设置双亲指针 
//先序、后序、中序、层序均可 
void setParent(TriTree tt)
{
	if(tt==NULL) return;
		
	if(tt->LChild) tt->LChild->parent=tt;
	if(tt->LChild) tt->LChild->parent=tt;
	
	setParent(tt->LChild);
	setParent(tt->RChild);
} 

//初值h的层次为0 
//先序、后序、中序、层序均可 
int wpl=0;
void calWPL(BiTree bt,int h)
{
	if(bt==NULL) return;
	
	if(bt->LChild==NULL  && bt->RChild==NULL) 
		wpl += wpl+bt->data*h;
	
	calWPL(bt->LChild,h+1);	
	calWPL(bt->RChild,h+1);	
}

//自上而下、从右到左的层次遍历
void layer(BiTree bt) 
{
	Queue    Q;
    BiTree  p; 
    
    InitQueue(&Q)； 
    if(bt==NULL) return;  
    EnterQueue(&Q, bt);   

    while (!IsEmpty(&Q))   
    { 
	    DeleteQueue(&Q, &p); 
	    visit(p->data);
	    if(p-> RChild)  EnterQueue(&Q, p->RChild); 
	    if(p-> LChild)  EnterQueue(&Q, p->LChild); 
    }  
}

//顺序存储，后序遍历
void LRD(ElemType A[],int i,int n)
{
	if(i>n) return;
	
	LRD(A,2*i,n);
	LRD(A,2*i+1,n);
	if(A[i]!=nullElem) visit(A[i]);
} 

//判断某个顺序存储的完全二叉树是否为大根堆
int isMaxHeap(ElemType A[],int n)
{
	int i;
	
	for(i=1;i<=n/2;i++)
	{
		if(A[i]<A[2*i]) return false;
		if(2*i+1<n && A[i]<A[2*i+1]) return false; 
	}	
	return true; 
}

//遍历每个结点，看看是否符合堆的要求 ; DLR,LDR,LRD,层序遍历均可 
int isMaxHeap(ElemType A[],int i,int n)
{	
	static int tag=1;
	if(i>n) return 0;
	
	if(2*i<=n && A[i]<A[2*i])  tag=0;  //与左孩子比 
	if(2*i+1<=n && A[i]<A[2*i+1]) tag=0; //与右孩子比 
	
	isMaxHeap(A,2*i,n);
	isMaxHeap(A,2*i+1,n);
	return tag;
}

//分治思想判断是否为堆 
int isMaxHeap(ElemType A[],int i,int n)
{
	if(i>n) return 1;  //空树是堆 	
	if(2*i>n) return 1; //A[i]是叶子，是堆 
	
	//肯定不是叶子结点 
	int tag=1; 
	if(2*i<=n && A[i]<A[2*i])  tag=0;  //与左孩子比 
	if(2*i+1<=n && A[i]<A[2*i+1]) tag=0; //与右孩子比 
	
	return tag && isMaxHeap(A,2*i,n) && isMaxHeap(A,2*i+1,n);		
}




