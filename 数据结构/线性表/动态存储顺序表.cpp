#include <stdlib.h>
#include <iostream>
using namespace std;

#define InitSize 10 // �����ʼ����

typedef struct
{
	int *data;	 // ָʾ��̬���������ָ��
	int MaxSize; // ˳�����������
	int len;	 // ˳���ǰ�ĳ���
} sql;			 // ˳�������Ͷ���

void InitList(sql &L) // ��ʼ����
{
	// ��malloc��������һƬ�����Ĵ洢�ռ�
	L.data = (int *)malloc(InitSize * sizeof(int)); // C����ʹ��malloc��������ռ�
	// L.data = new int[InitSize];		//C++ʹ��new���������ռ�
	L.len = 0;
	L.MaxSize = InitSize;
}

bool ListInsert(sql &L, int i, int e) // �������
{
	if (i < 1 || i > L.len + 1) // �ж�i�ķ�Χ�Ƿ���Ч
		return false;
	if (L.len >= L.MaxSize) // ��ǰ�洢�ռ����������ܲ���
		return false;
	for (int j = L.len; j >= i; j--) // ����i��Ԫ�ؼ�֮���Ԫ�غ���
		L.data[j] = L.data[j - 1];
	L.data[i - 1] = e; // ��λ��i������e
	L.len++;		   // ����1
	return true;
}

bool ListDelete(sql &L, int i, int &e) // ɾ������
{
	if (i < 1 || i > L.len) // �ж�i�ķ�Χ�Ƿ���Ч
		return false;
	e = L.data[i - 1];				// ����ɾ����Ԫ�ظ�ֵ��e
	for (int j = i; j < L.len; j++) // ����i��λ�ú��Ԫ��ǰ��
		L.data[j - 1] = L.data[j];
	L.len--; // ����1
	return true;
}

int GetElem(sql L, int i) // ��λ���Ҳ���
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
