
#include<stdio.h>
#include<string.h>

int main() {
	char str1[20] = "Hello";
	char str2[20] ;
	char str3[40];
	strcpy(str2,"World");// Copy "World" to str2
	
	strcpy(str3, str1); // Copy str1 to str3
	strcat(str3, " ");  // Concatenate a space to str3
	strcat(str3, str2); // Concatenate str2 to str3
	printf("Combined String: %s\n", str3);
	strlen(str3); // Get the length of str3
	
	sizeof(str3); // Get the size of str3
	puts(str3); // Print str3
	strncpy(str2, "C Programming", 5); // Copy first 5 characters of "C Programming" to str2
	strncat(str3, " is fun!", 4); // Concatenate first 4 characters of " is fun!" to str3
	strncmp(str1, "Hello", 5); // Compare first 5 characters of str1 and "Hello"
	s
	return 0;
}
