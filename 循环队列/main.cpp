#include <stdio.h>
#include <stdlib.h>
#define Maxsize 5


typedef int ElemType;
typedef struct {
	ElemType data[Maxsize];       //数组，最多只能存储Maxsize-1 个值，剩下一个用来判断队满
	int front;      //队列头
	int rear;         //对列尾
}SqQueue;


//初始化队列
void InitSqQueue(SqQueue &S) {
	S.front = 0;
	S.rear = 0;
}


//判断队列是否为空
bool isEmpty(SqQueue S) {
	if (S.front == S.rear) {       //队头队尾位置相等则为空，队尾加1到达队头位置则队满
		return true;
	}
	return false;
}


//元素入队
bool EnQueue(SqQueue& S, ElemType e) {
	if ((S.rear + 1) % Maxsize == S.front) {
		return false;            //判断队满
	}
	S.data[S.rear] = e;          //e赋给当前的队尾
	S.rear = (S.rear + 1) % Maxsize;      //队尾向后移动一格
	return true;
}


//元素出队
bool DeQueue(SqQueue& S, ElemType& e) {
	if (isEmpty(S)) {               //判断队空
		return false;
	}
	e = S.data[S.front];        //队头值赋给e传出去
	S.front = (S.front + 1) % Maxsize;          //队头向后移动一格
	return true;
}




int main()
{
	SqQueue S;
	bool ret;          
	ElemType element;       //存储出队的元素
	InitSqQueue(S);      //初始化队列
	ret = isEmpty(S);
	if (ret) {
		printf("当前队列为空\n");
	}

	printf("==================\n");
	EnQueue(S, 1);          //入队
	EnQueue(S, 2);
	EnQueue(S, 3);
	ret = EnQueue(S, 4);
	if (ret) {
		printf("入队成功\n");
	}
	else
	{
		printf("入队失败\n");
	}
	

	printf("==================\n");
	ret = EnQueue(S, 5);
	if (ret) {
		printf("入队成功\n");
	}
	else
	{
		printf("入队失败\n");
	}


	printf("==================\n");
	ret = DeQueue(S, element);              //出队
	ret = DeQueue(S, element);
	ret = DeQueue(S, element);
	ret = DeQueue(S, element);
	if (ret) {
		printf("出队成功，出队的元素为：%d\n",element);
	}
	else {
		printf("出队失败\n");
	}

	printf("==================\n");
	ret = DeQueue(S, element);
	if (ret) {
		printf("出队成功，出队的元素为：%d\n", element);
	}
	else {
		printf("出队失败\n");
	}

	return 0;
}