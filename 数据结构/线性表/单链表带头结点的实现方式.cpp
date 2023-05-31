#include<iostream>
#include<stdlib.h>
using namespace std;

typedef struct LNode{//定义一个单链表数据结构
    int data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L){//初始化单链表
    L = (LNode *)malloc(sizeof(LNode));//分配一个头节点
    if(L == NULL){//内存不足，分配失败
        return false;
    }
    L->next = NULL;//头节点之后暂时还没有节点，所以暂时指向NULL
    return true;
}

bool Empty(LinkList L){//判断单链表是否为空
    return (L->next == NULL);//如果为空返回true，否则返回false
}

int main(){
    LinkList L;//声明一个指向节点的指针
    InitList(L);//初始化单链表
    cout << Empty(L) << endl;//判断单链表是否为空
    return 0;
}