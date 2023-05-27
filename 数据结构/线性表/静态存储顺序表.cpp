#include <stdio.h>
#include <iostream>
using namespace std;

#define MaxSize 10 // ������󳤶�

typedef struct
{
	int data[MaxSize]; // ���������ʽ��̬�洢
	int len;		   // ˳���ǰ�ĳ���
} sql;				   // ˳�������Ͷ���

void InitList(sql &L)
{									  // ��ʼ����
	for (int i = 0; i < MaxSize; i++) // ����ʡ�Ե����淶
		// for (int i = 0; i < L.len; i++) �Ż�д����ֻΪ�����ڵ����ݳ�ʼ��ֵ
		L.data[i] = 0;
	L.len = 0;
}

bool ListInsert(sql &L, int i, int e)
{ // �������
	/*��ԭ������ôд�ģ�������Ӧ��Ҳ����ʵ�ָò���
	if (i <= L.len && i > 0 && L.len < MaxSize)
	{									 // �ж�i�Ƿ�Ϸ�
		for (int v = L.len; v >= i; v--) // �����һλ��ʼ˳λ����
			L.data[v] = L.data[v - 1];
		L.data[i - 1] = e; // �ڱ�L�е�i��λ�ò�����Ԫ��e
		L.len++;		   // ���ȼ�1
		return true;
	}
	else
	{
		return false;
	}*/

	// ��������ôд�ģ�ä������д�ĺô��ǣ����Խ��Ƿ���������ز�ͬ��ֵ���Թ��������ж�
	if (i < 1 || i > L.len + 1) // �ж�i�Ƿ�Ϸ�
		return false;
	if (L.len >= MaxSize) // �жϴ洢�ռ��Ƿ�����
		return false;
	for (int j = L.len; j >= i; j--) // �����һλ��ʼ˳λ����
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e; // �ڱ�L�е�i��λ�ò�����Ԫ��e
	L.len++;		   // ���ȼ�1
	return true;
}

bool ListDelete(sql &L, int i, int &e)
{							// ɾ��������ɾ����L�е�i��λ�õ�Ԫ�أ�����e������ֵ
	if (i < 1 || i > L.len) // �ж�i�Ƿ�Ϸ�
		return false;
	e = L.data[i - 1]; // ����ɾ����Ԫ�ظ�ֵ��e
	for (int j = i; j < L.len; j++)
		L.data[j - 1] = L.data[j]; // ����i��λ�ú��Ԫ��ǰ��
	L.len--;					   // ���ȼ�1
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
