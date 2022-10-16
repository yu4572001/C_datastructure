#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50        //����һ��������˳�������ռ�
typedef int ElemType;         //˳����е�Ԫ�����ͣ������������ͳһ�޸ı��е�Ԫ������
//��ʼ��
typedef struct {       //����һ���ṹ��
	ElemType data[MaxSize];         //��������飬������Ԫ��
	int length;             //��ǰ˳����ж��ٸ�Ԫ��
}SqList;


bool InsertList(SqList &L, int i, ElemType e)   //����ʵ�Σ�LҪȡ��ַ&,ָ��ͬһ������ռ�����޸�
{
	if (i<1 || i>L.length + 1) {        //�жϲ���λ���Ƿ�Ϸ�
		return false;
	}
	if (L.length >= MaxSize) {          //�жϵ�ǰ���Ƿ����
		return false;
	}
	for (int j = L.length; j >= i; j--) {          //�ƶ����е�Ԫ�أ����������ƶ�	
		L.data[j] = L.data[j - 1];
	}
	L.data[i - 1] = e;        //��ǰҪ����Ԫ��λ�õ��±�     ����e
	L.length++;            //���ȼ�1
	return true;       //����true�������ɹ�
}



//ɾ������
bool DeleteList(SqList &L, int i, ElemType &e)     //�����e�ӵ��ǵ�ַ���������ʵ��ָ��ͬһƬ�ռ��Ըı���ֵ
{
	if (i < 1 || i > L.length + 1) {      //�ж�ɾ��λ���Ƿ�Ϸ�
		return false;
	}
	if (L.length == 0) {         //�жϱ����Ƿ�ձ��ձ�����ɾ��
		return false;
	}
	e = L.data[i - 1];      //��Ҫɾ����Ԫ�ظ���e�������������del
	for (int j = i; j < L.length; j++) {        //��i��λ�����ΰ�Ԫ����ǰ����
		L.data[j - 1] = L.data[j];
	}
	L.length--;             //���ȼ�1
	return true;
}


//���Ҳ���,�ɹ�����λ�ã�λ�ô�1��ʼ������ʧ�ܷ���0
int LocateList(SqList L, ElemType e)
{
	int i;
	for (int i = 0; i < L.length; i++) {      //����˳���
		if (L.data[i] == e) {
			return i + 1;       //���ظ�Ԫ�ص��±�
		}
	}
	return 0;      //û���ҵ�����0
}




//��ӡ��ǰ��Ԫ��
void PrintList(SqList L)
{
	for (int i = 0; i < L.length; i++) {
		printf("%4d", L.data[i]);
	}
	printf("\n");
}



int main()
{    //˳�������ƣ����ṹ�����
	SqList L;
	bool ret;            //���巵��ֵ��Ϊ��������
	ElemType del;        //����һ��ɾ������
	//�ֶ���˳����и�ֵ
	L.data[0] = 1;
	L.data[1] = 2;
	L.data[2] = 3;
	L.length = 3;          //��ǰ����Ԫ�ظ���Ϊ3

	printf("===============================\n");
	//���ò��뺯������100����ڶ���λ��
	ret = InsertList(L, 2, 100);         
	if (ret) {
		printf("Ԫ�ز���ɹ���\n");
		PrintList(L);            //��ӡ
	}
	else {
		printf("Ԫ�ز���ʧ�ܣ�\n");
		PrintList(L);
	}

	printf("===============================\n");
	//����ɾ�����ѵڶ���Ԫ��ɾ�������ظ�ֵ
	ret = DeleteList(L, 2, del);
	if (ret) {
		printf("Ԫ��ɾ���ɹ���\n");
		printf("ɾ����Ԫ��Ϊ��%d\n",del);
		PrintList(L);
	}
	else {
		printf("Ԫ��ɾ��ʧ�ܣ�\n");
	}

	printf("===============================\n");
	//���ò��Һ������ҵ������ظ�ֵ�±�
	int elem_pos;
	elem_pos = LocateList(L, 3);
	if (elem_pos) {
		printf("���ҳɹ�\n");
		printf("Ԫ��λ��Ϊ��%d", elem_pos);
	}
	else {
		printf("����ʧ��\n");
	}
	return 0;
}

