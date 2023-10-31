typedef struct Tnode   //树结点定义
{
	DataType data;
	int parent;
} TNode;
typedef struct     //树定义
{
    TNode tree[MAX]; 
    int nodenum;
}MFSet;


/* 确定x属于并查集SS中哪个子集合。如果不属于SS中任一子集，则返回-1，否则返回所在子集树的根结点下标。*/
int Find_1 ( MFSst  *SS,  DataType  x)
{
    pos=Locate (SS, x);  //找到x在并查集中的位置
    if ( pos<0 )  return -1
    i=pos; 

    while(SS->tree[i].parent > 0 )   //顺着双亲域向上找
        i= SS->tree[i].parent ;
    return  i；
}
 
int Merge_1 ( MFSst  *SS,  int  root1,  int  root2 )
/* root1和root2是并查集SS中两个互不相交的非空子集树的根，将子集树root2并入子集树root1。*/
{
	if ( root1<0 || root1> SS->nodenum-1 ) return  ERROR;
	if ( root2<0 || root2> SS->nodenum-1 ) return  ERROR;

	SS->tree[root2].parent=root1;
	return OK;
}


///////////////////////////
/*路径压缩 
确定x属于并查集SS中哪个子集合，同时调整子集树，降低其高度。
如果x不属于SS中任一子集，则返回-1，
否则首先找到x所在子集树的根root，
然后将x及x的所有祖先（除了root）均改为root的子结点，
最后返回root。 
*/
int Find_2 ( MFSst  *SS,  DataType  x)
{
	pos=Locate (SS, x);
	if ( pos<0 )  return -1; 
	i=pos
	while ( SS->tree[i].parent > 0 )  
 		 i= SS->tree[i].parent ;
	root=i; 
	i=pos; 
	while ( i !=root )
	{
  		temp= SS->tree[i].parent ;
  		SS->tree[i].parent = root;
  		i= temp ;
	}
	return  root;
}

 
/* 本算法将结点数目较少的子集树并入结点数目较多的子集树。
parent域存放树中结点数目的负值，用来指导合并操作*/ 
int Merge_2 ( MFSst  *SS,  int  root1,  int  root2 )
{    
	if ( root1<0 || root1> SS->nodenum-1 )   return  ERROR;
    if ( root2<0 || root2> SS->nodenum-1 )  return  ERROR;
    if ( SS->tree[root1].parent < SS->tree[root2].parent )
     {  
          SS->tree[root1].parent+= SS->tree[root2].parent ；
          SS->tree[root2].parent=root1; }
    else  /* 第二棵子集树中结点数目较多 */
    {  
           SS->tree[root2].parent+= SS->tree[root1].parent ;
           SS->tree[root1].parent=root2;
	}
    return OK;
}

////////////////////////////////
// 并查集的应用（并查集采用简化了的存储结构，但算法思想相同） 
 
// 1. 判断图的连通分量数: 用邻接矩阵 g[][] 表示无向图的边
int ComponentCount(){
    int s[n];
    for(int k = 0; k < n; k++){
        s[k] = -1;    // 初始化并查集
    }
 
    // 遍历各条边（无向图，遍历上三角部分即可）
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(g[i][j] > 0){    // 结点 i, j 之间有边
                int iRoot = Find(s, i);  // 通过并查集找到 i 所属集合
                int jRoot = Find(s, j);  // 通过并查集找到 j 所属集合
                if(iRoot != jRoot)  Union(s, iRoot, jRoot);   // i, j 并入同一集合
            }int g[][],int n
        }
    }
 
    // 统计有几个连通分量
    int count = 0;
    for(int i = 0; i < n; i++){
        if(s[i] < 0) count++;
    }
    return count;   
    // count = 1, 说明是连通图；count > 1, 说明不是连通图，有count个连通分量；
}
 
// 2. 判断图是否有环:用邻接矩阵 g[][] 表示无向图的边
int ComponentCount(int g[][],int n){
    int s[n];
    for(int k = 0; k < n; k++)
        s[k] = -1;   // 初始化并查集
    
 
    // 遍历各条边（无向图，遍历上三角部分即可）
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(g[i][j] > 0){    // 结点 i, j 之间有边
                int iRoot = Find(s, i);  // 找到i 所属集合
                int jRoot = Find(s, j);  // 找 j 所属集合
 
                if(iRoot != jRoot)  Union(s, iRoot, jRoot);   // i, j 并入同一集合
                else   return 1;  // i, j 原本就在同一个集合，即原本就连通  
            }
        }
    }
    return 0;  // 图中没有环
}

// 3. Kruskal算法
// 总的时间复杂度 O(elog_2e)，总共执行e轮，每轮判断两个顶点是否属于同一个集合。
#include <stdio.h>
#include <stdlib.h>
#define N 9   // 图中边的数量
#define P 6   // 图中顶点的数量
//构建表示边的结构体
struct edge {   
    int start;  //一条边有 2 个顶点
    int end;    
    int weight;  //边的权值
};

//qsort排序函数中使用，使edges结构体中的边按照权值大小升序排序
int cmp(struct edge a[], struct edge b[]) {
    return  a[i]->weight - b[i]->weight;
}
//克鲁斯卡尔算法寻找最小生成树，edges 存储用户输入的图的各个边，minTree 用于记录组成最小生成树的各个边
void kruskal_MinTree(struct edge edges[], struct edge minTree[]) {
    int i, start, end, elem, k;
    //每个顶点配置一个标记值
    int assists[P];
    int num = 0;
    //初始状态下，每个顶点的标记都不相同
    for (i = 0; i < P; i++) {
        assists[i] = i;
    }
    //根据权值，对所有边进行升序排序
    qsort(edges, N, sizeof(edges[0]), cmp);
    //遍历所有的边
    for (i = 0; i < N; i++) {
        //找到当前边的两个顶点在 assists 数组中的位置下标
        initial = edges[i].start - 1;
        end = edges[i].end - 1;
        //如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
        if (assists[initial] != assists[end]) {
            //记录该边，作为最小生成树的组成部分
            minTree[num] = edges[i];
            //计数+1
            num++;
            elem = assists[end];
            //将新加入生成树的顶点标记全部改为一样的
            for (k = 0; k < P; k++) {
                if (assists[k] == elem) {
                    assists[k] = assists[initial];
                }
            }
            //如果选择的边的数量和顶点数相差1，证明最小生成树已经形成，退出循环
            if (num == P - 1) {
                break;
            }
        }
    }
}

void display(struct edge minTree[]) {
    int cost = 0, i;
    printf("最小生成树为:\n");
    for (i = 0; i < P - 1; i++) {
        printf("%d-%d  权值：%d\n", minTree[i].start, minTree[i].end, minTree[i].weight);
        cost += minTree[i].weight;
    }
    printf("总权值为：%d", cost);
}

int main() {
    int i;
    struct edge edges[N], minTree[P - 1];
    for (i = 0; i < N; i++) {
        scanf("%d %d %d", &edges[i].start, &edges[i].end, &edges[i].weight);
    }
    kruskal_MinTree(edges, minTree);
    display(minTree);
    return 0;
}


