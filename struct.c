/*
#include<stdio.h>

struct Point {
	int x;
	int y;
};

struct Point create_point(int x, int y) {
	struct Point p;
	p.x = x;
	p.y = y;
	return p;
}

//typedef and struct
typedef struct {
	int x;
	int y;
} Point2;

typedef struct {
	int x;
	int y;
} *PointPtr;

typedef struct point {
	int x;
	int y;
} Point3;

int main() {
	struct Point p1;
	p1.x = 10;
	p1.y = 20;
	printf("Point p1: (%d, %d)\n", p1.x, p1.y);
	struct Point p2 = create_point(30, 40); // Declare and initialize a struct variable
	printf("Point p2: (%d, %d)\n", p2.x, p2.y);

	//pointer to struct
	struct Point * ptr;
	ptr = &p1;

	(*ptr).x = 50; // This will cause undefined behavior because ptr is uninitialized
	(*ptr).y = 60; // This will also cause undefined behavior
	printf("Point ptr: (%d, %d)\n", (*ptr).x, (*ptr).y);
	ptr->x = 70; // This is equivalent to (*ptr).x = 50, and will also cause undefined behavior
	ptr->y = 80; // This is equivalent to (*ptr).y = 60, and will also cause undefined behavior
	printf("Point ptr: (%d, %d)\n", ptr->x, ptr->y);

	//typedef
	typedef int zx;
	typedef char zfx;
	int a = 1;
	zx a = 1; // This is equivalent to int a = 1;
	
	//typedef struct
	Point2 p3;
	
	return 0;

}
*/