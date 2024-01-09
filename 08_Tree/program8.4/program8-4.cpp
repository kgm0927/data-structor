#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define  SIZE 100

//				8.5 �ݺ��� ��ȸ
// 
// 
// �տ����� ��ȸ�� ��ȯ ȣ���� �̿��Ͽ� �����Ͽ���. ���� �̰��� ǥ������ ����̰� ���� ���ص� �� �ִ� ���������
// �츮�� �ݺ��� �̿��ؼ��� Ʈ�� ��ȸ�� �� �� �ִ�. ����, �� ��쿡�� ������ �ʿ��ϴ�. ���ÿ� �ڽ� ��带 �����ϰ�
// �����鼭 ��ȸ�� �� �� �ִ� ���̴�.
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
	printf("���� ��ȸ=");
	inorder_iter(root);
	printf("\n");
	return 0;
}
//
// 
// ���� Ʈ���� ���� ������ NULL��忡 ������ ������ ���ÿ� �߰��Ǿ��ٰ� NULL ��忡 �����ϸ� ���ÿ��� �ϳ��� �����ȴ�.
// �� ������ ��带 �湮�� �Ŀ� ����� ������ ���� �̵��Ѵ�. �ٽ� �� ����� ���� ������ NULL ��忡 ������ ������ 
// ���ÿ� �߰��Ѵ�.
// 
//