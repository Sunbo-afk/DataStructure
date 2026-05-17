#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

//栈(stack)是限定仅在表尾进行插入或删除操作的线性表。因此对栈来说, 表尾端有
//其特殊含义, 称为栈顶(top), 相应地, 表头端称为栈底(bottom)。不含元素的空表
//称为空栈。(分为顺序栈和链式栈)

//栈的顺序结构实现
typedef struct {
	ElemType data[MAXSIZE];
	int top;
} SqStack;

//初始化
void InitSqStack(SqStack* s) {
	s->top = -1;
}

//判断栈是否为空
int IsEmpty(SqStack* s) {
	if(s->top == -1) {
		return 1;
	} else {
		return 0;
	}
}

//入栈(进栈/压栈push）
int Push(SqStack* s, ElemType e) {
	if (s->top == MAXSIZE - 1) {
		return 0; //栈满
	}
	s->top++;
	s->data[s->top] = e;
	return 1;
}

//出栈(退栈/pop)
int Pop(SqStack* s, ElemType* e) {
	if (s->top == -1) {
		return 0; //栈空
	}
	*e = s->data[s->top];
	s->top--;
	return 1;
}

//获取栈顶元素
int GetTop(SqStack* s, ElemType* e) {
	if (s->top == -1) {
		return 0; //栈空
	}
	*e = s->data[s->top];
	return 1;
}

//栈的动态分配实现
typedef struct{
	ElemType* data;
	int top;
}DynamicStack;

DynamicStack* InitDynamicStack() {
	DynamicStack* s = (DynamicStack*)malloc(sizeof(DynamicStack));
	s->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	s->top = -1;
	return s;
}

//清除动态栈缓存
void ClearDynamicStack(DynamicStack* s) {
	free(s->data);
	s->data = NULL;
	s->top = -1;
}


//栈的链式实现
typedef struct StackNode {
	ElemType data;
	struct StackNode* next;
} StackNode;

//初始化链式栈
StackNode* InitLinkedStack() {
	StackNode* s = (StackNode*)malloc(sizeof(StackNode));
	s->data = 0; //栈顶元素
	s->next = NULL; //栈顶指针
	return s;
}

//判断链式栈是否为空
int IsLinkedStackEmpty(StackNode* s) {
	if (s->next == NULL) {
		return 1; //栈空
	}
	else {
		return 0; //栈非空
	}
}

//入栈(进栈/压栈push)
int  PushLinkedStack(StackNode* s, ElemType e) {
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	newNode->data = e;
	newNode->next = s->next; //新节点指向当前栈顶
	s->next = newNode; //栈顶指向新节点
	return 1;
}

//出栈(退栈/pop)
int PopLinkedStack(StackNode* s, ElemType* e) {
	if (s->next == NULL) {
		printf("栈空，无法出栈！\n");)
		return 0; //栈空
	}
	StackNode* temp = s->next; //临时指针指向当前栈顶
	*e = temp->data; //获取栈顶元素
	s->next = temp->next; //栈顶指向下一个节点
	free(temp); //释放原栈顶节点
	return 1;
}

//获取栈顶元素
int GetTopLinkedStack(StackNode* s, ElemType* e) {
	if (s->next == NULL) {
		printf("栈空，无法获取栈顶元素！\n");
		return 0; //栈空
	}
	*e = s->next->data; //获取栈顶元素
	return 1;
}

//清除链式栈缓存
void ClearLinkedStack(StackNode* s) {
	StackNode* current = s->next; //从栈顶开始
	while (current != NULL) {
		StackNode* temp = current; //临时指针指向当前节点
		current = current->next; //移动到下一个节点
		free(temp); //释放当前节点
	}
	s->next = NULL; //重置栈顶指针
}


//main函数测试
int main() {

	//测试顺序栈
	SqStack s;
	InitSqStack(&s);
	Push(&s, 10);
	Push(&s, 20);
	Push(&s, 30);
	ElemType e;
	GetTop(&s, &e);
	printf("栈顶元素: %d\n", e); // 输出: 栈顶元素: 30
	Pop(&s, &e);
	printf("出栈元素: %d\n", e); // 输出: 出栈元素: 30
	GetTop(&s, &e);
	printf("新的栈顶元素: %d\n", e); // 输出: 新的栈顶元素: 20

	//测试链式栈
	StackNode* linkedStack = InitLinkedStack();
	PushLinkedStack(linkedStack, 10);
	PushLinkedStack(linkedStack, 20);
	PushLinkedStack(linkedStack, 30);
	GetTopLinkedStack(linkedStack, &e);
	printf("链式栈顶元素: %d\n", e); // 输出: 链式栈顶元素: 30
	PopLinkedStack(linkedStack, &e);
	printf("链式出栈元素: %d\n", e); // 输出: 链式出栈元素: 30
	GetTopLinkedStack(linkedStack, &e);
	printf("链式新的栈顶元素: %d\n", e); // 输出: 链式新的栈顶元素: 20

	//清除链式栈缓存
	ClearLinkedStack(linkedStack);


	return 0;
}