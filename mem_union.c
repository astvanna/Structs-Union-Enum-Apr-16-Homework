#include <stdio.h>

union Data{
	int i;
	float f;
	char c;
};

int main(){
	union Data data;
	
	data.i = 10;
	printf("Assigning int value: 10\n");
	printf("int: %d\nfloat: %f\nchar: %c\n\n", data.i, data.f, data.c);
	
	data.f = 5.5;
	printf("Assigning float value: 5.5\n");
	printf("int: %d\nfloat: %f\nchar: %c\n\n", data.i, data.f, data.c);
	
	data.c = 'A';
	printf("Assigning char value: A\n");
	printf("int: %d\nfloat: %f\nchar: %c\n\n", data.i, data.f, data.c);
	
	printf("Size of union: %zu\n", sizeof(union Data));
	
	return 0;
}
