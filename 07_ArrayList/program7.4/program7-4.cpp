#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
		printf("ÇöÀç »ç·Ê=%s \n", p->data);
		p = p->link;
	}

	return 0;
}