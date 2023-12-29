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


//				4.1 스택이란
// 
// 
// 스택(Stack): 가장 최근에 들어온 상자가 가장 위에 있게 되고, 또 먼저 나가게 되는 구조. 이러한 형태를 후입선출(LIFO: Last-In First_Out)이라고 한다.
//				스택에서의 입출력은 맨 위에서만 일어나고 스택의 중간에서는 데이터를 삭제할 수 없다.
// 
// 
// 스택 상단(stack top): 스택에서 입출력이 이루어지는 부분
// 
// 스택 하단(stack bottom): 반대쪽인 바닥부분
// 
// 
// 
// 요소(element): 스택에 저장되는 요소
// 
// 
// 
// 스택은 특히 자료의 출력순서가 입력순서의 역순으로 이루어져야 할 경우에 매우 요긴하게 사용된다. 예를 들어(A, B, C, D, E)의 데이터가 있을 때 데이터들의
// 순서를 (E, D, C, B, A)처럼 역순으로 하고 싶다면 데이터를 전부 스택에 입력했다가 다시 꺼내면 역순으로 만들 수 있다. 예를 들면 텍스트 에디터에서 "되돌리기(undo)"
// 기능을 구현할 대 스택을 사용할 수 있다. 왜냐하면 수행된 명령어들 중 가장 최근에 수행된 것부터 되돌리기를 하여야 하기 때문이다.
// 
// 
// 
// 
// 
// 
//		* 예제: 시스템 스택을 이용한 함수 호출
// 
// 컴퓨터 안에서는 수 많은 함수 호출이 이루어지는데, 함수는 실행이 끝나면 자신을 호출한 함수로 되돌아가야 한다. 이때 스택이 사용된다. 즉 스택은 복귀할 주소를
// 기억하는데 사용된다. 함수는 호출된 역순으로 되돌아가기 때문이다. 
// 
// 
// 
// 
// 
// 
//		* 추상 자료형 스택
// 
// 
// 스택을 추상 자료형으로 정의하여 본다. 추상 자료형으로서의 스택은 0개 이상의 요소를 가지는 선형 리스트의 일종으로 정의되면 스택에 요소를 추가하거나 삭제하는
// 연산과 현재 스택 상태를 검사하는 연산으로 나온다.
// 
// 
//					-ADT 4.1 Stack
//
//					객체: 0개 이상의 원소를 가지는 유한 선형 리스트
//	
//					연산:
// 
//						create(size)::= 최대 크기가 size인 공백 스택을 생성한다.
//			 
//					
//							is_full(s) ::=
//									if(스택의 원소수== size)return TRUE;
//									else return FALSE;
//			 
//							is_empty(s)::=
//									if(스택의 원소수==0)return TRUE;
//									else return FALSE;
//			 
//							push(s,item)::=
//									if(is_full(s)) return ERROR_STACKFULL;
//									else 스택의 맨 위에 item을 추가한다.
//			
//							pop(s)::=
//									if(is_empty(s))return ERROR_STACKEMPTY
//									else 스택의 맨 위의 원소를 제거해서 반환한다.
//					
//			
//	/						peek(s)::=
//	//								if(is_empty(s)) return ERROR_STACKEMPTY;
//									else 스택의 맨 위의 원소를 제거하지 않고 반환한다.
// 
// 
// 
// 
// 
// 
// push(A): 스택에 A가 삽입됨.
// 
// pop(B): 스택에 B가 빠져나감
// 
// is_empty(): 스택이 비어있음을 알림
// 
// is_full(): 스택이 꽉 차 있음을 알림
// 
// peek(): 스택의 맨 위를 그냥 지우지 않고 반환함.
// 
// 
////
//				전역변수로 구현하는 방법
// 
// 1차원 배열과 top 변수를 모두 전역변수로 구현한다. 전역 변수로 구현되기 때문에 배열이나 top 변수를 함수의 매개 변수로 전달할 필요가 없다.
// 스택에 저장되는 데이터의 타입은 typedef를 이용하여 element로 정의되었다. 현재는 정수형으로 정의되어 있다.push 연산은 top을 먼저 증가시킨
// 다음, 증가된 위치에 데이터를 저장한다. pop연산은 먼저 top이 가리키는 위치에서 데이터를 꺼내 온 다음, top을 하나 감소한다.
// 
//