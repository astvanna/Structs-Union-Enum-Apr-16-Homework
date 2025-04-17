#include <stdio.h>
#include <string.h>
#define NAME_SIZE 20
#define NUM_PRODUCTS 3

enum Category {ELECTRONICS, FOOD, CLOTHING};

struct Product {
	char name[NAME_SIZE];
	enum Category category;
	float price;
};

char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) {
		char *find = strchr(st, '\n');
		if (find) {
			*find = '\0';
		} else {
			while (getchar() != '\n') continue;
		}
	}
	return ret_val;
}

int main() {
	struct Product products[NUM_PRODUCTS];
	
	for (int i = 0; i < NUM_PRODUCTS; i++) {
		printf("\nProduct %d:\n", i + 1);
	
		printf("Name: ");
		s_gets(products[i].name, NAME_SIZE);
		
		printf("Category (0-ELECTRONICS, 1-FOOD, 2-CLOTHING): ");
		int num = 0;
		scanf("%d", &num);
		products[i].category = (enum Category)num;
		
		printf("Price: ");
		scanf("%f", &products[i].price);
		while (getchar() != '\n');
	}
	
	printf("\nFOOD Products:\n");
	for (int i = 0; i < NUM_PRODUCTS; i++) {
		if (products[i].category == FOOD) {
			printf("Name: %s\n", products[i].name);
			printf("Price: %.2f\n\n", products[i].price);
		}
	}
	
	return 0;
}
