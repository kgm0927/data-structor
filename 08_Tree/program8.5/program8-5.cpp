#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define MAX_QUEUE_SIZE 100

//
//			8.6 레벨 순회
// 
// 표준적인 순회 방법은 아니지만 레벨순회도 많이 사용된다. '레벨 순회(level order)'는 각 노드를 레벨 순으로 검사하는
// 순회방법이다. 루트 노드의 레벨이 1이고 아래로 내려갈수록 레벨은 증가한다. 동일한 레벨의 경우에는 좌에서 우로 방문한다.
// 지금까지의 순회법이 스택을 사용했던 것에 레벨 순회는 큐를 사용하는 순회법이다.
// 
// 
// 
// 
// 레벨 순회 코드는 큐에 하나라도 노드가 있으면 계속 반복하는 코드로 이루어져 있다. 먼저 큐에 있는 노드를 꺼내어 방문한 다음,
// 그 노드의 자식 노드를 큐에 삽입하는 것으로 한번의 반복을 끝낸다.이러한 반복을 큐에 더 이상의 노드가 없을 때까지 계속한다.
// 
// 
//		트리 레벨 순회 알고리즘
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
// 레벨 순회를 구현하면 다음과 같다. 앞에서의 큐의 소스를 이 프로그램에 연결하여 컴파일하면 된다.
// 다만 큐의 요소 타입이 정수가 아니라 포인터이므로 프로그램 8.5와 같이 큐의 element타입을 다시 정의해
// 주어야 한다.
//


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
