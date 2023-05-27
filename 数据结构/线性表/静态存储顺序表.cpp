#include <stdio.h>
#include <iostream>
using namespace std;

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

bool ListInsert(sql &L, int i, int e)
{ // 插入操作
	/*我原本是这么写的，理论上应该也可以实现该操作
	if (i <= L.len && i > 0 && L.len < MaxSize)
	{									 // 判断i是否合法
		for (int v = L.len; v >= i; v--) // 从最后一位开始顺位后移
			L.data[v] = L.data[v - 1];
		L.data[i - 1] = e; // 在表L中第i个位置插入新元素e
		L.len++;		   // 表长度加1
		return true;
	}
	else
	{
		return false;
	}*/

	// 大佬是这么写的，盲猜这样写的好处是，可以将非法的情况返回不同的值，以供调用者判断
	if (i < 1 || i > L.len + 1) // 判断i是否合法
		return false;
	if (L.len >= MaxSize) // 判断存储空间是否已满
		return false;
	for (int j = L.len; j >= i; j--) // 从最后一位开始顺位后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e; // 在表L中第i个位置插入新元素e
	L.len++;		   // 表长度加1
	return true;
}

bool ListDelete(sql &L, int i, int &e)
{							// 删除操作，删除表L中第i个位置的元素，并用e返回其值
	if (i < 1 || i > L.len) // 判断i是否合法
		return false;
	e = L.data[i - 1]; // 将被删除的元素赋值给e
	for (int j = i; j < L.len; j++)
		L.data[j - 1] = L.data[j]; // 将第i个位置后的元素前移
	L.len--;					   // 表长度减1
	return true;
}
int main()
{
	sql L;
	InitList(L);
	ListInsert(L, 1, 9);
	ListInsert(L, 2, 8);
	ListInsert(L, 3, 7);
	int num;
	ListDelete(L, 3, num);
	//...
	return 0;
}
