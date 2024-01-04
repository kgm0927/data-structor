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
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}

element dequeue(QueueType* q) {
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");

	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

// =====����ť �ڵ� ��=====

int main(void) {
	QueueType queue;
	int element;
	
	init_queue(&queue);
	printf("--������ �߰� �ܰ�--\n");

	while (!is_full(&queue))
	{
		printf("������ �Է��Ͻÿ�: ");
		scanf("%d", &element);
		enqueue(&queue, element);
		queue_print(&queue);

	}
	printf("ť�� ��ȭ�����Դϴ�. \n\n");

	printf("--������ ���� �ܰ�--\n");
	while (!is_empty(&queue))
	{
		element = dequeue(&queue);
		printf("������ ����: %d \n", element);
		queue_print(&queue);
	}
	printf("ť�� ��������Դϴ�. \n");
	return 0;
}

//
//			5.3 ����ť
// 
// 
// ����ť�� �����ϱ�� ������ �������� �ִ�. �� front�� rear�� ���� ��� ������ �ϱ� ������ �������� �迭�� ����
// �����ϰ� �ǰ� �迭�� �պκ��� ��� �ִ��� ������� ���Ѵٴ� ���̴�. ���� �ֱ������� ��� ��ҵ��� ��������
// �̵����Ѿ� �Ѵ�. �̷� ������ ��ҵ��� �̵���Ű�� �ذ��� ������ �Ź� �̵���Ű�� ����� �ð��� �ɸ��� ����
// ���α׷� �ڵ��� ����������.
// 
// 
// �� ������ �迭�� �������� �������� ���� �������� �����ϸ� ���� �ذ�ȴ�. ��, front�� rear�� ���� �迭�� ����(MAX_QUEUE_SIZE-1)��
// �����ϸ� ������ �����Ǵ� ���� 0�� �ǵ��� �ϴ� ���̴�. �� ������ ���� �迭�� �������� ó���� ���� ����Ǿ� �ִٰ� �����ϴ� ���̴�.
// ���⼭ ���� �迭�� �������� ��ȭ�Ǵ� ���� �ƴϴ�. �׳� ��������� �׷��ٴ� �ǹ��̴�.
// 
// 
// ����ť������ front�� rear�� ������ �ణ ����ȴ�. ���� �ʱⰪ�� -1�� �ƴ� 0�̴�. �� front�� �׻� ť�� ù ��° ����� �ϳ� ����,
// rear�� ������ ��Ҹ� ����Ų��. ó���� front, rear�� ��� 0�̰� ���� �ÿ��� rear�� ���� �����ǰ�, ������ ��ġ�� ���ο� �����Ͱ� 
// ���Եȴ�. �� ���� �ÿ��� front�� ���� ������ ����, ������ ��ġ���� �����͸� �����Ѵ�. �̷� ������ �����ϸ� ������ ����.
// 
// 
// front�� rear�� ���� ������ ���� ť�� ��� ������ ��Ÿ����. ����ť������ �ϳ��� �ڸ��� �׻� ����д�. �ֳ��ϸ� ��ȭ ���¿� ���� ���¸�
// �����ϱ� ���ؼ��̴�. ���� �� �ڸ��� ������� �ʴ´ٸ� ������¿� ��ȭ ���¸� ������ �� ���� ���̴�. ���� ���� ť���� ���� front==rear
// �̸� ���� ���°� �ǰ� ���� front�� rear���� �ϳ� �տ� ������ ��ȭ ���°� �ȴ�.
// 
// 
// 
// 
// 
// 
//			����ť�� ����, ���� �˰���
// 
// 
// ���� �����̳� ������ �ϱ� ���� front�� rear�� ���� ȸ�����Ѽ� �ϳ� ������Ű�� ������ ��ġ�� �����͸� ���� �Ǵ� �����Ѵ�.
// ����ť�� ������ �־ �߿��� ���� front�� rear�� �������� ȸ�����Ѿ� �Ѵٴ� ���̴�. �̴� ������ ������ %�� �̿��Ͽ� ����
// ������ �� �ִ�.
// 
//	--------------------------------------------------------------------------------------------------------------------
//		front<-(front+1)%MAX_QUEUE_SIZE;
//		rear<-(rear+1)%MAX_QUEUE_SIZE;
// ---------------------------------------------------------------------------------------------------------------------
// 
// ���� �Ŀ� ���Ͽ� front�� rear���� (MAX_QUEUE_SIZE-1)���� �ϳ� �����Ǹ� 0���� �ȴ�. �� ���� MAX_QUEUE_SIZE�� 5�� �����ϸ�,
// front�� rear���� 0,1,2,3,4,0�� ���� ��ȭ�ȴ�.
// 
// 
// 
//		�˰��� 5.1 ����ť������ ���� �˰���
// 
//			enqueue(Q,x):
//				rear<-(rear+1)%MAX_QUEUE_SIZE;
//				Q[rear]<-x;
// 
//		�˰��� 5.2 ����ť������ ���� �˰���
//		
//			dequeue(Q):
//				front<-(front+1)%MAX_QUEUE_SIZE;
//				return Q[front];
// 
// 
// 
//			����ť�� ����
// 
// 
// ���⼭ ������ ���� front�� rear�� ����Ű�� �ִ� ��ġ�� �ǹ��̴�. �ٽ� �����ϸ� ����ť������ front�� ù ��° ��� �ϳ� ����,
// rear�� ������ ��Ҹ� ����Ų��. ���� ������ �� ���� rear�� ������ ���� �ϳ� ������Ű�� ������ ��ġ�� ������ �Ͽ��� �ϰ�, ������
// �� ���� ���� front�� ������Ų ����, �� ��ü���� �����͸� ���� �;� �Ѵ�.
// 
//