#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
//			7.4 예제: mp3 재생 프로그램 만들기
// 
// mp3 재생기를 보면 현재 곡에서 이전 곡으로 가기도 하고 다음 곡으로 가기도 한다. 또 처음 곡이나 마지막 곡으로
// 가기도 한다. 따라서 현재 항목에서 이전 항목이나 다음 항목으로 쉽게 이동할 수 있는 자료 구조를 사용하여야 한다.
// 우리는 이중 연결 리스트를 이용하여서 음악을 저장하고 사용자의 명령에 맞춰서 곡을 선택해는 프로그램을 작성해보자.
// 
// 
//
typedef char element[100];
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

DListNode* current;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
		if (p==current)
		{
			printf("<-| #%s# |->", p->data);
		}
		else
		{
			printf("<-| %s |->", p->data);
		}
	}
	printf("\n");
}

void dinsert(DListNode* before, const element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	strcpy(newnode->data, data);
	newnode->llink = before;
	newnode->rlink = before->rlink;
	before->rlink->llink = newnode;
	before->rlink = newnode;
}


void ddelete(DListNode* head, DListNode* removed) {
	if (removed == head)return;

	removed->llink->rlink = removed->rlink;
	removed->rlink->llink = removed->llink;
	free(removed);
}

int main(void) {
	char ch;
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);

	dinsert(head, "Mamamia");
	dinsert(head, "Dancing Queen");
	dinsert(head, "Fernando");

	current = head->rlink;
	print_dlist(head);

	do {
		printf("\n 명령어를 입력하세요.(<,>,q):");
		ch = getchar();
		getchar();
		if (ch == '<') {
			current = current->llink;
			if (current == head)
				current = current->llink;
			
		}
		else if (ch=='>')
		{
			current = current->rlink;
			if (current==head)
			{
				current = current->rlink;
			}

		}
		
		print_dlist(head);
		

	} while (ch != 'q');
	free(head);
}