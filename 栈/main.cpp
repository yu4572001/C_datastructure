#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define Maxsize 50

typedef int ElemType;
typedef struct {
	ElemType data[Maxsize];          //数组，用来存储栈中元素
	int top;
}SqStack;


void InitStack(SqStack& S) {        //初始化为一个空栈
	S.top = -1;
}


bool StackEmpty(SqStack S) {         //判断栈是否为空
	if (S.top == -1) {
		return true;
	}
	return false;
}


bool Push(SqStack& S, ElemType x) {        //入栈，将元素插入栈顶
	if (S.top == Maxsize - 1) {    //判断栈满
		return false;
	}
	S.data[++S.top] = x;           //栈顶先向后移动一下作为新的栈顶，再去赋值
	return true;
}


bool GetTop(SqStack S, ElemType& x) {          //得到栈顶元素
	if (StackEmpty(S)) {       //判断该栈是否为空
		return false;
	}
	x = S.data[S.top];
	return true;
}


bool Pop(SqStack& S, ElemType& x) {          //出栈，将栈顶元素弹出来
	if (StackEmpty(S)) {          //判断该栈是否为空
		return false;
	}
	x = S.data[S.top];       //栈顶元素赋给x
	S.top--;           //栈顶向前移动
	return true;
}


int main()
{	
	SqStack S;          //创建一个结构体变量 S栈
	bool fag;
	ElemType m;           //中间变量m用来接收拿出来的栈顶元素
	InitStack(S);      //初始化

	fag = StackEmpty(S);
	if (fag) {
		printf("当前栈为空\n");
	}

	Push(S, 3);     //压栈
	Push(S, 4);
	Push(S, 5);

	fag = GetTop(S,m);
	if (fag) {
		printf("获取栈顶元素为：%d\n", m);
	}

	fag = Pop(S, m);
	if (fag) {
		printf("弹出栈顶元素为：%d\n", m);
	}

	return 0;
}

