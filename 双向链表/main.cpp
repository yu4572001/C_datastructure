#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//定义结构体
typedef int ElemType;
typedef struct DNode {
	ElemType data;        //数据域
	struct DNode* prior;          //前驱指针
	struct DNode* next;           //后继指针

}DNode, * DLinkList;


//头插法建表
DLinkList Dlist_head_insert(DLinkList& DL) {
	DNode* s;        //定义一个结构体中的结点为s，数据域为x 
	int e;
	DL = (DNode*)malloc(sizeof(DNode));      //定义一个结点DL为头结点
	DL->next = NULL;           //头结点的前驱和后继都为NULL
	DL->prior = NULL;
	scanf("%d", &e);
	while (e != 9999) {
		s = (DNode*)malloc(sizeof(DNode));       //申请空间
		s->data = e;
		s->next = DL->next;
		if (DL->next != NULL) {
			DL->next->prior = s;
		}
		s->prior = DL;
		DL->next = s;
		scanf("%d", &e);
	}
	return DL;
}



//尾插法建表
DLinkList Dlist_tail_insert(DLinkList& DL) {
	int x;
	DL = (DNode*)malloc(sizeof(DNode));      //定义一个结点DL为头结点
	DNode* s, * r;
	s = r = DL;
	DL->prior = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));       //申请空间
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;              //r指向新的尾结点，即尾结点为刚插入的元素
		scanf("%d", &x);
	}
	r->next = NULL;               //定义尾结点的next尾空
	return DL;
}



//查找对应位置结点的值
DNode* GetElem(DLinkList DL, int i) {
	if (i == 0) {
		return DL;
	}
	else if (i < 0) {
		return NULL;
	}
	DNode* p = DL->next;         //定义链表中第一个结点为p
	int j = 1;
	while (p != NULL && j < i) {    //判断p结点不为空，且不能超过第i个结点
		p = p->next;        //让p指向下一个结点
		j++;
	}
	return p;         //返回此结点

}



//往第i个位置插入元素
bool DListFrontInsert(DLinkList &DL, int i, ElemType e) {
	DNode* p = GetElem(DL, i - 1);        //得到要插入的第i个位置的前一个结点，GetElem()为前面写的函数
	if (p == NULL) {          //判断前一个结点不为空
		return false;
	}
	DNode* s = (DNode*)malloc(sizeof(DNode));          //申请新空间结点s
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}


//删除第i个结点
bool DListDelete(DLinkList &DL,int i) {
	DNode* p = GetElem(DL, i - 1);    //p为要删除的结点的前一个结点
	if (p == NULL) {        //判断前一个结点不为空
		return false;
	}
	DNode *q = p->next;             //q为要删除的结点
	if (q == NULL) {          //判断q是否为空
		return false;
	}
	if (q->next != NULL) {      //判断q后面还有没有元素，是否为尾结点
		p->next = q->next;
		q->next->prior = p;
		free(q);
	}
	else {
		free(q);      //如果q为尾结点，直接释放q，p成为尾结点
		p->next = NULL;
	}
	q = NULL;
	return true;
	

}




//打印链表
void PrintDLink(DLinkList DL)
{
	printf("=============双向链表如下：\n");
	DL = DL->next;            //将第一个元素的next赋给L
	while (DL != NULL) {       //只要L->next不为空就循环打印
		printf("%3d", DL->data);
		DL = DL->next;         //将下一个元素的next赋给L
	}
	printf("\n");
}



int main() {
	DLinkList DL;
	DNode* search;

	//Dlist_head_insert(DL);      //头插法
	Dlist_tail_insert(DL);        //尾插法   1 2 3 4 5 6 9999
	PrintDLink(DL);            //输出打印

	search = GetElem(DL, 2);        //调用查找
	if (search != NULL) {
		printf("==============按序号查找如下：\n");
		printf("第2个位置的值为：%d\n", search->data);
	}
	else {
		printf("查找有误!");
	}


	DListFrontInsert(DL, 2, 99);    //在链表第二个位置插入99
	PrintDLink(DL);

	DListDelete(DL, 2);           //删除第二个元素99
	PrintDLink(DL);
}