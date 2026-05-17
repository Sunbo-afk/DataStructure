
#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100

typedef int ElemType;


//顺序表

//初始化顺序表
typedef struct {
	ElemType data[MAX_SIZE];
	int length;
}SeqList;

void initList(SeqList * L) {
	L -> length = 0;
}


//动态分配内存地址的初始化(顺序表的所有操作与基本初始化一致，仅更改函数名即可使用)
typedef struct {
	ElemType* data;
	int length;
} DynamicSeqList;

DynamicSeqList* initDynamicList() {
	DynamicSeqList* list = (DynamicSeqList*)malloc(sizeof(DynamicSeqList));
	list->data = (ElemType*)malloc( MAX_SIZE * sizeof(ElemType));
	list->length = 0;
	return list;
}

//遍历
void listElem(SeqList* L) {
	printf("顺序表中的元素为: ");
	for (int i = 0; i < L->length; i++) {
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//插入元素
//按顺序依次插入元素
int append(SeqList * L, ElemType e) {
	if (L -> length >= MAX_SIZE) {
		printf("顺序表已满，无法插入元素\n");
		return 0;
	}
	L -> data[L -> length] = e;
	L -> length++;
	return 1;
}
//按位置插入
int  insert(SeqList * L, int pos, ElemType e) {
	if (L -> length >= MAX_SIZE) {
		printf("顺序表已满，无法插入元素\n");
		return 0;
	}
	if (pos < 1 || pos > L -> length + 1) {
		printf("插入位置不合法\n");
		return 0;
	}
	for (int i = L -> length; i >= pos; i--) {
		L -> data[i] = L -> data[i - 1];
	}
	L -> data[pos - 1] = e;
	L -> length++;
	return 1;
}

//删除元素
int delete(SeqList * L, int pos, ElemType * e) {
	if (L -> length == 0) {
		printf("顺序表为空，无法删除元素\n");
		return 0;
	}
	if (pos < 1 || pos > L -> length) {
		printf("删除位置不合法\n");
		return 0;
	}
	*e = L -> data[pos - 1];
	for (int i = pos; i < L -> length; i++) {
		L -> data[i - 1] = L -> data[i];
	}
	L -> length--;
	return 1;
}

//查找元素
int find(SeqList * L, ElemType e) {
	if (L->length == 0) {
		printf("顺序表为空，无法查找元素\n");
		return 0;
	}
	for (int i = 0; i < L -> length; i++) {
		if (L -> data[i] == e) {
			return i + 1; //返回位置
		}
	}
	return 0; //未找到
}

// 释放动态顺序表
void freeDynamicList(DynamicSeqList* list) {
	if (list) {
		free(list->data);  // 释放数组
		free(list);        // 释放结构体
	}
}

//链表
typedef struct Node {
	ElemType data;
	struct Node* next;
} Node;

//初始化链表
Node* initLinkedList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0; //头结点数据域可存储链表长度或其他信息
	head->next = NULL;
	return head;
}

//遍历链表
void traverseLinkedList(Node* head) {
	Node* current = head->next; //跳过头结点
	printf("链表中的元素为: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

//插入数据
//头插法
int headInsert(Node* head, ElemType e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = head->next;
	head->next = newNode;
	return 1;
}

//尾插法
//获取尾节点
Node* getTail(Node* head) {
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	return current;
}

Node * tailInsert(Node* tail, ElemType e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	tail->next = newNode;
	newNode->next = NULL;
	return newNode;
}

//指定位置插入
int insertAtPosition(Node* head, int pos, ElemType e) {
	if (pos < 1) {
		printf("插入位置不合法\n");
		return 0;
	}
	Node* current = head;
	int index = 0;
	while (current != NULL && index < pos - 1) {
		current = current->next;
		index++;
	}
	if (current == NULL) {
		printf("插入位置超出链表长度\n");
		return 0;
	}
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	newNode->next = current->next;
	current->next = newNode;
	return 1;
}

//删除节点
int deleteAtPosition(Node* head, int pos, ElemType* e) {
	if (pos < 1) {
		printf("删除位置不合法\n");
		return 0;
	}
	Node* current = head;
	int index = 0;
	while (current->next != NULL && index < pos - 1) {
		current = current->next;
		index++;
	}
	if (current->next == NULL) {
		printf("删除位置超出链表长度\n");
		return 0;
	}
	Node* temp = current->next;
	*e = temp->data;
	current->next = temp->next;
	free(temp);
	return 1;
}

//获取链表长度
int getLinkedListLength(Node* head) {
	int length = 0;
	Node* current = head;
	while (current != NULL) {
		length++;
		current = current->next;
	}
	return length;
}

//释放链表内存
void freeLinkedList(Node* head) {
	Node* current = head->next;//跳过头结点
	Node* temp;
	while (current != NULL) {
		temp = current->next;
		free(current);
		current = temp;
	}
	head->next = NULL; //清空头结点的next指针
}

//单向循环链表(操作除了遍历不同需要注意，其余与普通链表相同)
typedef struct CircularNode {
	ElemType data;
	struct CircularNode* next;

}CircularNode;

//初始化单向循环链表
CircularNode* initCircularLinkedList() {
	CircularNode* head = (CircularNode*)malloc(sizeof(CircularNode));
	head->data = 0; //头结点数据域可存储链表长度或其他信息
	head->next = head; //指向自己形成循环
	return head;
}

//遍历单向循环链表
void traverseCircularLinkedList(CircularNode* head) {
	CircularNode* current = head->next; //跳过头结点
	printf("单向循环链表中的元素为: ");
	while (current != head) { //循环条件为current不等于head
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

//双向链表
typedef struct doublyNode{
	ElemType data;
	struct doublyNode *prev, *next;
}doublyNode;

doublyNode* initdoublyLinkedList() {
	doublyNode* head = (doublyNode*)malloc(sizeof(doublyNode));
	head->data = 0; //头结点数据域可存储链表长度或其他信息
	head->next = NULL;
	head->prev = NULL;
	return head;
}

//头插法
int insertdoublyHead(doublyNode* doublyHead, ElemType e) {
	doublyNode* newNode = (doublyNode*)malloc(sizeof(doublyNode));
	newNode->data = e;
	newNode->prev = doublyHead;
	newNode->next = doublyHead->next;
	if (doublyHead->next != NULL) {
		doublyHead->next->prev = newNode;
	}
	doublyHead->next = newNode;
	return 1;
}

//遍历
void traversedoublyLinkedList(doublyNode* head) {
	doublyNode* current = head->next; //跳过头结点
	printf("链表中的元素为: ");
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}


//尾插法
doublyNode* getdoublyTail(doublyNode* head) {
	doublyNode* current = head;
	while (current->next != NULL) {
		current = current->next;
	}
	return current;
}
doublyNode* insertdoublyTail(doublyNode* tail, ElemType e) {
	doublyNode* newNode = (doublyNode*)malloc(sizeof(doublyNode));
	newNode->data = e;
	newNode->prev = tail;
	tail->next = newNode;
	newNode->next = NULL;
	return newNode;
}

//指定位置插入
int insertdoublyAtPosition(doublyNode* head, int pos, ElemType e) {
	if (pos < 1) {
		printf("插入位置不合法\n");
		return 0;
	}
	doublyNode* current = head;
	int index = 0;
	while (current != NULL && index < pos - 1) {
		current = current->next;
		index++;
	}
	if (current == NULL) {
		printf("插入位置超出链表长度\n");
		return 0;
	}
	doublyNode* newNode = (doublyNode*)malloc(sizeof(doublyNode));
	newNode->data = e;
	newNode->prev = current;
	newNode->next = current->next;
	if (current->next != NULL) {
		current->next->prev = newNode;
	}
	current->next = newNode;
	return 1;
}

//删除节点
int deletedoublyAtPosition(doublyNode* head, int pos, ElemType* e) {
	if (pos < 1) {
		printf("删除位置不合法\n");
		return 0;
	}
	doublyNode* current = head;
	int index = 0;
	while (current->next != NULL && index < pos - 1) {
		current = current->next;
		index++;
	}
	if (current->next == NULL) {
		printf("删除位置超出链表长度\n");
		return 0;
	}
	doublyNode* temp = current->next;
	*e = temp->data;
	current->next = temp->next;
	if (temp->next != NULL) {
		temp->next->prev = current;
	}
	free(temp);
	return 1;
}

//释放双向链表内存
void freedoublyLinkedList(doublyNode* head) {
	doublyNode* current = head->next;//跳过头结点
	doublyNode* temp;
	while (current != NULL) {
		temp = current->next;
		free(current);
		current = temp;
	}
	head->next = NULL; //清空头结点的next指针
}

int main() {

	//顺序表
	//声明一个顺序表并初始化
	SeqList list;
	initList(&list);
	printf("顺序表初始化完成，当前长度为: %d\n", list.length);
	printf("目前占用的存储空间为: %d\n", sizeof(list.data));
	
	//动态分配内存地址的初始化
	DynamicSeqList* dynamicList = initDynamicList();//后续传入函数时，无需使用&符号，因为dynamicList已经是一个指针了
	printf("动态分配内存地址的顺序表初始化完成，当前长度为: %d\n", dynamicList->length);
	printf("目前占用的存储空间为: %d\n", sizeof(dynamicList->data));


	//释放动态顺序表内存
	freeDynamicList(dynamicList);

	//按顺序依次插入元素
	append(&list, 10);
	printf("插入元素10，当前长度为: %d\n", list.length);
	append(&list, 20);
	append(&list, 30);
	append(&list, 40);

	//遍历顺序表
	listElem(&list);
	//按位置插入元素
	insert(&list, 2, 15);
	printf("在位置2插入元素15，当前长度为: %d\n", list.length);
	insert(&list, 4, 25);
	printf("在位置2插入元素15，当前长度为: %d\n", list.length);
	listElem(&list);

	//删除元素
	ElemType deletedElem;
	delete(&list, 3, &deletedElem);
	printf("删除位置3的元素: %d，当前长度为: %d\n", deletedElem, list.length);
	listElem(&list);

	//查找元素
	int pos = find(&list, 25);
	if (pos) {
		printf("元素25在顺序表中的位置为: %d\n", pos);
	} else {
		printf("元素25未找到\n");
	}

	//链表
	//初始化链表
	Node* head = initLinkedList();
	printf("链表初始化完成，头结点数据为: %d\n", head->data);
	printf("目前占用的存储空间为: %d\n", sizeof(Node));

	//头插法插入元素
	headInsert(head, 10);
	headInsert(head, 20);
	headInsert(head, 30);
	headInsert(head, 40);

	//遍历链表
	traverseLinkedList(head);

	//尾插法插入元素
	Node* tail = getTail(head);
	printf("当前尾节点数据为: %d\n", tail->data);
	tail = tailInsert(tail, 50);
	tail = tailInsert(tail, 60);
	tail = tailInsert(tail, 70);
	tail = tailInsert(tail, 80);

	//遍历链表
	traverseLinkedList(head);

	//指定位置插入元素
	insertAtPosition(head, 3, 35);
	printf("在位置3插入元素35\n");
	traverseLinkedList(head);

	//删除节点
	ElemType deletedNode;
	printf("删除位置4的节点\n");
	deleteAtPosition(head, 4, &deletedNode);
	printf("删除的节点数据为: %d\n", deletedNode);
	traverseLinkedList(head);

	//获取链表长度
	int length_1 = getLinkedListLength(head);
	printf("链表长度为: %d\n", length_1);

	//释放链表内存
	freeLinkedList(head);
	int length_2 = getLinkedListLength(head);
	printf("链表长度为: %d\n", length_2);

	//双向链表
	doublyNode* List = initdoublyLinkedList();
	//头插法
	insertdoublyHead(List, 10);
	insertdoublyHead(List, 20);
	insertdoublyHead(List, 30);
	traversedoublyLinkedList(List);
	
	//尾插法
	doublyNode* doublytail=getdoublyTail(List);
	doublytail=insertdoublyTail(doublytail, 50);
	doublytail=insertdoublyTail(doublytail, 60);
	doublytail=insertdoublyTail(doublytail, 70);
	traversedoublyLinkedList(List);

	//指定位置插入
	insertdoublyAtPosition(List, 3, 35);
	printf("在位置3插入元素35\n");
	traversedoublyLinkedList(List);

	//删除节点
	ElemType deleteddoublyNode;
	printf("删除位置4的节点\n");
	deletedoublyAtPosition(List, 4, &deleteddoublyNode);
	printf("删除的节点数据为: %d\n", deleteddoublyNode);
	traversedoublyLinkedList(List);


	//释放双向链表内存
	freedoublyLinkedList(List);


	return 0;
}
