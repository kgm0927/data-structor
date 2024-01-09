#include <stdio.h>
#define  TRUE 1
#define FALSE 0

//
//			8.10 ������ ����Ʈ��
// 
// ���� Ʈ�� ��ȭ�� ��ȯ ȣ���� ����Ѵ�. ������ �̷��� �Ǹ� ������ �������� Ʈ���� ���̰� Ŀ���� �Ǹ�
// ����� ��ȿ������ ���� �ִ�. ���� ��ȸ�� ��ȯ ȣ�� ����, �� ������ ���� ���� �� �� ������?
// 
// �츮�� ���� Ʈ���� ��忡 ���� NULL ��ũ���� �������� �˰� �ִ�. ���� Ʈ���� ����� ������ n����� �ϸ�
// �� ���� 2���� ��ũ�� �����Ƿ� �� ��ũ�� ������ 2n���� �ǰ� �̵� ��ũ �߿��� n-1���� ��ũ���� ��Ʈ��带
// ������ n-1���� �ٸ� ������ ����Ų��. ���� 2n�� �߿��� n-1�� NULL ��ũ�� �ƴ����� ������ n+1���� 
// ��ũ�� NULL���� �� �� �ִ�.
// 
// �̵� NULL ��ũ�� ���� ��ȸ �ÿ� ���� ����� ���� ������(inorder predecessor)�� ���� ��ȸ�ÿ� �ļ� �����
// ���� �ļ���(inorder successer)�� ������� ���� Ʈ���� '������ ���� Ʈ��'(threaded binary tree)�̴�. ������(thread),
// �� ���� �̿��Ͽ� ������ ��ȸ ������� ������� ���� Ʈ���̴�.
// 
// 
// �׷��� ���� �̷� ������ NULL ��ũ�� �����尡 ����Ǹ� ��ũ�� �ڽ��� ����Ű�� �����Ͱ� ����Ǿ� �ִ��� �ƴϸ�
// NULL�� ����Ǿ�� �ϴµ� ��� �����尡 ����Ǿ� �ִ����� �������ִ� �±� �ʵ尡 �ʿ��ϴ�.
//
typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
	int is_thread;
}TreeNode;
//
// ���� is_thread�� TRUE �̸� right�� ���� �ļ����̰� is_thread�� FALSE�̸� ������ �ڽ��� ����Ű�� �����Ͱ� �ȴ�. ����
// ������ ���� Ʈ���� �����Ǿ��ٰ� �����Ͽ��� ���, ���� ��ȸ ������ ��� ����Ǿ�� �ϴ°�? ���� ��� p�� ���� �ļ��ڸ�
// ��ȯ�ϴ� �Լ� find_successor�� ����, p�� is_thread�� TRUE�� �Ǿ� ������ �ٷ� ������ �ڽ��� ���� �ļ��ڰ� �ǹǷ� ������
// �ڽ��� ��ȯ�Ѵ�.
// 
// ���� is_thread�� TRUE�� �ƴ� ��쿡�� ���� Ʈ���� ���� ���� ���� �����Ѵ�. ���� ���� �ڽ��� NULL�� �� ������ ����
// ��ũ�� Ÿ�� �̵��Ѵ�.
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
// ��ȸ�� ���� �����ʺ��� �����ϱ� ������ ���� ���� �ڽ��� NULL�� �� ������ ���� ��ũ�� Ÿ�� �̵��Ѵ�.
// �������� �����͸� ����ϰ� ���� �ļ��ڸ� ã�� �Լ��� ȣ���Ͽ� �ļ��ڰ� NULL�� �ƴϸ� ��� ������ �ݺ��Ѵ�.
// 
//

void thread_inorder(TreeNode* t) {
	TreeNode* q;
	q = t;

	while (q->left) q = q->left; // �켱 ���� �������� ����.
	

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