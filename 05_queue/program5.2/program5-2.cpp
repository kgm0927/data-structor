#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}


int is_empty(QueueType* q) {

	return(q->front == q->rear);
}


int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


void queue_print(QueueType* q) {

	printf("QUEUE(front=%d rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		
		do
		{
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i!=q->front);

	}
	printf("\n");
}


void enqueue(QueueType* q, element item) {
	if (is_full(q))
	{
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}

element dequeue(QueueType* q) {
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");

	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// =====원형큐 코드 끝=====

int main(void) {
	QueueType queue;
	int element;
	
	init_queue(&queue);
	printf("--데이터 추가 단계--\n");

	while (!is_full(&queue))
	{
		printf("정수를 입력하시오: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);

	}
	printf("큐는 포화상태입니다. \n\n");

	printf("--데이터 삭제 단계--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("꺼내진 정수: %d \n", element);
		queue_print(&queue);
	}
	printf("큐는 공백상태입니다. \n");
	return 0;
}

//
//			5.3 원형큐
// 
// 
// 선형큐는 이해하기는 쉽지만 문제점이 있다. 즉 front와 rear의 값이 계속 증가만 하기 때문에 언젠가는 배열의 끝에
// 도달하게 되고 배열의 앞부분이 비어 있더라도 사용하지 못한다는 점이다. 따라서 주기적으로 모든 요소들을 왼쪽으로
// 이동시켜야 한다. 이런 식으로 요소들을 이동시키면 해결은 되지만 매번 이동시키면 상당한 시간이 걸리고 또한
// 프로그램 코딩이 복잡해진다.
// 
// 
// 이 문제는 배열을 선형으로 생각하지 말고 원형으로 생각하면 쉽게 해결된다. 즉, front와 rear의 값이 배열의 끝인(MAX_QUEUE_SIZE-1)에
// 도달하면 다음에 증가되는 값은 0이 되도록 하는 것이다. 즉 다음과 같이 배열이 원형으로 처음과 끝이 연결되어 있다고 생각하는 것이다.
// 여기서 실제 배열이 원형으로 변화되는 것이 아니다. 그냥 개념사응로 그렇다는 의미이다.
// 
// 
// 원형큐에서는 front와 rear의 개념이 약간 변경된다. 먼저 초기값은 -1이 아닌 0이다. 또 front는 항상 큐의 첫 번째 요소의 하나 앞을,
// rear는 마지막 요소를 가리킨다. 처음에 front, rear는 모두 0이고 삽입 시에는 rear가 먼저 증가되고, 증가된 위치에 새로운 데이터가 
// 삽입된다. 또 삭제 시에도 front가 먼저 증가된 다음, 증가된 위치에서 데이터를 삭제한다. 이런 식으로 생각하면 착오가 없다.
// 
// 
// front와 rear의 값이 같으면 원형 큐가 비어 있음을 나타낸다. 원형큐에서는 하나의 자리는 항상 비워둔다. 왜냐하면 포화 상태와 공백 상태를
// 구별하기 위해서이다. 만약 한 자리를 비워두지 않는다면 공백상태와 포화 상태를 구분할 수 없을 것이다. 따라서 원형 큐에서 만약 front==rear
// 이면 공백 상태가 되고 만약 front가 rear보다 하나 앞에 있으면 포화 상태가 된다.
// 
// 
// 
// 
// 
// 
//			원형큐의 삽입, 삭제 알고리즘
// 
// 
// 먼저 삽입이나 삭제를 하기 전에 front와 rear를 원형 회전시켜서 하나 증가시키고 증가된 위치에 데이터를 삽입 또는 삭제한다.
// 원형큐의 구현에 있어서 중요한 것은 front와 rear를 원형으로 회전시켜야 한다는 것이다. 이는 나머지 연산자 %를 이용하여 쉽게
// 구현할 수 있다.
// 
//	--------------------------------------------------------------------------------------------------------------------
//		front<-(front+1)%MAX_QUEUE_SIZE;
//		rear<-(rear+1)%MAX_QUEUE_SIZE;
// ---------------------------------------------------------------------------------------------------------------------
// 
// 위의 식에 의하여 front와 rear값은 (MAX_QUEUE_SIZE-1)에서 하나 증가되면 0으로 된다. 즉 만약 MAX_QUEUE_SIZE를 5로 정의하면,
// front와 rear값은 0,1,2,3,4,0과 같이 변화된다.
// 
// 
// 
//		알고리즘 5.1 원형큐에서의 삽입 알고리즘
// 
//			enqueue(Q,x):
//				rear<-(rear+1)%MAX_QUEUE_SIZE;
//				Q[rear]<-x;
// 
//		알고리즘 5.2 원형큐에서의 삭제 알고리즘
//		
//			dequeue(Q):
//				front<-(front+1)%MAX_QUEUE_SIZE;
//				return Q[front];
// 
// 
// 
//			원형큐의 구현
// 
// 
// 여기서 주의할 점은 front와 rear가 가리키고 있는 위치의 의미이다. 다시 설명하면 원형큐에서의 front는 첫 번째 요소 하나 앞을,
// rear는 마지막 요소를 가리킨다. 따라서 삽입을 할 때는 rear를 무조건 먼저 하나 증가시키고 증가된 위치에 삽입을 하여야 하고, 삭제를
// 할 때도 먼저 front를 증가시킨 다음, 그 위체에서 데이터를 꺼내 와야 한다.
// 
//