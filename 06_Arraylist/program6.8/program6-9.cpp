#include <stdio.h>
#include <stdlib.h>

//
//			6.6 연결 리스트의 응용: 다항식
// 
// 여기서는 연결 리스트를 이용하여 동일한 다항식을 표현해보고 이 두 가지의 표현 방식을 비교하여 보자.
// 
// A(x)=a_(m-1)x^(em-1)+ ... +a_(0)x^(e_(0))
// 
//



//
//
// 다항식을 단순 연결 리스트로 표현 가능한데 각 항을 하나의 노드로 표현해보자. 각 노드는 계수(coef)와 지수(exp) 그리고, 
// 다음 항을 가리키는 링크(link) 필드로 구성되어 있다.
// 
// 
// 
// 예를 들어서 다항식 A(x)=3x^12+2x^8+1 과 B(x)=8x^12-3x^10+10x^6은 다음과 같이 표현된다.
// 
// 2개의 다항식을 더하는 덧셈 연산 C(x)=A(x)+B(x)을 표현해보자. 참고로 앞의 다항식을 A(x)와 B(x)을 더하면 아래와 같다.
// 
// (3x^12+2x^8+1)+(8x^12-3x^10+10x^6)=11x^12-3x^10+2x^8+10x^6+1
// 
// 
// 다항식이 연결리스트로 표현되어 있기 때문에 포인터 변수 p와 q를 이용하여 다항식 A와 B의 항들을 따라 순회하면서 각 항들을 더하면 된다.
// 
// 
// 1) p.expon== q.expon:
//		두 계수를 더해서 0이 아니면 새로운 항을 만들어 결과 다항식 C에 추가한다. 그리고 p와 q는 모두 다음 항으로 이동한다.
// 
// 
// 2) p.expon<q.expon:
//		q가 지시하는 항을 새로운 항으로 복사하여 결과 다항식 C에 추가한다. 그리고 q만 다음 항으로 이동한다.
// 
// 3) p.expon> q.expon:
//		p가 지시하는 항을 새로운 항으로 복사하여 결과 다항식 C에 추가한다. 그리고 p만 다음 항으로 이동한다.
// 
// 
// 
// 위의 과정들을 p나 q 둘 중에서 어느 하나가 NULL이 될 때까지 되풀이 한다. p나 q 중에서 어느 하나가 NULL이 되면 아직 남아 있는 항들을 전부 C로 가져오면 된다.
// 
// 
// 
// 프로그램 6.9는 앞에서 설명한 알고리즘을 구현한 것이다. 먼저 포인터 a,b는 두 개의 입력 다항식을 가리킨다. a,b가 가리키는 맨 처음 노드에서부터 비교를 시작한다.
// 만일 두 개의 노드의 지수가 같으면 계수를 합하여 결과 다항식에 새로운 항을 만들고, 다음 노드를 가리키도록 포인터 a와b를 전진시킨다. 만약 a가 가리키는 노드의 
// 지수가 b가 가리키는 노드의 지수보다 높으면 a의 노드와 같은 노드를 만들어서 결과 다항식에 추가시키고 다음 노드를 가리키도록 a를 전진시킨다. 반대의 경우도 마찬가지로
// 하면 된다. a나 b중의 하나가 먼저 끝나게 되면 남아있는 항들을 모두 결과 다항식으로 옮기면 된다.
// 
// 
// 여기서는 하나의 연결 리스트가 두개의 포인터 head와 tail로 표현되고 있다. 
// 
//		head: 첫 번째 노드
//		tail: 마지막 노드
// 
// 보통은 헤더 노드(header node)라고 하는 특수한 노드가 있고 이 헤더 노드가 head와 tail 포인터를 동시에 가지고 있다. 추가로 연결 리스트에 들어 있는 항목들의 개수인 size
// 변수도 가지는 경우가 많다. 이런 경우, 하나의 연결 리스트는 하나의 헤더 노드에 의하여 표현된다. 우리는 이미 헤더 노드를 구조체 ListType으로 사용해왔다. 
// 
// 실제 헤더 노드를 사용하게 되면 편리한 점이 매우 많다. 하나의 예를 들면 맨 끝에 노드를 추가하는 경우, 단순 연결 리스트의 경우, 매번 추가할 때마다 처음부터 포인터를 따라서
// 끝까지 가야 한다.
// 
// 
// 반면 헤더 노드의 개념을 사용하기 위해서는 항상 연결 리스트를 생성한 다음, 초기화를 해 주어야 한다. 여기서는 create() 함수를 이용하여 헤더 노드를 동적으로 생성하고 초기화
// 하였다. 여기서도 새로운 노드가 만들어질 때마다 결과 다항식의 마지막 노드를 찾는 작업을 피하기 위하여 마지막 노드를 가리키는 tail 포인터를 헤더 노드 안에서 유지한다.
// insert_last() 함수는 새로운 노드를 만들어서 다항식의 마지막에 추가하는 역할을 한다. 이때 헤더 노드를 가리키는 포인터가 함수의 매개 변수로 전달되는 것을 유의하라. 이는 헤드와
// 테일 포인터를 변경하기 위한 것이다.
// 
//
typedef struct ListNode {
	int coef;
	int expon;
	struct  ListNode* link;
}ListNode;

typedef struct ListType {
	int size;
	ListNode* head;
	ListNode* tail;
}ListType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListType* create() {
	ListType* plist = (ListType*)malloc(sizeof(ListType));
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_last(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	if (temp == NULL) error("메모리 할당 에러");
	
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;

		// 나중에 김평 교수님께 여쭤볼 것.// 특히 이부분 중요
	}
	plist->size++;

}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;

	int sum;

	while (a && b) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			if (sum != 0) insert_last(plist3, sum, a->expon);
			a = a->link, b = b->link;
		}
		else if (a->expon>b->expon)
		{
			insert_last(plist3, a->coef, a->expon);
			a = a->link;

		}
		else {
			insert_last(plist3, b->coef, b->expon);
			b = b->link;
		}
	}

	for ( ;  a!=NULL;a=a->link)
	{
		insert_last(plist3, a->coef, a->expon);
	}
	for (; b != NULL; b = b->link) {
		insert_last(plist3, b->coef, b->expon);
	}


}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;
	printf("polynomial = ");
	for (; p; p = p->link) {
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");

}

int main(void) {
	ListType* list1, * list2, * list3;
	list1 = create();
	list2 = create();
	list3 = create();

	insert_last(list1, 3, 12);
	insert_last(list1, 2, 8);
	insert_last(list1, 1, 0);

	insert_last(list2, 8, 12);
	insert_last(list2, -3, 10);
	insert_last(list2, 10, 6);


	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1), free(list2), free(list3);

}

