#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//����һ���ṹ��
typedef int ElemType;
typedef struct LNode
{
	ElemType data;             //������������������ָ����
	struct LNode* next;
}LNode,*LinkList;         //LNode*(�ṹ����)Ϊһ����㣬LiskList(�ṹ��ָ��)Ϊ��������



//ͷ�巨����
LinkList CreateListHead(LinkList& L)     //&Ϊ���÷���Ҫ�ı�L��ֵ�ͼӣ����ı�Ͳ���
{	
	//����һ���ṹ���еĽ��Ϊs��������Ϊx 
	LNode* s;    
	int x;        

	L = (LNode*)malloc(sizeof(LNode));     //����һ�����LΪͷ���
	L->next = NULL;           //ͷ���L����Ϊ��
	scanf("%d", &x);            //�����ֵ��ֵ��x
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;        //�������ֵ����s��data
		s->next = L->next;           //��sָ���Ԫ�ظ�Ϊ֮ǰLָ���Ԫ��
		L->next = s;            //��Lָ���Ԫ�ظ�Ϊs
		scanf("%d", &x);      //�ٴ�ѭ������һ�����֣�ֱ������9999����
	}
	return L;
}



//β�巨����
LinkList CreateListTail(LinkList &L)         //��������Ϊһ���ṹ��ָ�룬������
{
	int x;           //xΪ�����data����
	L = (LNode*)malloc(sizeof(LNode));    //����һ���ṹ����LΪͷ���
	LNode* s, * r;         //���������ṹ���н�㣬sΪ�²���Ľ�㣬rΪβ�ڵ�
	s = r = L;          //��rβ��㣬s��ָ��Lͷ��㣬��Ϊ��ʱ�����һ��ͷ���
	scanf("%d", &x);
	while (x != 9999) {
		s = (LNode*)malloc(sizeof(LNode));        //����һ������С�Ŀռ�
		s->data = x;
		r->next = s;       //β���rָ��s��s��Ϊ��β���
		r = s;             //��ֵ��r����s�ٴγ�Ϊβ���
		scanf("%d", &x);
	}
	r->next = NULL;              //��β����nextΪ�գ������������
	return L;              //����L����
}



//���Ҷ�Ӧλ�ý���ֵ
LNode* GetElem(LinkList L, int i) {
	if (i == 0) {
		return L; 
	}
	else if (i < 0) {
		return NULL;
	}
	LNode* p = L->next;         //���������е�һ�����Ϊp
	int j = 1;
	while (p != NULL && j < i) {    //�ж�p��㲻Ϊ�գ��Ҳ��ܳ�����i�����
		p = p->next;        //��pָ����һ�����
		j++;
	}
	return p;         //���ش˽��

}



//��ֵ���в���
LNode* LocateElem(LinkList L, ElemType e) {
	LNode* p = L->next;       //���������е�һ�����Ϊp
	while (p != NULL && p->data != e) {	          //���ƥ�䵽p-data����e,������ѭ��������p���
		p = p->next;        //��pָ����һ����� 
	}
	return p;    //���ز��ҵ��ĸý��
}



//����i��λ�ò���Ԫ��
bool ListFrontInsert(LinkList &L, int i, ElemType e) {
	LNode* p = GetElem(L, i - 1);        //�õ�Ҫ����ĵ�i��λ�õ�ǰһ����㣬GetElem()Ϊǰ��д�ĺ���
	if (p == NULL) {          //�ж�ǰһ����㲻Ϊ��
		return false;
	}
	LNode* s = (LNode*)malloc(sizeof(LNode));          //�����¿ռ���s
	s->data = e;
	s->next = p->next;             //˳���ܷ�
	p->next = s;
	return true;
}



//ɾ����i��λ�õĽ��
bool ListDelete(LinkList& L, int i) {
	LNode* p = GetElem(L, i - 1);          //�õ����i��ǰ�����
	if (p == NULL) {
		return false;
	}
	LNode* q = p->next;         //����Ҫɾ���Ľ��Ϊq
	if (q == NULL) {       //�ж�Ҫɾ���Ľ���Ƿ�Ϊ��
		return false;
	}
	p->next = q->next;          //��������
	free(q);        //�ͷ�ɾ�����Ŀռ�
	q == NULL;         //Ϊ�˱���Ұָ��
	return true;
}



//��ӡ����
void PrintLink(LinkList L)
{
	printf("=============�������£�\n");
	L = L->next;            //����һ��Ԫ�ص�next����L
	while (L != NULL) {       //ֻҪL->next��Ϊ�վ�ѭ����ӡ
		printf("%3d", L->data);
		L = L->next;         //����һ��Ԫ�ص�next����L
	}
	printf("\n");
}





int main()
{
	LinkList L;          //����һ���ṹ��ָ��(����)
	LNode* search;          //����һ����㣬�������ܲ��ҵ����ص�ֵ
	//CreateListHead(L);          //ͷ�巨����
	CreateListTail(L);          //���� 1 2 3 4 5 6 9999

	PrintLink(L);       //��ӡ����


	search = GetElem(L, 2);          //���ò���
	if (search != NULL) {
		printf("==============����Ų������£�\n");
		printf("��2��λ�õ�ֵΪ��%d\n",search->data);
	}
	else {
		printf("��������!");
	}

	search = LocateElem(L, 23);
	if (search != NULL) {
		printf("==============��ֵ�������£�\n");
		printf("�����д��ڸ�ֵ��%d\n", search->data);
	}
	else {
		printf("��������!");
	}


	ListFrontInsert(L, 2, 99);      //����Ԫ��
	PrintLink(L);


	ListDelete(L, 2);           //ɾ���ڶ���Ԫ��
	PrintLink(L);

}