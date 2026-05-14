/*
#include<stdio.h>

void swap_f(int a, int b){
	int temp;
	temp=a;
	a=b;
	b=temp;
	printf("Inside swap function: a = %d, b = %d\n", a, b);
}

void swap_s(int* a, int* b){
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	printf("Inside swap function: a = %d, b = %d\n", *a, *b);
}

int main(){
	int a;
	int b;
	int* p;
	a=5;
	b = 10;
	p=&a; // p now holds the address of a
	printf("%p,%d\n",&a,a);
	printf("%p,%d\n",&p,p); // p holds the address of a, so it will print the address of a

	*p=20; // This changes the value of a to 20, since p points to a
	printf("%p,%d\n",&a,a);
	printf("%p,%d\n",&p,p); // p holds the address of a, so it will print the address of a

	swap_f(a,b); // This will not change the values of a and b in main, because they are passed by value
	printf("After swap in main: a = %d, b = %d\n", a, b); // a will still be 20, and b will still be 10

	swap_s(&a,&b); // This will change the values of a and b in main, because they are passed by reference
	printf("After swap in main: a = %d, b = %d\n", a, b); // a and b will be swapped

	//pointer and array
	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr; // ptr points to the first element of the array
	printf("%p,%p,%d\n", arr, ptr, *ptr);

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		printf("通过数组：%d ", arr[i]); // Print the value pointed to by ptr
	}

	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		printf("通过指针：%d ", *(ptr + i)); // Print the value pointed to by ptr
	}

	return 0;
}
*/