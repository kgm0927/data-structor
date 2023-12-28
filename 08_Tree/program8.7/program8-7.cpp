#include <stdio.h>
#include <stdlib.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;

}TreeNode;


int calc_dir_size(TreeNode* root) {
	int left_size, right_size;
	if (root == NULL)return 0;

	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);

	return (root->data + left_size + right_size);
}
int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}


int main(void) {
	TreeNode n5 = { 500,NULL,NULL };
	TreeNode n4 = { 200,NULL,NULL };
	TreeNode n3 = { 100,&n4,&n5 };
	TreeNode n2 = { 50,NULL,NULL };
	TreeNode n1 = { 0,&n2,&n3 };


	printf("디렉토리의 크기= %d\n", calc_dir_size(&n1));
	printf("높이=%d \n", get_height(&n1));
}