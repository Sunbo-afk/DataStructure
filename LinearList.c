#include<stdio.h>
#define MAX_SIZE 100

typedef int ElemType;


//顺序表
typedef struct {
	ElemType data[MAX_SIZE];
	int length;
}SeqList;

void initList(SeqList * L) {
	L -> length = 0;
}//初始化顺序表



int main() {

	//顺序表
	//声明一个顺序表并初始化
	SeqList list;
	initList(&list);
	printf("顺序表初始化完成，当前长度为: %d\n", list.length);
	printf("目前占用的存储空间为: %d\n", sizeof(list.data));







	return 0;
}