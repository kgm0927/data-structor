#include <stdio.h>
#define  TRUE 1
#define FALSE 0

//
//			8.10 스레드 이진트리
// 
// 이진 트리 순화는 순환 호출을 사용한다. 하지만 이렇게 되면 개수가 많아지고 트리의 높이가 커지게 되면
// 상당히 비효율적일 수도 있다. 따라서 순회를 순환 호출 없이, 즉 스택의 도움 없이 할 수 있을까?
// 
// 우리는 이진 트리의 노드에 많은 NULL 링크들이 존재함을 알고 있다. 만약 트리의 노드의 개수를 n개라고 하면
// 각 노드당 2개의 링크가 있으므로 총 링크의 개수는 2n개가 되고 이들 링크 중에서 n-1개의 링크들이 루트노드를
// 제외한 n-1개의 다른 노드들을 가리킨다. 따라서 2n개 중에서 n-1은 NULL 링크가 아니지만 나머지 n+1개의 
// 링크는 NULL임을 알 수 있다.
// 
// 이들 NULL 링크에 중위 순회 시에 선행 노드인 중위 선행자(inorder predecessor)나 중위 순회시에 후속 노드인
// 중위 후속자(inorder successer)를 저장시켜 놓은 트리가 '스레드 이진 트리'(threaded binary tree)이다. 스레드(thread),
// 즉 실을 이용하여 노드들은 순회 순서대로 연결시켜 놓은 트리이다.
// 
// 
// 그러나 만약 이런 식으로 NULL 링크에 스레드가 저장되면 링크에 자식을 가리키는 포인터가 저장되어 있는지 아니면
// NULL이 저장되어야 하는데 대신 스레드가 저장되어 있는지를 구별해주는 태그 필드가 필요하다.
//
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;
//
// 따라서 is_thread가 TRUE 이면 right는 중위 후속자이고 is_thread가 FALSE이면 오른쪽 자식을 가리키는 포인터가 된다. 만약
// 스레드 이진 트리가 구성되었다고 가정하였을 경우, 중위 순회 연산은 어떻게 변경되어야 하는가? 먼저 노드 p의 중위 후속자를
// 반환하는 함수 find_successor를 보면, p의 is_thread가 TRUE로 되어 있으면 바로 오른쪽 자식이 중위 후속자가 되므로 오른쪽
// 자식을 반환한다.
// 
// 만약 is_thread가 TRUE가 아닌 경우에는 서브 트리의 가장 왼쪽 노드로 가야한다. 따라서 왼쪽 자식이 NULL이 될 때까지 왼쪽
// 링크를 타고 이동한다.
// 
//

TreeNode* find_successor(TreeNode* p) {
	TreeNode* q = p->right;

	if (q == NULL || p->is_thread == TRUE) return q;


	while (q->left != NULL) q = q->left;

	return q;

}

TreeNode n1 = { 'A',NULL,NULL,1 };
TreeNode n2 = { 'B',NULL,NULL,1 };
TreeNode n3 = { 'C',&n1,&n2,0 };
TreeNode n4 = { 'D',NULL,NULL,1 };
TreeNode n5 = { 'E',NULL,NULL,0 };
TreeNode n6 = { 'F',&n4,&n5,0 };
TreeNode n7 = { 'G',&n3,&n6,0 };

TreeNode* exp = &n7;


//
// 순회는 가장 오른쪽부터 시작하기 때문에 따라서 왼쪽 자식이 NULL이 될 때까지 왼쪽 링크를 타고 이동한다.
// 다음으로 데이터를 출력하고 중위 후속자를 찾는 함수를 호출하여 후속자가 NULL이 아니면 계속 루프를 반복한다.
// 
//

void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;

	while (q->left) q = q->left; // 우선 가장 왼쪽으로 간다.
	

	do
	{
		printf("%c->", q->data);
		q = find_successor(q);
	} while (q);
}

int main(void) {
	n1.right = &n3;
	n2.right = &n7;
	n4.right = &n6;

	thread_inorder(exp);
	printf("\n");
	return 0;
}