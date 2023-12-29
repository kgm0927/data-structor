#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100


//
//		4.3 동적 배열 스택
// 
// 컴파일 시간에 필요한 스택의 크기를 알아야 하는데 실제로는 아주 어렵다. C언어에는 malloc()을 호출하여서 실행시간에 메모리를 할당 받을 수 있다.
// 
// 
// realloc()은 동적 메모리의 크기를 변경하는 함수로서 현재 내용은 유지하면서 주어진 크기로 동적 메모리를 다시 할당한다. 배열의 크기는 2배씩 늘어난다.
// 
// 
//

typedef int element;
typedef struct {
	element* data;// data은 포인터로 정의한다.
	int capacity;// 현재 크기
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
		fprintf(stderr, "스택 공백 에러\n");
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