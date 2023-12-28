#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

int is_empty() {
	return(top == -1);
}

int is_full() {
	return (top == (MAX_STACK_SIZE-1));
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
	//먼저 top 증가 그리고 추가
}
element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
	// 먼저 수행  그 다음 빼기
}
element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top];
}

int main(void) {
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());

	return 0;
}