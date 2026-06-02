#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//1.使用malloc（memory allocate）函数动态分配内存
//void* malloc(size_t)
//如果成功，会返回从堆内存上分配的内存块的地址；如果失败，会返回NULL
//2.使用分配的内存
//3.使用free函数释放内存


typedef struct {
	int x;
	int y;
}p1;

void fun(int** temp) {
	*temp = (int*)malloc(sizeof(int));
	**temp = 100;
}




int main() {
	int* ptr; // 定义一个整型指针
	ptr = (int*)malloc(sizeof(int)); // 动态申请一块int大小内存，将首地址赋值给ptr
	printf("已分配内存的地址: %p\n", (void*)ptr); // 打印动态分配内存的地址
	printf("赋值前内存里的数据: %d\n", *ptr); // 输出随机垃圾值，刚申请的堆内存未初始化
	free(ptr); // 释放这块申请的内存

	char* str; // 定义字符型指针
	str = (char*)malloc(10); // 动态分配可存放10个字符的内存空间
	strcpy(str, "Hello"); // 把字符串复制到动态内存中
	printf("动态内存中的字符串: %s\n", str); // 打印保存在动态内存里的字符串
	free(str); // 释放字符串占用的动态内存

	//为整型数组动态分配内存
	int* arr;
	int n = 5; // 数组长度
	arr = (int*)malloc(n * sizeof(int)); // 动态开辟存放n个int元素的数组空间
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1; // 给数组元素赋值初始化
	}
	printf("数组元素: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr); // 释放数组占用的动态内存

	//为结构体变量动态分配内存
	p1* p;
	p = (p1*)malloc(sizeof(p1));
	p->x = 15;
	p->y = 20;
	printf("结构体数据: x = %d, y = %d\n", p->x, p->y);
	free(p);


	//动态内存分配时传值的问题，利用指针的指针来实现函数内修改主函数中的变量值
	int *pp = NULL;
	fun(&pp);
	printf("%d\n", pp);
	//在函数fun中，我们传递了pp的地址（&pp），因此temp是一个指向pp的指针。
	// 当我们在fun函数中使用*temp时，我们实际上是在修改pp的值。
	// 通过malloc分配内存并将值100赋给**temp，我们成功地修改了pp的值，使其指向新分配的内存，并且该内存中的值为100。


	return 0;
}