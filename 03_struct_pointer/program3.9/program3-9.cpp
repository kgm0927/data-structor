#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main(void) {
	student* s;

	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� ����. \n");
		exit(1);
	}

	strcpy((*s).name, "Park");
	s->age = 20;

	free(s);
	return 0;
}