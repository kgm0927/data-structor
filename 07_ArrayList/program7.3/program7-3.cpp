#include <stdio.h>
#include <stdlib.h>
//
// 7.1 원형 연결 리스트
// 
//		원형 연결 리스트의 소개
// 
// 원형 연결 리스트란 마지막 노드가 첫 번재 노드를 가리키는 리스트이다. 즉 마지막 노드의 링크 필드가 널(NULL)이 아니라
// 첫 번째 노드 주소가 되는 리스트이다. 어떤 장점이 있을까? 원형 연결 리스트에는 하나의 노드에서 다른 노드로의 접근이
// 가능하다. 하나의 노드에서 링크를 계속 따라가면 결국 모든 노드를 거쳐 자기 자신으로 되돌아 올 수 있다는 것이다.
// 
// 삭제나 삽입 시에는 항상 선행 노드를 가리키는 포인터가 필요함을 기억하라.
// 
// 
// 원형 연결 리스트가 특히 유용한 경우는 리스트의 끝에 노드를 삽입하는 연산이 단순 연결 리스트보다
// 효율적일 수 있다는 것이다. 단순 연결 리스트에서 리스트 끝에 노드를 추가하려면 첫 번째 노드에서부터
// 링크를 따라서 노드의 개수만큼 진행하여 마지막 노드까지 가야한다. 그러나 만약 원형 연결 리스트에서 다음과
// 같이 헤드 포인터가 마지막 노드를 가리키도록 구성한다면 상수 시간 안에 처음과 끝에 노드를 삽입할 수 있어야 한다.
// 
// 이 변형된 원형 연결 리스트에서 마지막 노드는 헤드 포인터인 head가 가리키고 있고, 첫 번째 노드는 head->link가 가리키고
// 있으므로, 리스트의 마지막에 노드를 삽입하거나 삭제하기 위하여 맨 끝까지 힘들게 가지 않아도 된다.
// 
// 

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;


// 
//		원형 리스트에 처음에 삽입
// 
// 
// 이 변형된 원형 연결 리스트를 이용하여 리스트의 처음에 삽입하는 함수를 작성하여 보자 . 먼저 새로운 노드의 링크인
// node->link가 첫 번째 노드를 가리키게 하고 다음에 마지막 노드의 링크가 node를 가리키게 하면 된다. 헤드 포인터인
// head가 마지막 노드를 가리키는 것만 기억하면 소스를 이해하는데 별 문제가 없을 것이다.
// 
ListNode* insert_first(ListNode* head, element data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}

	return head;
}

//
//			원형 리스트 끝에 삽입
// 
// 앞의 코드에 한 문장만 추가하면 원형 연결 리스트의 끝에 삽입할 수 있다. 즉 원형 연결 리스트는 어차피 원형으로 연결되어 있으므로 어디가 처음이고 어디가 끝인지는
// 불분명하다. 따라서 head의 위치만 새로운 노드로 바꾸어주면 새로운 노드가 마지막 노드가 된다.
// 
//
ListNode* insert_last(ListNode* head, element data) {

	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;

	if (head == NULL)
	{
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}

	return head;

}

//
// 
// 테스트 프로그램
// 
// 위의 삽입 함수들을 테스트하는 프로그램을 프로그램 7.3에 보였다. 원형 리스트가 이와 같은 장점이 있지만 마지막 노드의 링크가
// NULL이 아니기 때문에 리스트의 끝에 도달했는지를 검사하려면 헤드 포인터와 비교해야 한다. 또한 while 루프 대신에 do-while 루프
// 를 쎠야 함을 유의해야 한다.
// 
//
void print_list(ListNode* head) {

	ListNode* p;

	if (head == NULL) return;
	p = head->link;

	do
	{
		printf("%d->", p->data);
		p = p->link;

	} while (p!=head);

	printf("%d-> ", p->data);
}




int main(void) {
	ListNode* head = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10);
	print_list(head);

	return 0;
}