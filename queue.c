#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

//队列(queue)是一种先进先出(First In First Out,FIFO)的线性表。它只
//允许在表的一端进行插入, 而在另一端删除元素。在队列中, 允许插入的一端称为
//队尾(rear), 允许删除的一端则称为队头(front)。

//队列的顺序结构实现
typedef struct {
	ElemType data[MAXSIZE];
	int front; //队头指针
	int rear; //队尾指针
} SqQueue;

//初始化
void InitSqQueue(SqQueue* q) {
	q->front = 0;
	q->rear = 0;
}

//判断队列是否为空
int IsEmpty(SqQueue* q) {
	if (q->front == q->rear) {
		return 1; //队列空
	}
	else {
		return 0; //队列非空
	}
}

//队尾满了，但队头有空位，调整队列
int queueFull(SqQueue* q) {
	if (q->front > 0) {
		int space = q->front;
		for (int i = q->front; i < q->rear; i++) {
			q->data[i - space] = q->data[i]; //将队头元素移动到队列前面
		}
		q->front = 0;
		q->rear = q->rear - space;
		return 1; //调整成功
	}
	else {
		printf("队列已满，无法调整！\n");
		return 0; //队列满，无法调整
	}
	
}

//入队(进队/enqueue)
int Enqueue(SqQueue* q, ElemType e) {
	if (q->rear >= MAXSIZE) {
		if (!queueFull(q)) {
			return 0; //队列满
		}
	}
	q->data[q->rear] = e;
	q->rear++;
	return 1;
}

//出队(退队/dequeue)
int Dequeue(SqQueue* q, ElemType* e) {
	if (q->front == q->rear) {
		printf("队列空，无法出队！\n");
		return 0; //队列空
	}
	*e = q->data[q->front];
	q->front++;
	return 1;
}

//获取队头元素
int GetFront(SqQueue* q, ElemType* e) {
	if (q->front == q->rear) {
		printf("队列空，无法获取队头元素！\n");
		return 0; //队列空
	}
	*e = q->data[q->front];
	return 1;
}

//栈的动态内存分配实现
typedef struct {
	ElemType* data;
	int front; //队头指针
	int rear; //队尾指针
} DynamicQueue;

//初始化动态队列
DynamicQueue* InitDynamicQueue() {
	DynamicQueue* q = (DynamicQueue*)malloc(sizeof(DynamicQueue));
	q->data = (ElemType*)malloc(MAXSIZE * sizeof(ElemType));
	q->front = 0;
	q->rear = 0;
	return q;
}


//清除动态队列缓存
void ClearDynamicQueue(DynamicQueue* q) {
	free(q->data);
	q->data = NULL;
	q->front = 0;
	q->rear = 0;
}

//循环队列的实现
//循环队列是一种特殊的队列结构，它通过将队列的尾部连接到头部来实现循环利用空间。当队尾指针达到数组末尾时，如果队头指针不在数组的起始位置，循环队列会将新元素插入到数组的起始位置，从而有效地利用了数组空间。
//循环队列—入队
int EnqueueCircular(SqQueue* q, ElemType e) {
	if ((q->rear + 1) % MAXSIZE == q->front) {
		printf("循环队列已满，无法入队！\n");
		return 0; //循环队列满
	}
	q->data[q->rear] = e;
	q->rear = (q->rear + 1) % MAXSIZE; //循环队列
	return 1;
}

//循环队列—出队
int DequeueCircular(SqQueue* q, ElemType* e) {
	if (q->front == q->rear) {
		printf("循环队列空，无法出队！\n");
		return 0; //循环队列空
	}
	*e = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE; //循环队列
	return 1;
}

//队列的链式实现
typedef struct QueueNode {
	ElemType data;
	struct QueueNode* next;
} QueueNode;

typedef struct {
	QueueNode* front; //队头指针
	QueueNode* rear; //队尾指针
} LinkedQueue;

//初始化链式队列
LinkedQueue* InitLinkedQueue() {
	LinkedQueue* q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->data = 0; //队头元素
	node->next = NULL; //队头指针
	q->front = node;
	q->rear = node;
	return q;
}

//入队（尾插法）
int EnqueueLinkedQueue(LinkedQueue* q, ElemType e) {
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->data = e;
	newNode->next = NULL; //新节点成为新的队尾
	q->rear->next = newNode; //原队尾指向新节点
	q->rear = newNode; //更新队尾指针
	return 1;
}

//出队（头删法）
int DequeueLinkedQueue(LinkedQueue* q, ElemType* e) {
	if (q->front == q->rear) {
		printf("链式队列空，无法出队！\n");
		return 0; //链式队列空
	}
	QueueNode* temp = q->front->next; //临时指针指向当前队头
	*e = temp->data; //获取队头元素
	q->front->next = temp->next; //队头指向下一个节点
	if (q->rear == temp) { //如果出队的是最后一个节点，更新队尾指针
		q->rear = q->front;
	}
	free(temp); //释放原队头节点
	return 1;
}

//获取队头元素
int GetFrontLinkedQueue(LinkedQueue* q, ElemType* e) {
	if (IsEmpty((SqQueue*)q)) {
		printf("链式队列空，无法获取队头元素！\n");
		return 0; //链式队列空
	}
	*e = q->front->next->data; //获取队头元素
	return 1;
}
//清除链式队列缓存
void ClearLinkedQueue(LinkedQueue* q) {
	QueueNode* current = q->front; //从队头开始
	while (current != NULL) {
		QueueNode* temp = current; //临时指针指向当前节点
		current = current->next; //移动到下一个节点
		free(temp); //释放当前节点
	}
	q->front = NULL; //重置队头指针
	q->rear = NULL; //重置队尾指针
}




//main函数测试
int main() {
	SqQueue q;
	InitSqQueue(&q);
	Enqueue(&q, 10);
	Enqueue(&q, 20);
	Enqueue(&q, 30);
	ElemType e;
	GetFront(&q, &e);
	printf("队头元素: %d\n", e); // 输出: 队头元素: 10
	Dequeue(&q, &e);
	printf("出队元素: %d\n", e); // 输出: 出队元素: 10
	GetFront(&q, &e);
	printf("新的队头元素: %d\n", e); // 输出: 新的队头元素: 20
	
	//测试循环队列
	SqQueue cq;
	InitSqQueue(&cq);
	EnqueueCircular(&cq, 100);
	EnqueueCircular(&cq, 200);
	EnqueueCircular(&cq, 300);
	GetFront(&cq, &e);
	printf("循环队列队头元素: %d\n", e); // 输出: 循环队列队头元素: 100
	DequeueCircular(&cq, &e);
	printf("循环队列出队元素: %d\n", e); // 输出: 循环队列出队元素: 100
	GetFront(&cq, &e);
	printf("循环队列新的队头元素: %d\n", e); // 输出: 循环队列新的队头元素: 200	

	//测试链式队列
	LinkedQueue* lq = InitLinkedQueue();
	EnqueueLinkedQueue(lq, 1000);
	EnqueueLinkedQueue(lq, 2000);
	EnqueueLinkedQueue(lq, 3000);
	GetFrontLinkedQueue(lq, &e);
	printf("链式队列队头元素: %d\n", e); // 输出: 链式队列队头元素: 1000
	DequeueLinkedQueue(lq, &e);
	printf("链式队列出队元素: %d\n", e); // 输出: 链式队列出队元素: 1000
	GetFrontLinkedQueue(lq, &e);
	printf("链式队列新的队头元素: %d\n", e); // 输出: 链式队列新的队头元素: 2000

	//清除链式队列缓存
	ClearLinkedQueue(lq);
	free(lq); //释放链式队列结构体内存
		

	return 0;
}