//链表的应用
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef int ElemType;

typedef struct Node {
	ElemType data;
	struct Node* next;
}Node;

//初始化链表
Node* initList() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = 0; //头结点数据域可存储链表长度或其他信息
	head->next = NULL;
	return head;
}

//遍历链表
void traverseList(Node* head) {
	Node* current = head->next;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
	printf("\n");
}

//插入数据
//头插法
int HeadInsert(Node* head, ElemType e) {
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
Node* TailInsert(Node* tail, ElemType e) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = e;
	tail->next = newNode;
	newNode->next = NULL;
	return newNode;
}


//双指针查找倒数第k个节点(尽可能小的时间复杂度)




//双指针查找链表的中间节点(尽可能小的时间复杂度)



//双指针查找两个单词相同后缀(尽可能小的时间复杂度)



//链表的反转(尽可能小的时间复杂度)



//链表的合并(尽可能小的时间复杂度)







int main() {
	Node* head = initList();
	printf("链表初始化完成，头结点数据为: %d\n", head->data);
	printf("目前占用的存储空间为: %d\n", sizeof(Node));
	//头插法插入元素
	HeadInsert(head, 10);
	HeadInsert(head, 20);
	HeadInsert(head, 30);
	printf("使用头插法插入元素后，链表中的元素为: ");
	traverseList(head);
	//尾插法插入元素
	Node* tail = getTail(head);
	tail = TailInsert(tail, 40);
	tail = TailInsert(tail, 50);
	printf("使用尾插法插入元素后，链表中的元素为: ");
	traverseList(head);
	return 0;


}