#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


//二叉树结构体
typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;         //结点数据
	struct BiTNode* lchild;       //当前结点的左孩
	struct BiTNode* rchild;         //当前结点的右孩
}BiTNode, *BiTree;

//辅助队列结构体
typedef struct queue {
	BiTree p;       //树中某一个结点的地址
	struct queue* pnext;
}Biqueue;



//递归实现前序遍历，根左右
void preOrder(BiTree t)
{
	if (t != NULL) {
		putchar(t->data);
		preOrder(t->lchild);
		preOrder(t->rchild);
	}
}													


//中序遍历    左根右
void midOrder(BiTree t) {
	if (t != NULL) {
		midOrder(t->lchild);
		putchar(t->data);
		midOrder(t->rchild);
	}
}



//后序遍历      左右根
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
	char c;         //新加的结点元素
	BiTree tree = NULL;         //树根结点
	Biqueue* phead = NULL;
	Biqueue* ptail = NULL;
	Biqueue* pcur = NULL;
	Biqueue* listpnew = NULL;
	
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));          //使用calloc来申请空间并初始化
		pnew->data = c;
		listpnew = (Biqueue*)calloc(1, sizeof(Biqueue));
		listpnew->p = pnew;
		if (tree == NULL) {    //当前树跟结点尾空
			tree = pnew;          //新加结点就为根节点
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else {
			ptail->pnext = listpnew;       //将新结点放入尾部，尾插法
			ptail = listpnew;     //将该结点变为尾部
		}
		
		if (pcur->p->lchild == NULL) {
			pcur->p->lchild = pnew;       //把新结点放到要插入结点的左边
		}
		else if (pcur->p->rchild == NULL) {
			pcur->p->rchild = pnew;        //把新结点放到要插入结点的右边
			//左右结点都放了之后，队列中pcur就指向下一个结点
			pcur = pcur->pnext;           
		}
	}


	printf("----------------------前序遍历----------------------\n");
	preOrder(tree);
	printf("\n----------------------中序遍历----------------------\n");
	midOrder(tree);
	printf("\n----------------------后序遍历----------------------\n");
	postOrder(tree);

	return 0;
}