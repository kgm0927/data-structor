#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100
#define MAX_STRING 100

//
//			스택의 요소를 구조체로 하기
// 
// 만약 스택에서 저장되어야 하는 값이 정수나 문자가 아니고 더 복잡한 구조를 가지는 요소이면
// 어떻게 해야 할까? 예를 들면 학생의 대한 정보라면 학생의 학번, 이름, 주소 등의 정보가 요소에 포함되어야
// 할 것이다. 이런 경우에는 스택에 구조체를 저장하면 된다.
// 
// 
//



typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element;
// 스택에 저장되는 데이터를 구조체로 정의된다.


element stack[MAX_STACK_SIZE];
int top = -1;



// 공백 상태 검출 함수
int is_empty() {
	return (top == -1);
}

// 포화 상태 검출 함수

int is_full() {
	return (top == (MAX_STACK_SIZE-1));
}

//삽입 함수

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else stack[++top] = item;
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return stack[top--];
}

element peek() {
	if (is_empty()) {
		fprintf(stderr, "공백에러");
		exit(1);
	}
	else return stack[top];
}

int main(void) {
	element ie = { 20190001,"Hong","Soeul" };
	element oe;

	push(ie);
	oe = pop();

	printf("학번: %d\n", oe.student_no);
	printf("이름: %s\n", oe.name);
	printf("주소: %s\n", oe.address);
	return 0;
}

//
// 지금부터는 스택에 저장되는 요소의 타입은 항상 element라고 가정한다. 만약 정수 스택이
// 필요하면 element 타입을 정수로 정의하면 된다.
// 
//
