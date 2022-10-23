#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//�������ṹ��
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;         //�������
	struct BiTNode* lchild;       //��ǰ������
	struct BiTNode* rchild;         //��ǰ�����Һ�
}BiTNode, *BiTree;

//�������нṹ��
typedef struct queue {
	BiTree p;       //����ĳһ�����ĵ�ַ
	struct queue* pnext;
}Biqueue;



//�ݹ�ʵ��ǰ�������������
void preOrder(BiTree t)
{
	if (t != NULL) {
		putchar(t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}													


//�������    �����
void midOrder(BiTree t) {
	if (t != NULL) {
		midOrder(t->lchild);
		putchar(t->data);
		midOrder(t->rchild);
	}
}



//�������      ���Ҹ�
void postOrder(BiTree t) {
	if (t != NULL) {
		postOrder(t->lchild);
		postOrder(t->rchild);
		putchar(t->data);
	}
}




int main()
{
	BiTNode* pnew;
	//int i, j, pos;
	char c;         //�¼ӵĽ��Ԫ��
	BiTree tree = NULL;         //�������
	Biqueue* phead = NULL;
	Biqueue* ptail = NULL;
	Biqueue* pcur = NULL;
	Biqueue* listpnew = NULL;
	
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));          //ʹ��calloc������ռ䲢��ʼ��
		pnew->data = c;
		listpnew = (Biqueue*)calloc(1, sizeof(Biqueue));
		listpnew->p = pnew;
		if (tree == NULL) {    //��ǰ�������β��
			tree = pnew;          //�¼ӽ���Ϊ���ڵ�
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else {
			ptail->pnext = listpnew;       //���½�����β����β�巨
			ptail = listpnew;     //���ý���Ϊβ��
		}
		
		if (pcur->p->lchild == NULL) {
			pcur->p->lchild = pnew;       //���½��ŵ�Ҫ����������
		}
		else if (pcur->p->rchild == NULL) {
			pcur->p->rchild = pnew;        //���½��ŵ�Ҫ��������ұ�
			//���ҽ�㶼����֮�󣬶�����pcur��ָ����һ�����
			pcur = pcur->pnext;           
		}
	}


	printf("----------------------ǰ�����----------------------\n");
	preOrder(tree);
	printf("\n----------------------�������----------------------\n");
	midOrder(tree);
	printf("\n----------------------�������----------------------\n");
	postOrder(tree);

	return 0;
}