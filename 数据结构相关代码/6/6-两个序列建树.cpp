/*先序序列和中序序列分别存储在pre[]和ino[]数组中；
i和j是先序序列的下标界，m和n是中序序列的下标界；
返回值为构造好的二叉树的根节点指针*/
BiTree CrtBiTree(char pre[],char in[],int i,int j,int m,int n)
{
    int k;
    BiTNode *bt;

    if(i>j) return NULL; //序列为空，返回空指针

    //根结点为pre[i]，在中序序列中寻找根结点的位置，
    k=m;
    while(k<n)
    {
         if(in[k]==pre[i]) break;
         k++;
    }

    if(k>n)   return NULL;  //在中序中未找到根结点，序列不正确

    bt=(BiTNode*)malloc(sizeof(BiTNode));
    bt->data=pre[i];
    if(k==m) //bt的左子树为空
        bt->LChild=NULL;
    else
        bt->LChild=CrtBiTree(pre,in,i+1,i+k-m,m,k-1); //递归建立左子树

    if(k==n)
        bt->RChild=NULL;  //bt的右子树为空
    else
        bt->RChild=CrtBiTree(pre,in,i+k-m+1,j,k+1,n);  //递归建立右子树

    return bt;
}
