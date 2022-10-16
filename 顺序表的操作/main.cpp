#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50        //定义一个常量，顺序表的最大空间
typedef int ElemType;         //顺序表中的元素类型，起别名，方便统一修改表中的元素类型
//初始化
typedef struct {       //定义一个结构体
	ElemType data[MaxSize];         //定义的数组，用来存元素
	int length;             //当前顺序表有多少个元素
}SqList;


bool InsertList(SqList &L, int i, ElemType e)   //传入实参，L要取地址&,指向同一个数组空间才能修改
{
	if (i<1 || i>L.length + 1) {        //判断插入位置是否合法
		return false;
	}
	if (L.length >= MaxSize) {          //判断当前表是否表满
		return false;
	}
	for (int j = L.length; j >= i; j--) {          //移动表中的元素，依次往后移动	
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;        //当前要插入元素位置的下标     插入e
	L.length++;            //表长度加1
	return true;       //返回true代表插入成功
}



//删除操作
bool DeleteList(SqList &L, int i, ElemType &e)     //这里的e接的是地址，跟传入的实参指向同一片空间以改变其值
{
	if (i < 1 || i > L.length + 1) {      //判断删除位置是否合法
		return false;
	}
	if (L.length == 0) {         //判断表中是否空表，空表无需删除
		return false;
	}
	e = L.data[i - 1];      //将要删除的元素赋给e，即函数外面的del
	for (int j = i; j < L.length; j++) {        //从i的位置依次把元素往前覆盖
		L.data[j - 1] = L.data[j];
	}
	L.length--;             //表长度减1
	return true;
}


//查找操作,成功返回位置，位置从1开始，查找失败返回0
int LocateList(SqList L, ElemType e)
{
	int i;
	for (int i = 0; i < L.length; i++) {      //遍历顺序表
		if (L.data[i] == e) {
			return i + 1;       //返回该元素的下标
		}
	}
	return 0;      //没有找到返回0
}




//打印当前表元素
void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++) {
		printf("%4d", L.data[i]);
	}
	printf("\n");
}



int main()
{    //顺序表的名称，即结构体变量
	SqList L;
	bool ret;            //定义返回值，为布尔类型
	ElemType del;        //定义一个删除变量
	//手动在顺序表中赋值
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;          //当前表中元素个数为3

	printf("===============================\n");
	//调用插入函数，把100插入第二个位置
	ret = InsertList(L, 2, 100);         
	if (ret) {
		printf("元素插入成功！\n");
		PrintList(L);            //打印
	}
	else {
		printf("元素插入失败！\n");
		PrintList(L);
	}

	printf("===============================\n");
	//调用删除，把第二个元素删除并返回该值
	ret = DeleteList(L, 2, del);
	if (ret) {
		printf("元素删除成功！\n");
		printf("删除的元素为：%d\n",del);
		PrintList(L);
	}
	else {
		printf("元素删除失败！\n");
	}

	printf("===============================\n");
	//调用查找函数，找到并返回该值下标
	int elem_pos;
	elem_pos = LocateList(L, 3);
	if (elem_pos) {
		printf("查找成功\n");
		printf("元素位置为：%d", elem_pos);
	}
	else {
		printf("查找失败\n");
	}
	return 0;
}

