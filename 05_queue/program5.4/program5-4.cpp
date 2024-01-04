#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {// ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;


// ���� �Լ�
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// �ʱ�ȭ
void init_deque(DequeType* q) {
	q->front = q->rear = 0;

}


// ���� ���� ���� �Լ�
int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
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
		error("ť�� ��ȭ�����Դϴ�.");

	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q) {
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");
	}
		return q->data[(q->front + 1) % MAX_QUEUE_SIZE];

	
}

element get_front(DequeType* q) {
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");

	}
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");
	}
	q->rear=(q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q)) {
		error("ť�� ��������Դϴ�.");
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
//			5.5 ���̶�?
// 
// 
// ��(deque)�� double-ended queue�� ���Ӹ��μ� ť�� ����(front)�� �Ĵ�(rear)���� ��� ���԰� ������ ������ ť�� �ǹ��Ѵ�.
// �׷����� ������ �߰��� �����ϰų� �����ϴ� ���� ������� �ʴ´�.
// 
// 
//			���� �߻� �ڷ���
// 
// ���� �߻� �ڷ������� �����ϸ� ������ ����.
// ----------------------------------------------------------------------------------------------------------------------
//	ADT 5.2 Deque
// ----------------------------------------------------------------------------------------------------------------------
//	* ��ü: n���� element���� ��ҵ��� ���� �ִ� ����
//  * ����:
//		
//		create() ::= ���� �����Ѵ�.
// 
//		init(dq) ::= ���� �ʱ�ȭ�Ѵ�.
// 
//		is_empty(dq) ::= ���� ���� �������� �˻��Ѵ�.
// 
//		is_full(dq) ::= ���� ��ȭ �������� �˻��Ѵ�.
// 
//		add_front(dq,e) ::= ���� �տ� ��Ҹ� �߰��Ѵ�.
// 
//		add_rear(dq,e) ::= ���� �ڿ� ��Ҹ� �߰��Ѵ�.
// 
//		delete_front(dq) ::= ���� �տ� �ִ� ��Ҹ� ��ȯ�� ���� �����Ѵ�.
// 
//		delete_rear(dq) ::= ���� �ڿ� �ִ� ��Ҹ� ��ȯ�� ���� �����Ѵ�.
// 
//		get_front(q) ::= ���� �տ��� �������� �ʰ� �տ� �ִ� ��Ҹ� ��ȯ�Ѵ�.
// 
//		get_rear(q) ::= ���� �ڿ��� �������� �ʰ� �ڿ� �ִ� ��Ҹ� ��ȯ�Ѵ�.
// ----------------------------------------------------------------------------------------------------------------------
// 
// ���� ���ð� ť�� ������� ��� ������ �ִ�. ���� ��� add_front�� delete_front ������ ������ push�� pop �����
// �����ϴ�. ���� add_rear ����� delete_front ������ ���� ť�� enqueue�� dequeue ����� ����.
// 
// 
// 
//			�迭�� �̿��� ���� ����
// 
// ���� ť�� ���� �������� ������, ���� ť�� Ȯ���ϸ� ���� �ս��� ������ �� �ִ�. ���� ���� ť�� ���� ���ܰ� �Ĵ���
// ����Ѵ�. ���� ť�� ����� �迭 data�� front, rear�� �״�� ����ϸ� �ǰ�, �߰����� �����ʹ� �ʿ� ����.
// 
// 
/*
*	#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {// ť Ÿ��
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;
*/
// 
// 
// 
// 
//		����� ���� ����
// 
// �����̳� ť�� ���� ���� ���� ����Ʈ�� ������ �� �ִ�. �׷��� ����� ���� �����ϴ� ���� ����� �����̳� ť�� ���� �� �����ϴ�. �����̳�
// ť�ʹ� �޸� ���� ���ܰ� �Ĵܿ��� ��� ����, ������ �����ϱ� ������ �ϳ��� ��忡�� �˾ƾ� �� ������ �� ����. ��ü������ ������� �ļӳ�带
// ����Ű�� ������ ������ ������ �ϴµ�, �̷��� ������ ���� ���� ����Ʈ(double linked list)��� �θ���. 
// 
// 
//