#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50

typedef int ElemType;
typedef struct {
	ElemType data[Maxsize];          //���飬�����洢ջ��Ԫ��
	int top;
}SqStack;


void InitStack(SqStack& S) {        //��ʼ��Ϊһ����ջ
	S.top = -1;
}


bool StackEmpty(SqStack S) {         //�ж�ջ�Ƿ�Ϊ��
	if (S.top == -1) {
		return true;
	}
	return false;
}


bool Push(SqStack& S, ElemType x) {        //��ջ����Ԫ�ز���ջ��
	if (S.top == Maxsize - 1) {    //�ж�ջ��
		return false;
	}
	S.data[++S.top] = x;           //ջ��������ƶ�һ����Ϊ�µ�ջ������ȥ��ֵ
	return true;
}


bool GetTop(SqStack S, ElemType& x) {          //�õ�ջ��Ԫ��
	if (StackEmpty(S)) {       //�жϸ�ջ�Ƿ�Ϊ��
		return false;
	}
	x = S.data[S.top];
	return true;
}


bool Pop(SqStack& S, ElemType& x) {          //��ջ����ջ��Ԫ�ص�����
	if (StackEmpty(S)) {          //�жϸ�ջ�Ƿ�Ϊ��
		return false;
	}
	x = S.data[S.top];       //ջ��Ԫ�ظ���x
	S.top--;           //ջ����ǰ�ƶ�
	return true;
}


int main()
{	
	SqStack S;          //����һ���ṹ����� Sջ
	bool fag;
	ElemType m;           //�м����m���������ó�����ջ��Ԫ��
	InitStack(S);      //��ʼ��

	fag = StackEmpty(S);
	if (fag) {
		printf("��ǰջΪ��\n");
	}

	Push(S, 3);     //ѹջ
	Push(S, 4);
	Push(S, 5);

	fag = GetTop(S,m);
	if (fag) {
		printf("��ȡջ��Ԫ��Ϊ��%d\n", m);
	}

	fag = Pop(S, m);
	if (fag) {
		printf("����ջ��Ԫ��Ϊ��%d\n", m);
	}

	return 0;
}

