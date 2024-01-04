#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {// 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;


// 오류 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 초기화
void init_deque(DequeType* q) {
	q->front = q->rear = 0;

}


// 공백 상태 검출 함수
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(DequeType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d)=", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
		
	}
	printf("\n");
}

void add_rear(DequeType* q, element item) {
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");

	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q) {
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];

	
}

element get_front(DequeType* q) {
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");

	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
	}
	q->rear=(q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q)) {
		error("큐가 공백상태입니다.");
	}

	return q->data[q->rear];
}

int main(void) {
	DequeType queue;

	init_deque(&queue);

	for (int i = 0; i < 3; i++)
	{
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++)
	{
		delete_rear(&queue);
		deque_print(&queue);

	}
	return 0;
}

//
//			5.5 덱이란?
// 
// 
// 덱(deque)은 double-ended queue의 줄임말로서 큐의 전단(front)과 후단(rear)에서 모두 삽입과 삭제가 가능한 큐를 의미한다.
// 그렇지만 여전히 중간에 삽입하거나 삭제하는 것은 허용하지 않는다.
// 
// 
//			덱의 추상 자료형
// 
// 덱을 추상 자료형으로 정의하면 다음과 같다.
// ----------------------------------------------------------------------------------------------------------------------
//	ADT 5.2 Deque
// ----------------------------------------------------------------------------------------------------------------------
//	* 객체: n개의 element형의 요소들의 순서 있는 모임
//  * 연산:
//		
//		create() ::= 덱을 생성한다.
// 
//		init(dq) ::= 덱을 초기화한다.
// 
//		is_empty(dq) ::= 덱이 공백 상태인지 검사한다.
// 
//		is_full(dq) ::= 덱이 포화 상태인지 검사한다.
// 
//		add_front(dq,e) ::= 덱의 앞에 요소를 추가한다.
// 
//		add_rear(dq,e) ::= 덱의 뒤에 요소를 추가한다.
// 
//		delete_front(dq) ::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다.
// 
//		delete_rear(dq) ::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.
// 
//		get_front(q) ::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
// 
//		get_rear(q) ::= 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.
// ----------------------------------------------------------------------------------------------------------------------
// 
// 덱은 스택과 큐의 연산들을 모두 가지고 있다. 예를 들면 add_front와 delete_front 연산은 스택의 push와 pop 연산과
// 동일하다. 또한 add_rear 연산과 delete_front 연산은 각각 큐의 enqueue와 dequeue 연산과 같다.
// 
// 
// 
//			배열을 이용한 덱의 구현
// 
// 원형 큐와 덱은 공통점이 많은데, 원형 큐를 확장하면 덱도 손쉽게 구현할 수 있다. 덱도 원형 큐와 같이 전단과 후단을
// 사용한다. 따라서 큐에 사용한 배열 data와 front, rear를 그대로 사용하면 되고, 추가적인 데이터는 필요 없다.
// 
// 
/*
*	#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {// 큐 타입
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;
*/
// 
// 
// 
// 
//		연결된 덱의 구현
// 
// 스택이나 큐와 같이 덱도 연결 리스트로 구현할 수 있다. 그러나 연결된 덱을 구현하는 것은 연결된 스택이나 큐에 비해 더 복잡하다. 스택이나
// 큐와는 달리 덱은 전단과 후단에서 모두 삽입, 삭제가 가능하기 때문에 하나의 노드에서 알아야 할 정조가 더 많다. 구체적으로 선행노드와 후속노드를
// 가리키는 포인터 변수를 가져야 하는데, 이러한 구조를 이중 연결 리스트(double linked list)라고 부른다. 
// 
// 
//