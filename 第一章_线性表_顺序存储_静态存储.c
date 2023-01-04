#include <stdio.h>
#define MaxSize 10   // 表最大长度

/*
name: 线性表逻辑结构 顺序存储结构 静态存储
time: 2023.1.3
author: xskj
*/;



typedef enum Bool {
	False=0, True=1
}Bool;

typedef int ElemType;


// 定义数据类型
typedef struct
{
	int data[MaxSize]; // 存储数据元素
	int length;		   // 表当前长度
} SqlList;


// 1.初始化顺序表: 指定为指针类型用于改变其值
void InitList(SqlList *L)
{
	for (int i = 0; i < MaxSize; i++)
        L->data[i] = 0; // 全部初始化为初值0
}

// 2.打印输出顺序表中的元素
void PrintSqlList(SqlList L, int Length)
{
	for (int i = 0; i < Length; i++)
		printf("第%d元素: %d \n", i + 1, L.data[i]);
}

// 3.插入操作
Bool ListInsert(SqlList *L, int i , int e) {

	//判断位序是否合法
	if (i <= 0 || i > L->length +1) return False;

	//检查当前存储空间是否已经存储满
	if (L->length > MaxSize) return False;

	//插入
	for (int j = L->length; j >= i; j--)
		L->data[j] = L->data[j - 1];

	//存放数据
	L->data[i-1] = e;

	//length加1
	L->length++;

	return True;
}


//4.删除操作
Bool ListDelete(SqlList* L, int i, int* e) {

	//位序校验
	if (i<1 || i>L->length) return False;

	//保存删除的元素
	*e = L->data[i - 1];

	//元素移动
	for (int j = i; j  < L->length+1; j++)
		L->data[j-1] = L->data[j];

	//长度-1
	L->length--;

	return True;
}

//5.查找操作--->按值查找
ElemType LocateElem(SqlList* L, ElemType e) {
	
	for (int i = 0; i < L->length; i++)
		if (L->data[i] == e) return i + 1;

	return 0;
}

//5.查找操作---> 位序查找
ElemType GetElem(SqlList* L, int i) {
	//位序校验
	if (i<1 || i>L->length) return 0;

	return L->data[i - 1];

}


int main()
{
	// 1.实例化一个顺序表:此时会开辟一块内存空间
	SqlList L;
	L.length = 0;
	// 2.初始化L顺序表
	InitList(&L);
	// 3.插入操作
	for (int i = 0; i < 10; i++)
		ListInsert(&L, i, i);
	//4.删除操作
	int e;
	ListDelete(&L, 5, &e);
	printf("删除的元素: %d\n", e);
	//5.查找操作--->按值查找
	
	int e1 = 4;
	int i = LocateElem(&L, e1);
	printf("位序为:%d   查到结果为: %d\n", i, e1);

	//5.查找操作--->按位序查找
	int i1 = 10;
	ElemType e2 = GetElem(&L, i1);
	printf("位序为:%d   查到结果为: %d\n", i1, e2);
	

	// 打印输出
	PrintSqlList(L, MaxSize);
	return 0;
}