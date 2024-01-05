#include <stdio.h>
#include <stdlib.h>

//
//				7.3 이중 연결 리스트
// 
// 
// 단순 연결 리스트에서 어떤 노드에서 후속 노드를 찾기는 쉽지 않지만, 선행 노드를 찾으려면 구조상
// 아주 어렵다. 원형 연결 리스트라고 하더라도 거의 전체 노드를 거쳐서 돌아와야 한다. 따라서 응용
// 프로그램에서 특정 노드에서 양방향으로 자유롭게 움직일 필요가 있다면 단순 연결 리스트 구조는 부적합하다.
// 이중 연결 리스트는 이러한 문제점을 해결하기 위하여 만들어진 자료구조이다.
// 
// 
// '이중 연결 리스트'는 하나의 노드가 선행 노드와 후속 노드에 대한 두 가지 링크를 가지는 리스트이다. 링크가
// 양방향이므로 양방향으로 검색이 가능해진다. 단점은 공간을 너무 많이 차지하고 코드가 복잡해진다는 것이다.
// 
// 
// 실제 응용에서는 이중 연결 리스트와 원형 연결 리스트를 혼합한 형태가 많이 사용된다. 또 헤드 노드(head node)라는 특별한
// 노드를 추가하는 경우가 많다. 헤드 포인터와는 구별하여야 한다. 헤드 포인터는 리스트의 첫 번째 노드를 가리키는 포인터이고,
// 헤드 노드는 데이터를 가지고 있지 않은 특별한 노드를 추가하는 것이다. 헤드 노드가 존재하게 되면 삽입, 삭제 알고리즘이
// 간편해진다. 
// 
// 헤드 노드의 데이터는 아무 정보도 담고 있지 않다. 다만 삽입과 삭제 알고리즘을 간편하게 하기 위해 존재한다.
// 
// 
//






//
// 노드의 구조를 구조체를 이용하여 정의해보면 다음과 같다. 노드의 왼쪽 링크 필드 llink는 바로 선행노드를 가리키며, 오른쪽 링크
// rlink는 후속 노드를 가리킨다.
// 
//
typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;

}DListNode;

void init(DListNode* phead) {
	phead->llink = phead;
	phead->rlink = phead;
}

void print_dlist(DListNode* phead) {
	DListNode* p;
	for (p = phead->rlink; p != phead; p = p->rlink) {
	
	
		printf("<-| |%d| |->", p->data);
	
	}
	printf("\n");
}

//
//			삽입 연산
// 
// 먼저 삽입 연산에 대하여 살펴보자. 순서대로 링크 필드의 값을 바꾸면 된다. 새로 만들어진
// 노드의 링크를 먼저 바꾸는 것을 알 수 있다. 새로 만들어진 노드의 링크는 아무런 정보도 
// 가지고 있지 않기 때문에 변경하여도 안전하다.
// 
//
//



void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;

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

//			 완전한 프로그램
// 
// 
// 아래의 프로그램 main함수는 이중 연결 리스트를 사용한 간단한 프로그램이다. 이중 연결 리스트의 내용을
// 출력할 수 있는 print_dlist 함수가 있으며 이중 연결 리스트를 초기화하는 함수인 init()이 추가되어 있다.
// 
// 한 가지 주의해야 할 것은 이중 연결 리스트에서는 보통 헤드 노드가 존재하므로 단순 연결 리스트처럼 헤드
// 포인터가 필요없다. 즉 헤드 노드만 알고 있으면 어떤 노드로도 접근할 수 있다. 헤드 노드는 main 함수 안에
// 변수로 head라는 이름으로 생성되어 있다. head는 포인터 변수가 아니고 구조체 변수임을 유의해야 한다.
// 이중 연결 리스트는 사용하기 전에 반드시 초기화를 해야 한다는 점을 유의해야 한다.
//



int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("추가 단계");

	for (int i = 0; i < 5; i++) {
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n 삭제단계\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}