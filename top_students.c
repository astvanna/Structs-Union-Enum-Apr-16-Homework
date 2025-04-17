#include <stdio.h>
#include <string.h>
#define NAME_SIZE 30
#define NUM_STUDENTS 5

struct Student {
	char name[NAME_SIZE];
	int age;
	float marks;
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
	struct Student students[NUM_STUDENTS];
	int top_student = 0;
	
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		printf("\nStudent %d:\n", i+1);
		printf("Name: ");
		s_gets(students[i].name, NAME_SIZE);
		printf("Age: ");
		scanf("%d", &students[i].age);
		printf("Marks: ");
		scanf("%f", &students[i].marks);
		while (getchar() != '\n');
		
		if (students[i].marks > students[top_student].marks) {
			top_student = i;
		}
	}
	
	printf("\nStudent with highest marks:\n");
	printf("Name: %s\n", students[top_student].name);
	printf("Age: %d\n", students[top_student].age);
	printf("Marks: %.2f\n", students[top_student].marks);
	
	return 0;
}
