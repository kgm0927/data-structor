#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100

//
//			8.6 ���� ��ȸ
// 
// ǥ������ ��ȸ ����� �ƴ����� ������ȸ�� ���� ���ȴ�. '���� ��ȸ(level order)'�� �� ��带 ���� ������ �˻��ϴ�
// ��ȸ����̴�. ��Ʈ ����� ������ 1�̰� �Ʒ��� ���������� ������ �����Ѵ�. ������ ������ ��쿡�� �¿��� ��� �湮�Ѵ�.
// ���ݱ����� ��ȸ���� ������ ����ߴ� �Ϳ� ���� ��ȸ�� ť�� ����ϴ� ��ȸ���̴�.
// 
// 
// 
// 
// ���� ��ȸ �ڵ�� ť�� �ϳ��� ��尡 ������ ��� �ݺ��ϴ� �ڵ�� �̷���� �ִ�. ���� ť�� �ִ� ��带 ������ �湮�� ����,
// �� ����� �ڽ� ��带 ť�� �����ϴ� ������ �ѹ��� �ݺ��� ������.�̷��� �ݺ��� ť�� �� �̻��� ��尡 ���� ������ ����Ѵ�.
// 
// 
//		Ʈ�� ���� ��ȸ �˰���
// ------------------------------------------------------------------------------------------------------------------------
// 
//		level_order(root):
// 1. initialize queue;
// 2. if(root==null) then return;
// 3. enqueue(queue,root);
// 4. while is_empty(queue)!=TRUE do
// 5.	x <- dequeue(queue);
// 6.	print x->data;
// 7.	if(x->left!=NULL) then
// 8.		enqueue(queue,x->left);
// 9.	if(x->right!=NULL) then
// 10.		enqueue(queue,x->left);
// ------------------------------------------------------------------------------------------------------------------------
// 
// 
// 
// ���� ��ȸ�� �����ϸ� ������ ����. �տ����� ť�� �ҽ��� �� ���α׷��� �����Ͽ� �������ϸ� �ȴ�.
// �ٸ� ť�� ��� Ÿ���� ������ �ƴ϶� �������̹Ƿ� ���α׷� 8.5�� ���� ť�� elementŸ���� �ٽ� ������
// �־�� �Ѵ�.
//


typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;

}TreeNode;



// ================== ����ť �ڵ� ���� ====================

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
		error("ť�� ��ȭ�����Դϴ�.");
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

void level_order(TreeNode* ptr) {
	QueueType q;

	init_queue(&q); // ť �ʱ�ȭ

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
