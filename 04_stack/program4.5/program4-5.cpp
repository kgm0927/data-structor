#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100


//
//		4.3 ���� �迭 ����
// 
// ������ �ð��� �ʿ��� ������ ũ�⸦ �˾ƾ� �ϴµ� �����δ� ���� ��ƴ�. C���� malloc()�� ȣ���Ͽ��� ����ð��� �޸𸮸� �Ҵ� ���� �� �ִ�.
// 
// 
// realloc()�� ���� �޸��� ũ�⸦ �����ϴ� �Լ��μ� ���� ������ �����ϸ鼭 �־��� ũ��� ���� �޸𸮸� �ٽ� �Ҵ��Ѵ�. �迭�� ũ��� 2�辿 �þ��.
// 
// 
//

typedef int element;
typedef struct {
	element* data;// data�� �����ͷ� �����Ѵ�.
	int capacity;// ���� ũ��
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
	s->capacity = 1;
	s->data = (element*)malloc(s->capacity * sizeof(element));
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (s->capacity - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		s->capacity *= 2;
		s->data = (element*)realloc(s->data, s->capacity * sizeof(element));
	}
	s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

int main(void) {
	StackType s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	free(s.data);
	return 0;
}