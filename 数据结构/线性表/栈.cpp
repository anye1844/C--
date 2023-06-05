// 栈的基本操作：
/*
InitStack(&S) 初始化栈。构造一个空栈S，分配内存空间。
DestroyStack(&S) 销毁栈。销毁栈S，释放内存空间。
Push(&S,x) 入栈，若栈S未满，则将x加入使之成为新栈顶。
Pop(&S,&x) 出栈，若栈S非空，则弹出栈顶元素，并用x返回。
GetTop(S,&x) 读栈顶元素，若栈S非空，则用x返回S的栈顶元素。
StackEmpty(S) 判断栈空，若栈S为空，则返回true，否则返回false。
*/
#include <iostream>
using namespace std;

#define MaxSize 10 // 定义栈中元素的最大个数
typedef struct
{
    int data[MaxSize]; // 用静态数组存放栈中元素
    int top;           // 栈顶指针
} SqStack;

void InitStack(SqStack &S) // 初始化栈
{
    S.top = -1; // 初始化栈顶指针
}

bool StackEmpty(SqStack S) // 判断栈空
{
    if (S.top == -1)
        return true;
    else
        return false;
}

bool Push(SqStack &S, int x) // 入栈
{
    if (S.top == MaxSize - 1) // 栈满的判断
        return false;
    S.data[++S.top] = x; // 将新插入元素赋值给栈顶空间
    return true;
}

bool Pop(SqStack &S, int &x) // 出栈
{
    if (S.top == -1) // 栈空的判断
        return false;
    x = S.data[S.top--]; // 将栈顶元素赋值给x
    return true;
}

bool GetTop(SqStack S, int &x) // 读取栈顶元素
{
    if (S.top == -1) // 栈空的判断
        return false;
    x = S.data[S.top]; // 将栈顶元素赋值给x
    return true;
}




