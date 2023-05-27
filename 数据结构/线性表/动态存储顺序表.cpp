#include<stdlib.h>

#define InitSize 10		//定义初始长度 

typedef struct{	
	int *data;			//指示动态分配数组的指针 
	int MaxSize;		//顺序表的最大容量 
	int len;			//顺序表当前的长度 
}sql;					//顺序表的类型定义 

void InitList(sql &L){		//初始化表 
	//用malloc函数申请一片连续的存储空间
	L.data = (int *)malloc(InitSize*sizeof(int));	//C语言使用malloc函数申请空间
	//L.data = new int[InitSize];		//C++使用new运算符申请空间
	L.len=0;
	L.MaxSize=InitSize;
}	

int main(){
	sql L;
	InitList(L);
	//...
	return 0; 
}