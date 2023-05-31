#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct LNode // 定义一个单链表数据结构
{
    int data;           // 数据域
    struct LNode *next; // 指针域
} LNode, *LinkList;     // LNode为节点名，LinkList为指向节点的指针

bool InitList(LinkList &L) // 初始化单链表
{
    L = NULL;    // 将指针置空
    return true; // 初始化成功
}

bool Empty(LinkList L) // 判断单链表是否为空
{
    return (L == NULL); // 如果为空返回true，否则返回false
}

bool ListInsert(LinkList &L, int i, int e)
{
    if (i < 1)
        return false;
    if (i = 1)
    {
        LNode *p = (LNode *)malloc(sizeof(LNode));
        p->data = e;
        p->next = L;
        L = p;
        return true;
    }
    int j = 1;
    LNode *p = L;
    while (L != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL)
        return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int main()
{
    LinkList L;               // 声明一个指向节点的指针
    InitList(L);              // 初始化单链表
    cout << Empty(L) << endl; // 判断单链表是否为空
    return 0;
}