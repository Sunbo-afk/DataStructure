
#include<stdio.h>

void fun_f(int n) {
	int sum = 0;

	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	printf("Sum: %d\n", sum);
}
int fun_s(int n) {
	int sum = 0;
	for (int i = 0; i <= n; i++) {
		sum += i;
	}
	return sum;
}
int main() {
	int n = 100;
	fun_f(n);
	int sum = fun_s(n);
	printf("Sum: %d\n", sum);
	return 0;
}
