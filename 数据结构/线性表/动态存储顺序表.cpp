#include <stdlib.h>
#include <iostream>
using namespace std;

#define InitSize 10 // 定义初始长度

typedef struct
{
	int *data;	 // 指示动态分配数组的指针
	int MaxSize; // 顺序表的最大容量
	int len;	 // 顺序表当前的长度
} sql;			 // 顺序表的类型定义

void InitList(sql &L) // 初始化表
{
	// 用malloc函数申请一片连续的存储空间
	L.data = (int *)malloc(InitSize * sizeof(int)); // C语言使用malloc函数申请空间
	// L.data = new int[InitSize];		//C++使用new运算符申请空间
	L.len = 0;
	L.MaxSize = InitSize;
}

bool ListInsert(sql &L, int i, int e) // 插入操作
{
	if (i < 1 || i > L.len + 1) // 判断i的范围是否有效
		return false;
	if (L.len >= L.MaxSize) // 当前存储空间已满，不能插入
		return false;
	for (int j = L.len; j >= i; j--) // 将第i个元素及之后的元素后移
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e; // 在位置i处放入e
	L.len++;		   // 表长增1
	return true;
}

bool ListDelete(sql &L, int i, int &e) // 删除操作
{
	if (i < 1 || i > L.len) // 判断i的范围是否有效
		return false;
	e = L.data[i - 1];				// 将被删除的元素赋值给e
	for (int j = i; j < L.len; j++) // 将第i个位置后的元素前移
		L.data[j - 1] = L.data[j];
	L.len--; // 表长减1
	return true;
}

int GetElem(sql L, int i) // 按位查找操作
{
	return L.data[i - 1];
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
	cout << num << endl;
	cout << GetElem(L, 2) << endl;
	//...
	return 0;
}
