#include<stdio.h>

void swap_f(int a, int b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("函数swap内部：a = %d, b = %d\n", a, b);
}

void swap_s(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	printf("函数swap内部：a = %d, b = %d\n", *a, *b);
}

int main() {
	int a;
	int b;
	int* p;
	a = 5;
	b = 10;
	p = &a; // p存储变量a的地址
	printf("%p,%d\n", &a, a);
	printf("%p,%d\n", &p, p); // p存放a的地址，因此此处输出a的地址

	*p = 20; // p指向a，修改*p等价于把a的值改成20
	printf("%p,%d\n", &a, a);
	printf("%p,%d\n", &p, p); // p存放a的地址，因此此处输出a的地址

	swap_f(a, b); // 采用值传递，无法修改主函数里a、b的原值
	printf("主函数中交换后：a = %d, b = %d\n", a, b); // a仍为20，b仍为10

	swap_s(&a, &b); // 地址传递（引用传递），可以修改主函数中原变量的值
	printf("主函数中交换后：a = %d, b = %d\n", a, b); // a和b完成数值互换

	//指针与数组
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr; // ptr指向数组首元素
	printf("%p,%p,%d\n", arr, ptr, *ptr);

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("通过数组：%d ", arr[i]); // 输出对应下标数组元素
	}

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("通过指针：%d ", *(ptr + i)); // 通过指针偏移取值输出元素
	}



	//二级指针（指针的指针）
	int a;
	int* p;
	p = &a;
	int** t = &p;
	//这个是指一个指向指针的指针,意为t的值保存这所指指针的地址（当我们用一个针指向另一个指针时，就需要使用指向指针的指针）。
	// t是一个指向int*类型的指针，也就是说t保存了一个int*类型的地址。
	//请看图片指针的指针以便理解
	//它可用于多维数组的访问，动态内存分配等场景。例如，在动态内存分配中，我们可能需要一个指向指针的指针来存储分配的内存地址。
	//后续在学习动态内存分配时会用到指向指针的指针
	//以及二叉树的创建和遍历等数据结构的实现中也会用到指向指针的指针



	return 0;
}