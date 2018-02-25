#include <stdio.h>
#include <string.h>
#include <stdbool.h>



typedef struct myClass {
	int m_x;
	void(*add)(struct myClass*, int);
} myClass;

typedef struct Derived {
	myClass* clas;
	int(*add2)(struct Derived*, int);
} Derived;

typedef struct Derived2 {
	myClass* clas;
	int m_y;
	int(*add3)(struct Derived2*, int);
} Derived2;

void add3(Dervied2* clas, int num) {
	clas->clas->m_x = num;
	clas->m_y = num;
}

int add2(Derived* clas, int y) {
	int x = clas->clas->m_x;
	int a = x & y;
	int b = ~x & ~y;
	int z = ~a & ~b;
	return z;
}

void add(myClass* clas, int num) {
	clas->m_x = num;
}


myClass Install() {
	myClass p;
	p.add = &add;
	return p;
}
Derived Install2() {
	Derived p;
	p.clas = (struct myClass*)malloc(sizeof(struct myClass));
	p.clas->m_x = 1;
	p.add2 = &add2;
	return p;
}
Derived2 Install3() {
	Derived2 p;
	p.clas = (struct myClass*)malloc(sizeof(struct myClass));
	p.class->m_x = 2;
	p.add3 = &add3;
	return p;
}

int main() {
	myClass c = Install();
	c.m_x = 0;
	// printf("myClass : m_x: %d", c->m_x);
	myClass* p2 = &c;
	c.add(p2, 0);
	printf("myClass : m_x: %d \n", p2->m_x);
	Derived sa = Install2();
	Derived * pointer = &sa;
	int num = sa.add2(pointer, 1);
	printf("This is xor: %d", num);

	Derived2 saa = Install3();
}