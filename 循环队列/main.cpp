#include <stdio.h>
#include <stdlib.h>
#define Maxsize 5


typedef int ElemType;
typedef struct {
	ElemType data[Maxsize];       //���飬���ֻ�ܴ洢Maxsize-1 ��ֵ��ʣ��һ�������ж϶���
	int front;      //����ͷ
	int rear;         //����β
}SqQueue;


//��ʼ������
void InitSqQueue(SqQueue &S) {
	S.front = 0;
	S.rear = 0;
}


//�ж϶����Ƿ�Ϊ��
bool isEmpty(SqQueue S) {
	if (S.front == S.rear) {       //��ͷ��βλ�������Ϊ�գ���β��1�����ͷλ�������
		return true;
	}
	return false;
}


//Ԫ�����
bool EnQueue(SqQueue& S, ElemType e) {
	if ((S.rear + 1) % Maxsize == S.front) {
		return false;            //�ж϶���
	}
	S.data[S.rear] = e;          //e������ǰ�Ķ�β
	S.rear = (S.rear + 1) % Maxsize;      //��β����ƶ�һ��
	return true;
}


//Ԫ�س���
bool DeQueue(SqQueue& S, ElemType& e) {
	if (isEmpty(S)) {               //�ж϶ӿ�
		return false;
	}
	e = S.data[S.front];        //��ͷֵ����e����ȥ
	S.front = (S.front + 1) % Maxsize;          //��ͷ����ƶ�һ��
	return true;
}




int main()
{
	SqQueue S;
	bool ret;          
	ElemType element;       //�洢���ӵ�Ԫ��
	InitSqQueue(S);      //��ʼ������
	ret = isEmpty(S);
	if (ret) {
		printf("��ǰ����Ϊ��\n");
	}

	printf("==================\n");
	EnQueue(S, 1);          //���
	EnQueue(S, 2);
	EnQueue(S, 3);
	ret = EnQueue(S, 4);
	if (ret) {
		printf("��ӳɹ�\n");
	}
	else
	{
		printf("���ʧ��\n");
	}
	

	printf("==================\n");
	ret = EnQueue(S, 5);
	if (ret) {
		printf("��ӳɹ�\n");
	}
	else
	{
		printf("���ʧ��\n");
	}


	printf("==================\n");
	ret = DeQueue(S, element);              //����
	ret = DeQueue(S, element);
	ret = DeQueue(S, element);
	ret = DeQueue(S, element);
	if (ret) {
		printf("���ӳɹ������ӵ�Ԫ��Ϊ��%d\n",element);
	}
	else {
		printf("����ʧ��\n");
	}

	printf("==================\n");
	ret = DeQueue(S, element);
	if (ret) {
		printf("���ӳɹ������ӵ�Ԫ��Ϊ��%d\n", element);
	}
	else {
		printf("����ʧ��\n");
	}

	return 0;
}