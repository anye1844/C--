#include <stdio.h>

#define MaxSize 10 // ������󳤶�

typedef struct
{
	int data[MaxSize]; // ���������ʽ��̬�洢
	int len;		   // ˳���ǰ�ĳ���
} sql;				   // ˳�������Ͷ���

void InitList(sql &L)
{ // ��ʼ����
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