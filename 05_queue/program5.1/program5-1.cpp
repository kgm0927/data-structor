#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5


typedef int element;
typedef struct {
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];

}QueueType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
		exit(1);
}

void init_queue(QueueType* q) {
	q->rear = -1;
	q->front = -1;

}
void queue_print(QueueType* q) {
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear)
			printf("   | ");
		else
			printf("%d | ", q->data[i]);
	}
	printf("\n");
}


int is_full(QueueType* q) {
	if (q->rear == MAX_QUEUE_SIZE - 1)
		return 1;
	else
		return 0;
}

int is_empty(QueueType* q) {
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueue(QueueType* q, int item) {
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");
		return -1;

	}
	int item = q->data[++(q->front)];
	return item;
}

int main(void) {
	int item = 0;
	QueueType q;
	init_queue(&q);

	enqueue(&q, 10); queue_print(&q);
	enqueue(&q, 20); queue_print(&q);
	enqueue(&q, 30); queue_print(&q);

	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);
	item = dequeue(&q); queue_print(&q);

	return 0;
}


//
//			05 큐
// 
// 
//		5.1 큐 추상 데이터 타입
// 
// 
// 스택의 경우, 나중에 들어온 데이터가 먼저 나가는 구조인데 반해 큐(queue)는 먼저 들어온 데이터가 먼저 나가는 구조로 
// 이러한 특성을 선입선출(FIFO: First-In First-Out)이라고 한다.
// 
// 
// 큐는 뒤에서 새로운 데이터가 추가되고 데이터가 하나씩 삭제되는 구조를 가지고 있다. 구조상으로 큐가 스택과 다른 점은
// 스택의 경우, 삽입과 삭제가 같은 쪽에서 일어나는 곳을 후단(rear)라고 하고 삭제가 일어나는 곳을 전단(front)이라고 한다.
// 
// 
// 
// ----------------------------------------------------------------------------------------------------------------------------
// 
//			*ADT 5.1 큐
// 
//	* 객체: 0개 이상의 요소들로 구성된 선형 리스트
//	* 연산:
// 
//			create(max_size)::=
//				최대 크기가 max_size인 공백큐를 생성한다.
// 
//			init(q)::=
//				큐를 초기화한다.
// 
//			is_empty(q)::=
//				if(size==0) return TRUE;
//				else return FALSE;
// 
//			is_full(q)::=
//				if(size==max_size) return TRUE;
//				else return FALSE;
// 
//			enqueue(q,e)::=
//				if(is_full(q)) queue_empty 오류;
//				else q의 맨 앞에 있는 e를 제거하여 반환한다.
// 
//			peek(q)::=
//				if(is_empty(q))	queue_empty 오류;
//				else q의 맨 앞에 있는 e를 읽어서 반환한다.
// -----------------------------------------------------------------------------------------------------------
// 
// 
// 추상 자료형 큐의 연산들은 추상 자료형 스택과 아주 유사하다. is_empty 연산은 큐가 비어 있으면 TRUE를 반환하고,
// 그렇지 않으면 FALSE를 반환한다. is_full 연산은 큐가 가득 찼으면 TRUE를, 그렇지 않으면 FALSE를 반환한다.
// 
// 
// 
// 가장 중요한 연산은 삽입과 삭제 연산인 enqueue과 dequeue이다.
// 
// 
//		enqueue: 큐에 요소를 추가하는 연산으로서 큐의 맨 뒤에 요소를 추가한다.
//		
//		dequeue: 큐의 맨 앞에 있는 요소를 꺼내서 외부로 반환한다.
// 
// 스택과는 달리 삽입, 삭제가 큐의 양끝에서 일어나기 때문에 잘 살펴보아야 한다. 스택에서는 삽입, 삭제와 관련하여
// top이라 불리우는 변수가 1개만 존재하는데 비해 큐에서는 두 개의 변수가 사용된다. 삽입과 관련된 변수를 rear라고 하고
// 삭제와 관련된 변수를 front라고 한다.
// 
// 
// 큐도 스택과 마찬가지로 "프로그래머의 도구"로서 폭넓게 이용된다.
// 
// 
// 
// 
//			5.2 선형큐
// 
// 
// 큐도 스택과 마찬가지로 구현하는 방법이 여러 가지이나 여기서는 가장 간단한 방법, 즉 1차원 배열을 쓰는 방법을 살펴보자.
// 정수를 저장할 수 있는 큐를 만들 때, 먼저 정수의 1차원 배열을 정의하고 삽입, 삭제를 위한 변수인 front와 rear를 만든다.
// 
// 
// front와 rear의 초기값은 -1이다. 데이터가 증가되면 rear를 하나 증가하고 그 위치에 데이터가 저장된다. 삭제할 때도 front를
// 하나 증가하고 front가 가리키는 위치에 있는 데이터를 삭제한다. 위와 같은 큐를 선형큐(linear queue)라고 한다.
// 
// 
// 
// 
//