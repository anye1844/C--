#include <stdlib.h>
#include <iostream>
using namespace std;

#define InitSize 10 // �����ʼ����
typedef struct
{
	int *data;	 // ָʾ��̬���������ָ��
	int MaxSize; // ˳�����������
	int len;	 // ˳���ǰ�ĳ���
} SqList;			 // ˳�������Ͷ���

void InitList(SqList &L) // ��ʼ����
{
	// ��malloc��������һƬ�����Ĵ洢�ռ�
	L.data = (int *)malloc(InitSize * sizeof(int)); // C����ʹ��malloc��������ռ�
	// L.data = new int[InitSize];		//C++ʹ��new���������ռ�
	L.len = 0;
	L.MaxSize = InitSize;
}

