#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// 
//			7.2 원형 연결 리스트는 어디에 사용될까?
// 
// 첫 번째로 컴퓨터에서 여러 응용 프로그램을 하나의 CPU를 이용하여 실행할 때에 필요하다. 현재
// 실행중인 모든 응용 프로그램은 원형 연결 리스트에 보관되며 운영체제는 원형 연결 리스트에 있는
// 프로그램의 실행을 위해 고정된 시간 슬롯을 제공한다. 운영 체제는 모든 응용 프로그램이 완료될
// 때까지 원형 연결 리스트를 계속 순회한다.
// 
// 
// 두 번째 예는 멀티 플레이어 게임이다. 모든 플레이어는 원형 연결 리스트에 저장되면 한 플레이어의
// 기회가 끝나면 포인터를 앞으로 움직여서 다음 플레이어의 순서가 된다.
// 
// 
// 세 번재로 원형 연결 리스트는 원형 큐를 만드는데도 사용할 수 있다. 우리는 4장에서 배열을 사용하여
// 원형 큐를 구현하였지만 원형 연결 리스트를 이용하여 원형 큐를 구현할 수 있다는 것은 너무 명백하다.
// 원형 큐에서는 두 개의 포인터, front와 rear가 있다.
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
		printf("현재 사례=%s \n", p->data);
		p = p->link;
	}

	return 0;
}