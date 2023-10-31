#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node, *LinkList;

int isPalindrome(LinkList head) {
    if (!head || !head->next) { // 空链表或只有一个结点，视为回文链表
        return 1;
    }
    
    // 快慢指针找到中间结点
    Node *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // 将中间结点之后的结点逆置
    Node *prev = NULL, *cur = slow, *next;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    
    // 从头和中间开始比较
    Node *p1 = head, *p2 = prev;
    int res = 1;
    while (p2) {
        if (p1->data != p2->data) {
            res = 0;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    // 恢复链表并返回结果
    cur = prev, prev = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    slow->next = prev;
    return res;
}
