#include <stdio.h>
#include <stdlib.h>

//
// 
//				7.6 연결 리스트로 구현한 큐
// 
// 연결 리스트를 이용하여 스택을 만들 수 있는 것처럼 큐도 연결 리스트를 이용하여 만들 수
// 있다. 연결리스트로 만들어진 큐를 '연결된 큐'(linked queue)라고 한다. 연결 리스트로 구현된
// 큐는 배열로 구현된 큐에 비하여 크기가 제한되지 않는다는 장점을 가지고 있다. 반면 배열로
// 구현되 큐에 비하여 코드가 약간 더 복잡해지고, 링크 필드 때문에 메모리 공간을 더 많이 사용한다.
// 
// 기본적인 구조는 단순 연결 리스트에다가 2개의 포인터를 추가한 것과 같다. front 포인터는 삭제와
// 관련하여 rear 포인터는 삽입과 관련한다. front는 연결 리스트의 맨 앞에 있는 요소를 가리키며,
// rear 포인터는 맨 뒤에 있는 요소를 가리킨다. 큐에 요소가 없는 경우에는 front와 rear는 NULL값이
// 된다.
//
//



//
//		연결된 큐 정의
// 
// 연결된 큐는 다음과 같이 정의된다.
// 
//
typedef int element;		// 요소의 타입

typedef struct QueueNode {	// 큐의 노드의 타입
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {			// 큐 ADT 구현
	QueueNode* front, * rear;
}LinkedQueueType;


// 큐의 초기화 함수
void init(LinkedQueueType* q) {
	q->front = q->rear = 0;
}


// 공백 상태 검출 함수
int is_empty(LinkedQueueType* q) {
	return(q->front == NULL);
}


// 포화 상태 검출 함수
int is_full(LinkedQueueType* q) {
	return 0;
}


//
//			삽입 연산
// 
// 삽입 연산은 먼저 동적 메모리 할당을 통하여 새로운 노드를 생성한 다음, 데이터를 저장하고
// 연결 리스트의 끝에 새로운 노드를 추가하면 된다.
// 
// 만약 큐가 공백상태이면 front와 rear 모두 새로운 노드를 가리키도록 해야 한다. 만약 공백상태가
// 아니고 기존의 노드가 있는 경우라면 rear가 가리키고 있는 노드의 링크 필드와 rear를 새로운 노드를
// 가리키도록 변경하면 된다.
// 
// 
//


// 삽입 함수
void enqueue(LinkedQueueType* q, element data) {

	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;

	if (is_empty(q))
	{
		q->front = temp;
		q->rear = temp;

	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}


//
//			삭제 연산
// 
// 삭제 연산은 연결 리스트의 처음에서 노드를 꺼내오면 된다. 삭제 연산은
// 먼저 큐가 공백상태인가를 검사해야 한다. 만약 공백상태라면 당연히 오류가 된다.
// 현재 구현에서는 오류이면 오류 메시지를 출력하고 종료하도록 되어 있다.
// 만약 공백상태가 아니라면 front가 가리키는 노드를 temp가 가리키도록 하고, front는
// front의 링크값으로 대입한다. 그러면 front는 현재 가리키는 노드의 다음 노드를 
// 가리키게 될 것이다. 
// 
// 그런 다음, temp가 가리키는 노드로부터 데이터를 꺼내오고 동적 메모리 해제를 통하여 이 노드를
// 삭제하면 된다.
// 
//



// 삭제 함수
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;

	if (is_empty(q)) {
		fprintf(stderr, "스택이 비어있다.\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;

		if (q->front = NULL)
			q->rear = NULL;

		free(temp);
		return data;

	}
}

void print_queue(LinkedQueueType* q) {
	QueueNode* p;
	for (p=q->front; p!=NULL; p=p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL\n");
}



//
//			연결된 큐 프로그램
// 
// 다음은 연결된 큐를 사용하는 전체 프로그램이다. 공백 상태 검출은 front이나 rear가 NULL 이면
// 공백 상태로 판단할 수 있다. 연결 리스트의 경우, 메모리 할당과정에서 오류가 있지 않는 한 포화
// 상태는 없다고 보아야 한다.
// 
// 
//

// 연결된 큐 테스트 함수
int main(void) {
	LinkedQueueType queue;
	init(&queue);

	enqueue(&queue, 1); print_queue(&queue);
	enqueue(&queue, 2); print_queue(&queue);
	enqueue(&queue, 3); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);
	dequeue(&queue); print_queue(&queue);

	return 0;
}