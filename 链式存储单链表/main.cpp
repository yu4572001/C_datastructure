#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//定义一个结构体
typedef int ElemType;
typedef struct LNode
{
	ElemType data;             //定义链表中数据域与指针域
	struct LNode* next;
}LNode,*LinkList;         //LNode*(结构体名)为一个结点，LiskList(结构体指针)为整个链表



//头插法建表
LinkList CreateListHead(LinkList& L)     //&为引用符，要改变L的值就加，不改变就不加
{	
	//定义一个结构体中的结点为s，数据域为x 
	LNode* s;    
	int x;        

	L = (LNode*)malloc(sizeof(LNode));     //定义一个结点L为头结点
	L->next = NULL;           //头结点L后面为空
	scanf("%d", &x);            //输入的值赋值给x
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;        //将输入的值赋给s的data
		s->next = L->next;           //将s指向的元素改为之前L指向的元素
		L->next = s;            //将L指向的元素改为s
		scanf("%d", &x);      //再次循环输入一个数字，直到输入9999结束
	}
	return L;
}



//尾插法建表
LinkList CreateListTail(LinkList &L)         //返回类型为一个结构体指针，即链表
{
	int x;           //x为插入的data数据
	L = (LNode*)malloc(sizeof(LNode));    //定义一个结构体结点L为头结点
	LNode* s, * r;         //定义两个结构体中结点，s为新插入的结点，r为尾节点
	s = r = L;          //让r尾结点，s都指向L头结点，因为此时链表就一个头结点
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));        //申请一个结点大小的空间
		s->data = x;
		r->next = s;       //尾结点r指向s，s成为了尾结点
		r = s;             //赋值给r，让s再次成为尾结点
		scanf("%d", &x);
	}
	r->next = NULL;              //让尾结点的next为空，结束这个链表
	return L;              //返回L链表
}



//查找对应位置结点的值
LNode* GetElem(LinkList L, int i) {
	if (i == 0) {
		return L; 
	}
	else if (i < 0) {
		return NULL;
	}
	LNode* p = L->next;         //定义链表中第一个结点为p
	int j = 1;
	while (p != NULL && j < i) {    //判断p结点不为空，且不能超过第i个结点
		p = p->next;        //让p指向下一个结点
		j++;
	}
	return p;         //返回此结点

}



//按值进行查找
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;       //定义链表中第一个结点为p
	while (p != NULL && p->data != e) {	          //如果匹配到p-data等于e,则跳出循环，返回p结点
		p = p->next;        //让p指向下一个结点 
	}
	return p;    //返回查找到的该结点
}



//往第i个位置插入元素
bool ListFrontInsert(LinkList &L, int i, ElemType e) {
	LNode* p = GetElem(L, i - 1);        //得到要插入的第i个位置的前一个结点，GetElem()为前面写的函数
	if (p == NULL) {          //判断前一个结点不为空
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));          //申请新空间结点s
	s->data = e;
	s->next = p->next;             //顺序不能反
	p->next = s;
	return true;
}



//删除第i个位置的结点
bool ListDelete(LinkList& L, int i) {
	LNode* p = GetElem(L, i - 1);          //得到结点i的前驱结点
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;         //定义要删除的结点为q
	if (q == NULL) {       //判断要删除的结点是否为空
		return false;
	}
	p->next = q->next;          //断链操作
	free(q);        //释放删除结点的空间
	q == NULL;         //为了避免野指针
	return true;
}



//打印链表
void PrintLink(LinkList L)
{
	printf("=============链表如下：\n");
	L = L->next;            //将第一个元素的next赋给L
	while (L != NULL) {       //只要L->next不为空就循环打印
		printf("%3d", L->data);
		L = L->next;         //将下一个元素的next赋给L
	}
	printf("\n");
}





int main()
{
	LinkList L;          //定义一个结构体指针(链表)
	LNode* search;          //定义一个结点，用来接受查找到返回的值
	//CreateListHead(L);          //头插法建表
	CreateListTail(L);          //输入 1 2 3 4 5 6 9999

	PrintLink(L);       //打印链表


	search = GetElem(L, 2);          //调用查找
	if (search != NULL) {
		printf("==============按序号查找如下：\n");
		printf("第2个位置的值为：%d\n",search->data);
	}
	else {
		printf("查找有误!");
	}

	search = LocateElem(L, 23);
	if (search != NULL) {
		printf("==============按值查找如下：\n");
		printf("链表中存在该值：%d\n", search->data);
	}
	else {
		printf("查找有误!");
	}


	ListFrontInsert(L, 2, 99);      //插入元素
	PrintLink(L);


	ListDelete(L, 2);           //删除第二个元素
	PrintLink(L);

}