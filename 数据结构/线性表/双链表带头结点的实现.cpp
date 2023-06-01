#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct DNode // 双链表结点的结构
{
	int data;			 // 数据域
	struct DNode *prior; // 指向前驱的指针
	struct DNode *next;	 // 指向后继的指针
} DNode, *DLinklist;	 // 双链表的类型

bool InitDLinkList(DLinklist &L) // 初始化双链表
{
	L = (DNode *)malloc(sizeof(DNode)); // 分配一个头结点
	if (L == NULL)
		return false; // 内存不足，分配失败
	L->prior = NULL;  // 头结点的prior永远指向NULL
	L->next = NULL;	  // 头结点之后暂时还没有结点
	return true;
}

bool Empty(DLinklist L) // 判断双链表是否为空
{
	return L->next == NULL;
}

bool InsertNextDNode(DNode *p, DNode *s) // 在p结点之后插入s结点
{
	if (p == NULL || s == NULL)
		return false;
	s->next = p->next;
	if (p->next != NULL)
		p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}

bool DeleteNextDNode(DNode *p) // 删除p结点的后继结点
{
	if (p == NULL)
		return false;
	DNode *q = p->next;
	if (q == NULL)
		return false;
	p->next = q->next;
	if (q->next != NULL)
		q->next->prior = p;
	free(q);
	return true;
}

bool InsertPriorDNode(DNode *p, DNode *s) // 在p结点之前插入s结点
{
	if (p == NULL || s == NULL) // p或s为空
		return false;			// 插入失败
	s->prior = p->prior;		// s的前驱为p的前驱
	if (p->prior != NULL)		// p的前驱不为空
		p->prior->next = s;		// p的前驱的后继为s
	s->next = p;				// s的后继为p
	p->prior = s;				// p的前驱为s
	return true;
}

bool DeletePriorDNode(DNode *p) // 删除p结点的前驱结点
{
	if (p == NULL) // p为空
		return false;
	DNode *q = p->prior; // q为p的前驱
	if (q == NULL)		 // q为空
		return false;
	p->prior = q->prior;	// p的前驱为q的前驱
	if (q->prior != NULL)	// q的前驱不为空
		q->prior->next = p; // q的前驱的后继为p
	free(q);				// 释放q结点
	return true;
}

DNode *GetElem(DLinklist L, int i) // 按序号查找
{
	if (i < 0)
		return NULL;
	DNode *p = L; // 头结点也算一个结点，头结点的序号为0
	int j = 0;	  // 当前p指向的是第几个结点
	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

DNode *LocateElem(DLinklist L, int e) // 按值查找
{
	DNode *p = L->next; // p指向第一个结点
	while (p != NULL && p->data != e)
		p = p->next;
	return p;
}

void DestroyList(DLinklist &L) // 销毁双链表
{
	while (L != NULL)
	{
		DNode *p = L;
		L = L->next;
		free(p);
	}
}

int main()
{

	return 0;
}
