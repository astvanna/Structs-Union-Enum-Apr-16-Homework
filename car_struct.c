#include <stdio.h>
#include <string.h>

#define SIZE 20

struct Car {
	char brand[SIZE];
	char model[SIZE];
	int year;
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

void findCars(struct Car cars[], int size) {
	int newidx = 0;
	int cheapidx = 0;
	
	for (int i = 1; i < size; i++) {
		if (cars[i].price < cars[cheapidx].price) {
			cheapidx = i;
		}
		if (cars[i].year > cars[newidx].year) {
			newidx = i;
		}
	}
	
	printf("\nCheapest Car: %s %s (%d) - $%.2f\n", 
		cars[cheapidx].brand, 
		cars[cheapidx].model, 
		cars[cheapidx].year, 
		cars[cheapidx].price);
	
	printf("Newest Car: %s %s (%d) - $%.2f\n", 
		cars[newidx].brand, 
		cars[newidx].model, 
		cars[newidx].year, 
		cars[newidx].price);
}

int main() {
	struct Car cars[3];
	
	for (int i = 1; i < 4; ++i) {
		printf("\nCAR %d\n", i);
		printf("Brand: ");
		s_gets(cars[i].brand, SIZE);
		printf("Model: ");
		s_gets(cars[i].model, SIZE);
		printf("Year: ");
		scanf("%d", &cars[i].year);
		printf("Price: ");
		scanf("%f", &cars[i].price);
		while (getchar() != '\n') continue;
	}
	
	printf("\nAll Cars\n");
	for (int i = 1; i < 4; ++i) {
		printf("\nCAR %d\n", i);
		printf("Brand: %s\n", cars[i].brand);
		printf("Model: %s\n", cars[i].model);
		printf("Year: %d\n", cars[i].year);
		printf("Price: $%.2f\n", cars[i].price);
	}
	
	findCars(cars, 3);
	
	return 0;
}
