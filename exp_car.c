#include <stdio.h>
#include <string.h>

#define SIZE 20

struct Car {
	char brand[SIZE];
	char model[SIZE];
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

struct Car compareCars(struct Car car1, struct Car car2) {
	if (car1.price > car2.price) {
		return car1;
	}
	return car2;
}

int main() {
	struct Car car1, car2;
	
	printf("Car 1:\n");
	printf("Brand: ");
	s_gets(car1.brand, SIZE);
	printf("Model: ");
	s_gets(car1.model, SIZE);
	printf("Price: ");
	scanf("%f", &car1.price);
	while (getchar() != '\n');
	
	printf("\nCar 2:\n");
	printf("Brand: ");
	s_gets(car2.brand, SIZE);
	printf("Model: ");
	s_gets(car2.model, SIZE);
	printf("Price: ");
	scanf("%f", &car2.price);
	while (getchar() != '\n');
	
	struct Car moreExpensive = compareCars(car1, car2);
	
	printf("\nThe more expensive car is %s %s - $%.2f\n",
		moreExpensive.brand,
		moreExpensive.model,
		moreExpensive.price);
		
	return 0;
}
