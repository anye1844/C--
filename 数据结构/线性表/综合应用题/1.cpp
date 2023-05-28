/* 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。 */
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
    if (i < 0 || i > L.len)
        return false;
    if (L.len >= MaxSize)
        return false;
    for (int j = L.len - 1; j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.len++;
    return true;
}

int main()
{
    SqList L;
    ListInsert(L, 1, 9);
    ListInsert(L, 2, 8);
    ListInsert(L, 3, 7);
    ListInsert(L, 4, 6);
    ListInsert(L, 5, 5);
    ListInsert(L, 6, 4);
    ListInsert(L, 7, 3);
    cout<<L.len<<endl;
    for (int i = 0; i < L.len; i++)
        cout << L.data[i] << " ";
    return 0;
}