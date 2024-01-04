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
		error("ť�� ��ȭ�����Դϴ�.");
		return;
	}
	q->data[++(q->rear)] = item;
}

int dequeue(QueueType* q) {
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");
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
//			05 ť
// 
// 
//		5.1 ť �߻� ������ Ÿ��
// 
// 
// ������ ���, ���߿� ���� �����Ͱ� ���� ������ �����ε� ���� ť(queue)�� ���� ���� �����Ͱ� ���� ������ ������ 
// �̷��� Ư���� ���Լ���(FIFO: First-In First-Out)�̶�� �Ѵ�.
// 
// 
// ť�� �ڿ��� ���ο� �����Ͱ� �߰��ǰ� �����Ͱ� �ϳ��� �����Ǵ� ������ ������ �ִ�. ���������� ť�� ���ð� �ٸ� ����
// ������ ���, ���԰� ������ ���� �ʿ��� �Ͼ�� ���� �Ĵ�(rear)��� �ϰ� ������ �Ͼ�� ���� ����(front)�̶�� �Ѵ�.
// 
// 
// 
// ----------------------------------------------------------------------------------------------------------------------------
// 
//			*ADT 5.1 ť
// 
//	* ��ü: 0�� �̻��� ��ҵ�� ������ ���� ����Ʈ
//	* ����:
// 
//			create(max_size)::=
//				�ִ� ũ�Ⱑ max_size�� ����ť�� �����Ѵ�.
// 
//			init(q)::=
//				ť�� �ʱ�ȭ�Ѵ�.
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
//				if(is_full(q)) queue_empty ����;
//				else q�� �� �տ� �ִ� e�� �����Ͽ� ��ȯ�Ѵ�.
// 
//			peek(q)::=
//				if(is_empty(q))	queue_empty ����;
//				else q�� �� �տ� �ִ� e�� �о ��ȯ�Ѵ�.
// -----------------------------------------------------------------------------------------------------------
// 
// 
// �߻� �ڷ��� ť�� ������� �߻� �ڷ��� ���ð� ���� �����ϴ�. is_empty ������ ť�� ��� ������ TRUE�� ��ȯ�ϰ�,
// �׷��� ������ FALSE�� ��ȯ�Ѵ�. is_full ������ ť�� ���� á���� TRUE��, �׷��� ������ FALSE�� ��ȯ�Ѵ�.
// 
// 
// 
// ���� �߿��� ������ ���԰� ���� ������ enqueue�� dequeue�̴�.
// 
// 
//		enqueue: ť�� ��Ҹ� �߰��ϴ� �������μ� ť�� �� �ڿ� ��Ҹ� �߰��Ѵ�.
//		
//		dequeue: ť�� �� �տ� �ִ� ��Ҹ� ������ �ܺη� ��ȯ�Ѵ�.
// 
// ���ð��� �޸� ����, ������ ť�� �糡���� �Ͼ�� ������ �� ���캸�ƾ� �Ѵ�. ���ÿ����� ����, ������ �����Ͽ�
// top�̶� �Ҹ���� ������ 1���� �����ϴµ� ���� ť������ �� ���� ������ ���ȴ�. ���԰� ���õ� ������ rear��� �ϰ�
// ������ ���õ� ������ front��� �Ѵ�.
// 
// 
// ť�� ���ð� ���������� "���α׷����� ����"�μ� ���а� �̿�ȴ�.
// 
// 
// 
// 
//			5.2 ����ť
// 
// 
// ť�� ���ð� ���������� �����ϴ� ����� ���� �����̳� ���⼭�� ���� ������ ���, �� 1���� �迭�� ���� ����� ���캸��.
// ������ ������ �� �ִ� ť�� ���� ��, ���� ������ 1���� �迭�� �����ϰ� ����, ������ ���� ������ front�� rear�� �����.
// 
// 
// front�� rear�� �ʱⰪ�� -1�̴�. �����Ͱ� �����Ǹ� rear�� �ϳ� �����ϰ� �� ��ġ�� �����Ͱ� ����ȴ�. ������ ���� front��
// �ϳ� �����ϰ� front�� ����Ű�� ��ġ�� �ִ� �����͸� �����Ѵ�. ���� ���� ť�� ����ť(linear queue)��� �Ѵ�.
// 
// 
// 
// 
//