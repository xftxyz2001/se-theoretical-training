/*后缀表达式生成二叉树（后缀表达式没有括号 ）
1. 依次读取表达式；
2. 如果是操作数，则将该操作数作为一个结点压入栈中；
3. 如果是操作符，则弹出栈中的两个操作数，第一个弹出的操作数作为右孩子，
第二个弹出的操作数作为左孩子，构建以该操作符为根的二叉树，并将构建的二叉树结点压入栈中。
*/
BiTree buildTree(char *exp)
{
    BiTNode *ptr,*q;         
    Stack S; //栈中的元素为BiTNode*类型 
    char c;
    int i=0;
    c=exp[i++];
    while(c!='\0')
    {
    	ptr=(BiTNode*)malloc(sizeof(BiTNode));  
		ptr->data=c; ptr->LChild=NULL; ptr->RChild=NULL; 
        if(c=='+' || c=='-'| c=='*'| c=='/') //c为运算符号 
       	{
		    if(!IsEmpty(&S))
            {
            	Pop(&S,&q); 
                ptr->RChild=q;
            }
            if(!IsEmpty(&S))
            {
                Pop(&S,&q); 
                ptr->LChild=q;
            }
        } 
        push(&S,ptr);
        c=exp[i++];        
    }
    return ptr;
}
