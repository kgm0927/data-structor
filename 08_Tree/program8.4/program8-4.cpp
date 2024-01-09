#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define  SIZE 100

//				8.5 반복적 순회
// 
// 
// 앞에서는 순회를 순환 호출을 이용하여 구현하였다. 물론 이것은 표준적인 방법이고 쉽게 이해될 수 있는 방법이지만
// 우리는 반복을 이용해서도 트리 순회를 할 수 있다. 물론, 이 경우에는 스택이 필요하다. 스택에 자식 노드를 저장하고
// 꺼내면서 순회를 할 수 있는 것이다.
// 
// 
//


typedef struct TreeNode{
	int data;

struct TreeNode* left,* right;
}TreeNode;

int top = -1;

TreeNode* stack[SIZE];

void push(TreeNode* p) {
	if (top < SIZE - 1) {
		stack[++top] = p;
	}
}

TreeNode* pop() {
	TreeNode* p = NULL;
	if (top >= 0) {
		p = stack[top--];
	}
	return p;
}

void inorder_iter(TreeNode* root) {
	while (1) {
		for (; root; root = root->left)
			push(root);

		root = pop();

		if (!root)break;

		printf("[%d] ", root->data);
		root = root->right;


	}
}

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20, &n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;


int main(void) {
	printf("중위 순회=");
	inorder_iter(root);
	printf("\n");
	return 0;
}
//
// 
// 이진 트리의 왼쪽 노드들은 NULL노드에 도달할 때까지 스택에 추가되었다가 NULL 노드에 도달하면 스택에서 하나씩 삭제된다.
// 이 삭제된 노드를 방문한 후에 노드의 오른쪽 노드로 이동한다. 다시 이 노드의 왼쪽 노드들을 NULL 노드에 도달할 때까지 
// 스택에 추가한다.
// 
//