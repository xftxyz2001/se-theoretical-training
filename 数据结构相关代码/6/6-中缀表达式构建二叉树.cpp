//中缀表达式构建二叉树
/*
（1）从当前传入的表达式data[start...end]中找出不在括号内、最靠后、优先级最低的一个运算符，
     作为二叉树的根节点，并记录其位置mid
（2）分别构建该二叉树的左子树data[start...mid-1]和右子树data[mid+1...end]
（3）返回当前根节点
*/ 
BiTree createTree(char *data, int start, int end)
{
	// 去掉最外侧括号
	if(data[start] == "(" && data[end] == ")"){
		start++; end--;
	}
	
	BiTree T = new BiTNode;
	int size = end-start+1;
	
	if(size <= 0) return NULL; 	
    if(size == 1){  // 长度为1, 数字直接作为叶结点
		T->data = data[start];
		T->lchild = T->rchild = NULL; 
		return T;		
	} 
	
	char chosen;   // 记录选中的运算符
	int lcount = 0, mid;  // lcount记录左括号数量，mid记录选中运算符位置
	for(int i=start; i<=end; i++){
		if(data[i] == "(") lcount++;  // 这两行用于记录括号匹配是否结束
		if(data[i] == ")") lcount--;
			
		// isFour()用于判断是否是四则运算符, lcount==0表示外层不存在括号, 
		// compare()用于比较两运算符优先级.0 表示相同；1表示第一个优先级大；-1表示第二个优先级大 
		if(isFour(data[i]) && lcount==0 && compare(chosen, data[i]) != -1){
			chosen = data[i];  mid = i;
		}
	}
	T->data = chosen;
	// 对左右子树分别赋值，递归调用此函数 
	T->lchild = createTree(data, start, mid-1);
	T->rchild = createTree(data, mid+1, end);
	return T;
	}
}
