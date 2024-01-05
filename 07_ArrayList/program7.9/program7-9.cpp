#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//
//			7.5 연결 리스트로 구현한 스택
// 
// 
// 스택을 연결 리스트로 만들 수 있을까? 3장에서 배열을 이용하여 구현하는 방법이 소개되었다.
// 그러나 스택은 연결리스트를 이용해서도 구현될 수 있다.
// 
// 이러한 스택이나 큐를 연결된 스택(linked stack)이라고 한다. 외부에서 보기에는 배열을 이용한 스택이나
// 연결 리스트를 이용한 스택이나 전혀 차이가 없다. 즉 제공되는 외부 인터페이스는 완전히 동일하다. 달라지는
// 것은 외부 구현이다. 연결 리스트를 이용하여 스택을 만들게 되면 장점이 크다. 즉 크기가 제한되지 않는다는
// 것이다. 동적 메모리 할당만 할 수 만 있다면 스택에 새로운 요소를 삽입할 수 있다. 반면에 연결 리스트를 
// 이용한 스택은 동적 메모리 할당이나 해제를 해야 하므로 삽입이나 삭제 시간은 좀 더 걸릴 수 있다.
// 
// 
// 
// 연결된 스택은 기본적으로 연결 리스트이기 때문에 다음과 같이 노드를 정의한다. 노드는 우리가 저장하고 싶은
// 데이터 필드와 다음 노드를 가리키기 위한 포인터가 들어 있는 링크 필드로 구성된다. 또한 top은 더 이상
// 정수가 아니고 노드를 가리키는 포인터로 선언된다. 또한 연결된 스택에 관련된 데이터는 top 포인터뿐이지만
// 일관성을 위하여 LinkedStackType이라는 구조체 타입으로 정의되었다. 모든 함수들은 이 구조체의 포인터를
// 매개 변수로 받아서 사용한다.
// 
// 
// 연결된 스택에서는 헤드 포인터가 top이라는 이름으로 불리는 것 외에는 별 차이점이 없다. 삽입 연산에는
// 먼저 동적 메모리 할당으로 노드를 만들고 첫 번째 노드로 삽입한다.
// 
// 삭제 연산에는 top의 값을 top->link로 바꾸고 기존의 top이 가리키는 노드를 동적 메모리 해제하면 된다.
// 
// 연결된 스택에서 공백상태는 연결 리스트와 마찬가지로 top 포인터가 NULL인 경우이다.
// 
//

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;


typedef struct {
	StackNode* top;
}LinkedStackType;


void init(LinkedStackType* s) {
	s->top = NULL;
}


int is_empty(LinkedStackType* s) {
	return(s->top == NULL);
}


int is_full(LinkedStackType* s) {
	return 0;
}


void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}


void print_stack(LinkedStackType* s) {
	for (StackNode *p = s->top; p !=NULL; p=p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL \n");
}


element pop(LinkedStackType* s) {
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}


element peek(LinkedStackType* s) {
	if (is_empty(s))
	{
		fprintf(stderr, "스택이 비어있음\n"); exit(1);
	}
	else {
		return s->top->data;
	}
}


int main(void) {
	LinkedStackType s;
	
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);

	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);

	return 0;
}