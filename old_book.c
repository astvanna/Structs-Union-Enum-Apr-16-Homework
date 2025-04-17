#include <stdio.h>
#include <string.h>
#define TITLE_SIZE 50
#define AUTHOR_SIZE 30
#define NUM_BOOKS 4

struct Book {
	char title[TITLE_SIZE];
	char author[AUTHOR_SIZE];
	int year;
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
	struct Book books[NUM_BOOKS];
	int oldest_index = 0;
	
	for (int i = 0; i < NUM_BOOKS; i++) {
		printf("\nBook %d:\n", i + 1);
		printf("Title: ");
		s_gets(books[i].title, TITLE_SIZE);
		printf("Author: ");
		s_gets(books[i].author, AUTHOR_SIZE);
		printf("Year: ");
		scanf("%d", &books[i].year);
		while (getchar() != '\n');
		
		if (books[i].year < books[oldest_index].year) {
			oldest_index = i;
		}
	}
	
	printf("\nOldest Book:\n");
	printf("Title: %s\n", books[oldest_index].title);
	printf("Author: %s\n", books[oldest_index].author);
	printf("Year: %d\n", books[oldest_index].year);
	
	return 0;
}
