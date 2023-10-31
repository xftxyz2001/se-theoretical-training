// 相对于动态链表，它节省了动态分配内存的时间和空间开销。
// 此外，静态链表还可以被用于解决内存动态分配困难的场景，例如操作系统中常见的虚拟内存管理。
#include <stdio.h>

#define MAXSIZE 100 // 静态链表的最大长度

typedef struct
{
    int data;
    int next;
} Node;

Node list[MAXSIZE]; // 静态链表数组
int length = 0;     // 静态链表当前长度
int head = -1;      // 静态链表头结点索引

// 初始化静态链表
void initList()
{
    for (int i = 0; i < MAXSIZE; i++)
    {
        list[i].next = -2;
    }
}

// 在静态链表末尾插入一个节点
void insert(int item)
{
    if (length == MAXSIZE)
    {
        printf("Error: the list is full!\n");
        return;
    }
    int index = ++length;
    list[index].data = item;
    list[index].next = -1;
    if (head == -1)
    {
        head = index;
    }
    else
    {
        int ptr = head;
        while (list[ptr].next != -1)
        {
            ptr = list[ptr].next;
        }
        list[ptr].next = index;
    }
}

// 删除指定位置的节点
void delete(int index)
{
    if (index < 1 || index > length)
    {
        printf("Error: invalid index!\n");
        return;
    }
    if (index == 1)
    {
        head = list[head].next;
    }
    else
    {
        int ptr = head;
        for (int i = 1; i < index - 1; i++)
        {
            ptr = list[ptr].next;
        }
        list[ptr].next = list[list[ptr].next].next;
    }
    length--;
}

// 修改指定位置的节点数据
void update(int index, int item)
{
    if (index < 1 || index > length)
    {
        printf("Error: invalid index!\n");
        return;
    }
    int ptr = head;
    for (int i = 1; i < index; i++)
    {
        ptr = list[ptr].next;
    }
    list[ptr].data = item;
}

// 查找指定位置的节点数据
int search(int index)
{
    if (index < 1 || index > length)
    {
        printf("Error: invalid index!\n");
        return -1;
    }
    int ptr = head;
    for (int i = 1; i < index; i++)
    {
        ptr = list[ptr].next;
    }
    return list[ptr].data;
}

// 测试静态链表基本操作
int main()
{
    initList();
    insert(1);
    insert(2);
    insert(3);
    insert(4);
    insert(5);

    printf("Before deletion:\n");
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", search(i));
    }
    printf("\n");

    delete (3);

    printf("After deletion:\n");
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", search(i));
    }
    printf("\n");

    update(2, 10);

    printf("After update:\n");
    for (int i = 1; i <= length; i++)
    {
        printf("%d ", search(i));
    }
    printf("\n");
    return 0;
}
