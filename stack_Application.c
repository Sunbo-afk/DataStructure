#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100


typedef int ElemType;

typedef struct {
	ElemType* data;
	int top;
}Stack;

typedef enum {
	LEFT_PARE,RIGHUT_PARE,ADD,SUB,MUL,DIV,MOD,EOS,NUM
}contentType;



