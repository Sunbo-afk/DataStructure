/*
#include<stdio.h>

int main() {
	int arr[5] = {1, 2, 3, 4, 5}; // Declare and initialize an array of integers
	int i;
	
	// Print the elements of the array
	printf("Array elements: ");
	for (i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Size of the array: %lu bytes\n", sizeof(arr)); // Get the size of the array in bytes
	printf("Number of elements in the array: %lu\n", sizeof(arr) / sizeof(arr[0])); // Calculate the number of elements in the array
	printf("Address of the first element: %p\n", (void *)&arr[0]); // Print the address of the first element
	printf("Address of the array itself: %p\n",&arr); // Print the address of the array itself (same as &arr[0])
		
	// Calculate the sum of the array elements
	int sum = 0;
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		sum += arr[i];
	}
	printf("Sum of array elements: %d\n", sum);
	
	
	return 0;

}
*/