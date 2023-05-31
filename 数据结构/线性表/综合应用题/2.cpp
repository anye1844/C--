/*设计一个高效算法，将顺序表L的所有元素逆置，要求算法的空间复杂度为O(1)。
 */
/* 官方答案 */
/* void Reverse(SqList &L)
{
    int temp;
    for (int i = 0; i < L.len / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.len - i - 1];
        L.data[L.len - i - 1] = temp;
    }
} */
/* 我的答案 */

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

void UnderList(SqList &L)
{
    int temp;
    for (int i = 0; i < L.len / 2; i++)
    {
        temp = L.data[i];
        L.data[i] = L.data[L.len - i - 1];
        L.data[L.len - i - 1] = temp;
        
    }
}

int main()
{
    SqList L;
    InitList(L);
    ListInsert(L, 1, 9);
    ListInsert(L, 2, 8);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 6);
    ListInsert(L, 5, 5);
    ListInsert(L, 6, 4);
    ListInsert(L, 7, 3);

    for (int i = 0; i < L.len; i++)
        cout << L.data[i] << " ";
    cout << endl;

    UnderList(L);

    for (int i = 0; i < L.len; i++)
        cout << L.data[i] << " ";
    return 0;
}
