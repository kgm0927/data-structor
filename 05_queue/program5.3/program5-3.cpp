#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


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
		} while (i != q->front);

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

int main(void) {
	QueueType queue;
	int element;

	init_queue(&queue);
	srand(time(NULL));

	for (int i = 0; i < 100; i++)
	{
		if (rand() %5 == 0) {// 5로 나누어 떨어지면
			enqueue(&queue, rand() % 100);
		}
		queue_print(&queue);

		
			if (rand()%10==0){
				int data = dequeue(&queue);
			}
		
		queue_print(&queue);
	}
	return 0;
}

//
//				5.4 큐의 응용: 버퍼
// 
// 
// 대개 데이터를 생산하는 생산자 프로세스가 있고 데이터를 소비하는 소비자 프로세스가 있으며
// 이 사이에 큐로 구성되는 버퍼가 존재한다.
// 
//		* 생산자- 소비자 프로세스: 큐를 버퍼로 사용한다.
// 
//		* 교통 관리 시스템: 컴퓨터로 제어되는 신호등에서는 신호등을 순차적으로 제어하는데 원형큐가 사용된다.
// 
//		* CPU 스케줄링: 운영체제는 실행 가능한 프로세스들을 저장하거나 이벤트를 기다리는 프로세스들을 저장하기 위하여
//						몇 개의 큐를 사용한다.
// 
// 
// 
//