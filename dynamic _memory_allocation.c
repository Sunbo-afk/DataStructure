/*
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

int main() {
	int* ptr; // Declare a pointer to an integer
	ptr = (int*)malloc(sizeof(int)); // Dynamically allocate memory for an integer and assign the address to ptr
	printf("Address of allocated memory: %p\n", (void*)ptr); // Print the address of the allocated memory
	printf("Value at allocated memory before assignment: %d\n", *ptr); // This will print an indeterminate value, as the allocated memory is uninitialized
	free(ptr); // Free the allocated memory

	char* str; // Declare a pointer to a character
	str = (char*)malloc(10); // Dynamically allocate memory for a string of 100 characters
	strcpy(str, "Hello"); // Copy a string into the allocated memory
	printf("String in allocated memory: %s\n", str); // Print the string stored in the allocated memory
	free(str); // Free the allocated memory for the string

	//dynamically allocate memory for an array of integers
	int* arr;
	int n = 5; // Size of the array
	arr = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1; // Initialize the array
	}
	printf("Array elements: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	free(arr); // Free the allocated memory for the array

	//dynamically allocate memory for an struct  of integers
	p1* p;
	p = (p1*)malloc(sizeof(p1));
	p->x = 15;
	p->y = 20;
	printf("Struct values: x = %d, y = %d\n", p->x, p->y);
	free(p);

	return 0;
 }
 */