/* ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�������ɺ������ر�ɾ��Ԫ�ص�ֵ���ճ���λ�������һ��Ԫ�������˳���Ϊ������ʾ������Ϣ���˳����С� */

/* �ٷ��� */
/*
bool Del_Min(SqList &L, ElemType &value)
{
    // ɾ��˳�������СֵԪ�ؽ�㣬��ͨ�������Ͳ���value������ֵ
    // ��ɾ���ɹ�������true�����򷵻�false
    if (L.length == 0)
        return false;                   // ˳���Ϊ�գ�����false
    value = L.data[0];                  // �����һ��Ԫ����С
    int pos = 0;                        // ��¼��СԪ��λ��
    for (int i = 1; i < L.length; i++)  // ѭ����������СԪ��
        if (L.data[i] < value)          // ����ǰԪ�ظ�С
            value = L.data[i], pos = i; // ������Сֵ��λ��
    L.data[pos] = L.data[L.length - 1]; // ���Ԫ�����λ
    L.length--;                         // ����1
    return true;                        // ɾ���ɹ�
} */

/* ���˴� */
/* bool DelListMin(SqList &L, int &Del)
{
    if (L.len == 0)
        return false;
    Del = L.data[0];
    int Del_ = 0;
    for (int i = 1; i < L.len; i++)
        if (L.data[i] < Del)
            Del = L.data[i], Del_ = i;
    L.data[Del_] = L.data[L.len - 1];
    L.len--;
    return true;
} */

#include <iostream>
using namespace std;

#define MaxSize 10
typedef struct
{
    int data[MaxSize];
    int len;
} SqList;

void InitList(SqList &L)
{
    for (int i = 0; i < L.len; i++)
        L.data[i] = 0;
    L.len = 0;
}

bool ListInsert(SqList &L, int i, int e)
{
    if (i < 1 || i > L.len + 1)
        return false;
    if (L.len >= MaxSize)
        return false;
    for (int j = L.len; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.len++;
    return true;
}

bool DelListMin(SqList &L, int &Del)
{
    if (L.len == 0)
        return false;
    Del = L.data[0];
    int Del_ = 0;
    for (int i = 1; i < L.len; i++)
        if (L.data[i] < Del)
            Del = L.data[i], Del_ = i;
    L.data[Del_] = L.data[L.len - 1];
    L.len--;
    return true;
}

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 9);
    ListInsert(L, 2, 8);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 7);
    ListInsert(L, 5, 1);
    ListInsert(L, 6, 9);
    ListInsert(L, 7, 2);
    cout << L.len << endl;
    for (int i = 0; i < L.len; i++)
        cout << L.data[i] << " ";
    cout << endl;
    int a;
    DelListMin(L, a);
    cout << a << endl;
    for (int i = 0; i < L.len; i++)
        cout << L.data[i] << " ";
    return 0;
}