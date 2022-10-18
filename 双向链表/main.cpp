#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//����ṹ��
typedef int ElemType;
typedef struct DNode {
	ElemType data;        //������
	struct DNode* prior;          //ǰ��ָ��
	struct DNode* next;           //���ָ��

}DNode, * DLinkList;


//ͷ�巨����
DLinkList Dlist_head_insert(DLinkList& DL) {
	DNode* s;        //����һ���ṹ���еĽ��Ϊs��������Ϊx 
	int e;
	DL = (DNode*)malloc(sizeof(DNode));      //����һ�����DLΪͷ���
	DL->next = NULL;           //ͷ����ǰ���ͺ�̶�ΪNULL
	DL->prior = NULL;
	scanf("%d", &e);
	while (e != 9999) {
		s = (DNode*)malloc(sizeof(DNode));       //����ռ�
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



//β�巨����
DLinkList Dlist_tail_insert(DLinkList& DL) {
	int x;
	DL = (DNode*)malloc(sizeof(DNode));      //����һ�����DLΪͷ���
	DNode* s, * r;
	s = r = DL;
	DL->prior = NULL;
	scanf("%d", &x);
	while (x != 9999) {
		s = (DNode*)malloc(sizeof(DNode));       //����ռ�
		s->data = x;
		r->next = s;
		s->prior = r;
		r = s;              //rָ���µ�β��㣬��β���Ϊ�ղ����Ԫ��
		scanf("%d", &x);
	}
	r->next = NULL;               //����β����nextβ��
	return DL;
}



//���Ҷ�Ӧλ�ý���ֵ
DNode* GetElem(DLinkList DL, int i) {
	if (i == 0) {
		return DL;
	}
	else if (i < 0) {
		return NULL;
	}
	DNode* p = DL->next;         //���������е�һ�����Ϊp
	int j = 1;
	while (p != NULL && j < i) {    //�ж�p��㲻Ϊ�գ��Ҳ��ܳ�����i�����
		p = p->next;        //��pָ����һ�����
		j++;
	}
	return p;         //���ش˽��

}



//����i��λ�ò���Ԫ��
bool DListFrontInsert(DLinkList &DL, int i, ElemType e) {
	DNode* p = GetElem(DL, i - 1);        //�õ�Ҫ����ĵ�i��λ�õ�ǰһ����㣬GetElem()Ϊǰ��д�ĺ���
	if (p == NULL) {          //�ж�ǰһ����㲻Ϊ��
		return false;
	}
	DNode* s = (DNode*)malloc(sizeof(DNode));          //�����¿ռ���s
	s->data = e;
	s->next = p->next;
	p->next->prior = s;
	s->prior = p;
	p->next = s;
	return true;
}


//ɾ����i�����
bool DListDelete(DLinkList &DL,int i) {
	DNode* p = GetElem(DL, i - 1);    //pΪҪɾ���Ľ���ǰһ�����
	if (p == NULL) {        //�ж�ǰһ����㲻Ϊ��
		return false;
	}
	DNode *q = p->next;             //qΪҪɾ���Ľ��
	if (q == NULL) {          //�ж�q�Ƿ�Ϊ��
		return false;
	}
	if (q->next != NULL) {      //�ж�q���滹��û��Ԫ�أ��Ƿ�Ϊβ���
		p->next = q->next;
		q->next->prior = p;
		free(q);
	}
	else {
		free(q);      //���qΪβ��㣬ֱ���ͷ�q��p��Ϊβ���
		p->next = NULL;
	}
	q = NULL;
	return true;
	

}




//��ӡ����
void PrintDLink(DLinkList DL)
{
	printf("=============˫���������£�\n");
	DL = DL->next;            //����һ��Ԫ�ص�next����L
	while (DL != NULL) {       //ֻҪL->next��Ϊ�վ�ѭ����ӡ
		printf("%3d", DL->data);
		DL = DL->next;         //����һ��Ԫ�ص�next����L
	}
	printf("\n");
}



int main() {
	DLinkList DL;
	DNode* search;

	//Dlist_head_insert(DL);      //ͷ�巨
	Dlist_tail_insert(DL);        //β�巨   1 2 3 4 5 6 9999
	PrintDLink(DL);            //�����ӡ

	search = GetElem(DL, 2);        //���ò���
	if (search != NULL) {
		printf("==============����Ų������£�\n");
		printf("��2��λ�õ�ֵΪ��%d\n", search->data);
	}
	else {
		printf("��������!");
	}


	DListFrontInsert(DL, 2, 99);    //������ڶ���λ�ò���99
	PrintDLink(DL);

	DListDelete(DL, 2);           //ɾ���ڶ���Ԫ��99
	PrintDLink(DL);
}