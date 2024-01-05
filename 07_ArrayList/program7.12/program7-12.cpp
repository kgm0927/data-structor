#include <stdio.h>
#include <stdlib.h>

//
// 
//				7.6 ���� ����Ʈ�� ������ ť
// 
// ���� ����Ʈ�� �̿��Ͽ� ������ ���� �� �ִ� ��ó�� ť�� ���� ����Ʈ�� �̿��Ͽ� ���� ��
// �ִ�. ���Ḯ��Ʈ�� ������� ť�� '����� ť'(linked queue)��� �Ѵ�. ���� ����Ʈ�� ������
// ť�� �迭�� ������ ť�� ���Ͽ� ũ�Ⱑ ���ѵ��� �ʴ´ٴ� ������ ������ �ִ�. �ݸ� �迭��
// ������ ť�� ���Ͽ� �ڵ尡 �ణ �� ����������, ��ũ �ʵ� ������ �޸� ������ �� ���� ����Ѵ�.
// 
// �⺻���� ������ �ܼ� ���� ����Ʈ���ٰ� 2���� �����͸� �߰��� �Ͱ� ����. front �����ʹ� ������
// �����Ͽ� rear �����ʹ� ���԰� �����Ѵ�. front�� ���� ����Ʈ�� �� �տ� �ִ� ��Ҹ� ����Ű��,
// rear �����ʹ� �� �ڿ� �ִ� ��Ҹ� ����Ų��. ť�� ��Ұ� ���� ��쿡�� front�� rear�� NULL����
// �ȴ�.
//
//



//
//		����� ť ����
// 
// ����� ť�� ������ ���� ���ǵȴ�.
// 
//
typedef int element;		// ����� Ÿ��

typedef struct QueueNode {	// ť�� ����� Ÿ��
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {			// ť ADT ����
	QueueNode* front, * rear;
}LinkedQueueType;


// ť�� �ʱ�ȭ �Լ�
void init(LinkedQueueType* q) {
	q->front = q->rear = 0;
}


// ���� ���� ���� �Լ�
int is_empty(LinkedQueueType* q) {
	return(q->front == NULL);
}


// ��ȭ ���� ���� �Լ�
int is_full(LinkedQueueType* q) {
	return 0;
}


//
//			���� ����
// 
// ���� ������ ���� ���� �޸� �Ҵ��� ���Ͽ� ���ο� ��带 ������ ����, �����͸� �����ϰ�
// ���� ����Ʈ�� ���� ���ο� ��带 �߰��ϸ� �ȴ�.
// 
// ���� ť�� ��������̸� front�� rear ��� ���ο� ��带 ����Ű���� �ؾ� �Ѵ�. ���� ������°�
// �ƴϰ� ������ ��尡 �ִ� ����� rear�� ����Ű�� �ִ� ����� ��ũ �ʵ�� rear�� ���ο� ��带
// ����Ű���� �����ϸ� �ȴ�.
// 
// 
//


// ���� �Լ�
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
//			���� ����
// 
// ���� ������ ���� ����Ʈ�� ó������ ��带 �������� �ȴ�. ���� ������
// ���� ť�� ��������ΰ��� �˻��ؾ� �Ѵ�. ���� ������¶�� �翬�� ������ �ȴ�.
// ���� ���������� �����̸� ���� �޽����� ����ϰ� �����ϵ��� �Ǿ� �ִ�.
// ���� ������°� �ƴ϶�� front�� ����Ű�� ��带 temp�� ����Ű���� �ϰ�, front��
// front�� ��ũ������ �����Ѵ�. �׷��� front�� ���� ����Ű�� ����� ���� ��带 
// ����Ű�� �� ���̴�. 
// 
// �׷� ����, temp�� ����Ű�� ���κ��� �����͸� �������� ���� �޸� ������ ���Ͽ� �� ��带
// �����ϸ� �ȴ�.
// 
//



// ���� �Լ�
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;

	if (is_empty(q)) {
		fprintf(stderr, "������ ����ִ�.\n");
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
//			����� ť ���α׷�
// 
// ������ ����� ť�� ����ϴ� ��ü ���α׷��̴�. ���� ���� ������ front�̳� rear�� NULL �̸�
// ���� ���·� �Ǵ��� �� �ִ�. ���� ����Ʈ�� ���, �޸� �Ҵ�������� ������ ���� �ʴ� �� ��ȭ
// ���´� ���ٰ� ���ƾ� �Ѵ�.
// 
// 
//

// ����� ť �׽�Ʈ �Լ�
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