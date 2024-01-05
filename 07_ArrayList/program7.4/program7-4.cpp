#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// 
//			7.2 ���� ���� ����Ʈ�� ��� ���ɱ�?
// 
// ù ��°�� ��ǻ�Ϳ��� ���� ���� ���α׷��� �ϳ��� CPU�� �̿��Ͽ� ������ ���� �ʿ��ϴ�. ����
// �������� ��� ���� ���α׷��� ���� ���� ����Ʈ�� �����Ǹ� �ü���� ���� ���� ����Ʈ�� �ִ�
// ���α׷��� ������ ���� ������ �ð� ������ �����Ѵ�. � ü���� ��� ���� ���α׷��� �Ϸ��
// ������ ���� ���� ����Ʈ�� ��� ��ȸ�Ѵ�.
// 
// 
// �� ��° ���� ��Ƽ �÷��̾� �����̴�. ��� �÷��̾�� ���� ���� ����Ʈ�� ����Ǹ� �� �÷��̾���
// ��ȸ�� ������ �����͸� ������ �������� ���� �÷��̾��� ������ �ȴ�.
// 
// 
// �� ����� ���� ���� ����Ʈ�� ���� ť�� ����µ��� ����� �� �ִ�. �츮�� 4�忡�� �迭�� ����Ͽ�
// ���� ť�� �����Ͽ����� ���� ���� ����Ʈ�� �̿��Ͽ� ���� ť�� ������ �� �ִٴ� ���� �ʹ� ����ϴ�.
// ���� ť������ �� ���� ������, front�� rear�� �ִ�.
// 
// 
//




typedef char element[100];
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, const element  data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	strcpy(node->data, data);

	if (head==NULL)
	{
		head = node;
		node->link = head;

	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head;
}

int main(void) {
	ListNode* head = NULL;

	head = insert_first(head, "Kim");
	head = insert_first(head, "Park");
	head = insert_first(head, "Choi");


	ListNode* p = head;

	for (int i = 0; i < 10;i++) {
		printf("���� ���=%s \n", p->data);
		p = p->link;
	}

	return 0;
}