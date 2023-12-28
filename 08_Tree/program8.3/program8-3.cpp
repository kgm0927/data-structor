#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;





TreeNode n7 = { 22,NULL,NULL };
TreeNode n6 = { 95,NULL,NULL };
TreeNode n4 = { 5 ,NULL,NULL };
TreeNode n2 = { 15 ,&n4,NULL };
TreeNode n5 = { 35,&n7,NULL };
TreeNode n3 = { 93,&n5,&n6 };
TreeNode n1 = { 17, &n2,&n3 };

TreeNode* root = &n1;


// 중위 순회
void inorder(TreeNode* root) {
	if (root != NULL)
	{
		inorder(root->left);		// 왼쪽서브트리 순회
		printf("[%d] ", root->data);// 노드 방문
		inorder(root->right);		// 오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->data);

	}
}

int main(void) {
	printf("중위 순회=");
	inorder(root); printf("\n");


	printf("전위 순회=");
	preorder(root); printf("\n");


	printf("후위 순위=");
	postorder(root); printf("\n");

	return 0;
}