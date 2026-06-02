#include<Stdio.h>


//计算1-n的和
//非递归方式
int Sum(int n) {
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum = sum + i;
	}
	return sum;
}

//递归方式
int reSum(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return reSum(n - 1) + n;
	}
}

//求斐波那契数列第n项的值
//非递归的形式
int Fibonacci(int n) {
	int last1 = 1;
	int last2 = 1;
	int result = 0;
	for (int i = 3; i <= n; i++) {
		result = last1 + last2;
		last2 = last1;
		last1 = result;
	}
	return result;
}


//递归方式
int reFibonacci(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	else {
		return reFibonacci(n - 1) + reFibonacci(n - 2);
	}
}


//main函数测试
int main(){
	int n = 10;
	int a = Sum(n);
	int b = reSum(n);
	int c = Fibonacci(n);
	int d = reFibonacci(n);
	printf("%d %d %d %d", a, b, c, d);
	return 0;
}
