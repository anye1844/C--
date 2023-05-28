/* 从顺序表中删除具有最小值的元素（假设唯一），并由函数返回被删除元素的值。空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行。 */

/* 官方答案 */
/*
bool Del_Min(SqList &L, ElemType &value)
{
    // 删除顺序表中最小值元素结点，并通过引用型参数value返回其值
    // 若删除成功，返回true，否则返回false
    if (L.length == 0)
        return false;                   // 顺序表为空，返回false
    value = L.data[0];                  // 假设第一个元素最小
    int pos = 0;                        // 记录最小元素位置
    for (int i = 1; i < L.length; i++)  // 循环，查找最小元素
        if (L.data[i] < value)          // 若当前元素更小
            value = L.data[i], pos = i; // 更新最小值和位置
    L.data[pos] = L.data[L.length - 1]; // 最后元素填补空位
    L.length--;                         // 表长减1
    return true;                        // 删除成功
} */

/* 个人答案 */
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