#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;

}TreeNode;



// ================== 원형큐 코드 시작 ====================

typedef TreeNode* element;


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
	return (q->front == q->rear);
}

int is_full(QueueType* q) {

	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {

	if (is_full(q))
		error("큐가 포화상태입니다.");
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

void level_order(TreeNode* ptr) {
	QueueType q;

	init_queue(&q); // 큐 초기화

	if (ptr == NULL)return;

	enqueue(&q, ptr);

	while (!is_empty(&q))
	{
		ptr = dequeue(&q);
		printf(" [%d] ", ptr->data);
		if (ptr->left)
			enqueue(&q, ptr->left);
		if (ptr->right)
			enqueue(&q, ptr->right);

	}


}

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 1,NULL,NULL };
TreeNode n3 = { 1,NULL,NULL };
TreeNode n4 = { 1,NULL,NULL };
TreeNode n5 = { 1,NULL,NULL };
TreeNode n6 = { 1,NULL,NULL };


TreeNode* root = &n6;

int main(void) {

}
