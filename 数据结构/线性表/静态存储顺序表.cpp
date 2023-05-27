#include <stdio.h>

#define MaxSize 10 // 定义最大长度

typedef struct
{
	int data[MaxSize]; // 以数组的形式静态存储
	int len;		   // 顺序表当前的长度
} sql;				   // 顺序表的类型定义

void InitList(sql &L)
{ // 初始化表
	for (int i = 0; i <= MaxSize; i++)
		L.data[i] = 0;
	L.len = 0;
}

int main()
{
	sql L;
	InitList(L);
	//...
	return 0;
}