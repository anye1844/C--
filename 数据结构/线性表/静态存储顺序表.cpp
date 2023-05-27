#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct
{
	int data[MaxSize]; // 以数组的形式静态存储
	int len;		   // 顺序表当前的长度
} sql;				   // 顺序表的类型定义

void InitList(sql &L)
{									  // 初始化表
	for (int i = 0; i < MaxSize; i++) // 可以省略但不规范
		// for (int i = 0; i < L.len; i++) 优化写法，只为表长度内的数据初始化值
		L.data[i] = 0;
	L.len = 0;
}

void ListInsert(sql &L, int i, int e)
{									 // 插入操作
	for (int v = L.len; v >= i; v--) // 从最后一位开始顺位后移
		L.data[v] = L.data[v - 1];
	L.data[i - 1] = e; // 在表L中第i个位置插入新元素e
	L.len++;		   // 表长度加1
}

int main()
{
	sql L;
	InitList(L);
	ListInsert(L, 3, 3);
	//...
	return 0;
}