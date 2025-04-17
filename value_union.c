#include <stdio.h>
#include <string.h>

union Value {
	int integerV;
	float floatV;
};

int main() {
	union Value val;
	
	val.integerV = 25;
	printf("Integer value: %d\n", val.integerV);
	
	val.floatV = 12.5;
	printf("Float value: %.2f\n", val.floatV);
	
	printf("Size of union: %zu\n", sizeof(union Value));
	
	return 0;
}
