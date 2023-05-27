#include <stdio.h>

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

int main()
{
	sql L;
	InitList(L);
	ListInsert(L, 3, 3);
	//...
	return 0;
}