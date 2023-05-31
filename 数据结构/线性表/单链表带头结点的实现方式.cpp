#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode // 定义一个单链表数据结构
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList &L) // 初始化单链表
{
    L = (LNode *)malloc(sizeof(LNode)); // 分配一个头节点
    if (L == NULL)
    { // 内存不足，分配失败
        return false;
    }
    L->next = NULL; // 头节点之后暂时还没有节点，所以暂时指向NULL
    return true;
}

bool Empty(LinkList L) // 判断单链表是否为空
{
    return (L->next == NULL); // 如果为空返回true，否则返回false
}

bool ListInsert(LinkList &L, int i, int e) // 在单链表的第i个位置插入元素e
{
    if (i < 1)
    { // i值不合法
        return false;
    }
    LNode *p;  // 声明一个指向节点的指针
    int j = 0; // 当前p指向的是第几个节点
    p = L;     // 让p指向头节点，由于头节点是第0个节点，所以p指向第0个节点
    while (p != NULL && j < i - 1)
    { // 寻找第i-1个节点
        p = p->next;
        j++;
    }
    if (p == NULL)
    { // i值不合法
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 分配一个新节点
    s->data = e;                               // 将数据e赋值给新节点的数据域
    s->next = p->next;                         // 将新节点的next指针指向第i个节点
    p->next = s;                               // 将第i-1个节点的next指针指向新节点
    return true;
}

bool InsertNextNode(LNode *p, int e) // 在p节点之后插入新节点
{
    if (p == NULL)
    { // p节点不存在
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 分配一个新节点
    if (s == NULL)
    { // 内存不足，分配失败
        return false;
    }
    s->data = e;       // 将数据e赋值给新节点的数据域
    s->next = p->next; // 将新节点的next指针指向p节点的next指针指向的节点
    p->next = s;       // 将p节点的next指针指向新节点
    return true;
}

bool InsertPriorNode(LNode *p, int e) // 在p节点之前插入新节点
{
    if (p == NULL)
    { // p节点不存在
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode)); // 分配一个新节点
    if (s == NULL)
    { // 内存不足，分配失败
        return false;
    }
    s->next = p->next; // 将新节点的next指针指向p节点的next指针指向的节点
    p->next = s;       // 将p节点的next指针指向新节点
    s->data = p->data; // 将p节点的数据域的值赋值给新节点的数据域
    p->data = e;       // 将数据e赋值给p节点的数据域
    return true;
}

bool ListDelete(LinkList &L, int i, int &e) // 删除单链表的第i个节点
{
    if (i < 1)
    { // i值不合法
        return false;
    }
    LNode *p;  // 声明一个指向节点的指针
    int j = 0; // 当前p指向的是第几个节点
    p = L;     // 让p指向头节点，由于头节点是第0个节点，所以p指向第0个节点
    while (p != NULL && j < i - 1)
    { // 寻找第i-1个节点
        p = p->next;
        j++;
    }
    if (p == NULL)
    { // i值不合法
        return false;
    }
    if (p->next == NULL)
    { // 第i-1个节点之后已经没有节点了，即第i个节点不存在
        return false;
    }
    LNode *q = p->next; // 声明一个指向节点的指针，指向第i个节点
    e = q->data;        // 将第i个节点的数据域的值赋值给e
    p->next = q->next;  // 将第i-1个节点的next指针指向第i+1个节点
    free(q);            // 释放第i个节点的内存空间，防止内存泄漏
    return true;
}

bool DeleteNode(LNode *p) // 删除p节点
{
    if (p == NULL)
    { // p节点不存在
        return false;
    }
    LNode *q = p->next; // 声明一个指向节点的指针，指向p节点的下一个节点
    p->data = q->data;  // 将p节点的下一个节点的数据域的值赋值给p节点的数据域
    p->next = q->next;  // 将p节点的next指针指向p节点的下一个节点的next指针指向的节点
    free(q);            // 释放p节点的下一个节点的内存空间，防止内存泄漏
    return true;
}

int main()
{
    LinkList L;          // 声明一个指向节点的指针
    InitList(L);         // 初始化单链表
    ListInsert(L, 1, 1); // 在单链表的第1个位置插入元素1
    ListInsert(L, 2, 2); // 在单链表的第1个位置插入元素2
    ListInsert(L, 3, 3); // 在单链表的第1个位置插入元素3
    ListInsert(L, 4, 4); // 在单链表的第1个位置插入元素4

    return 0;
}
