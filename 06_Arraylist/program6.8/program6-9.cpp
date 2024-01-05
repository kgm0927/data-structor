#include <stdio.h>
#include <stdlib.h>

//
//			6.6 ���� ����Ʈ�� ����: ���׽�
// 
// ���⼭�� ���� ����Ʈ�� �̿��Ͽ� ������ ���׽��� ǥ���غ��� �� �� ������ ǥ�� ����� ���Ͽ� ����.
// 
// A(x)=a_(m-1)x^(em-1)+ ... +a_(0)x^(e_(0))
// 
//



//
//
// ���׽��� �ܼ� ���� ����Ʈ�� ǥ�� �����ѵ� �� ���� �ϳ��� ���� ǥ���غ���. �� ���� ���(coef)�� ����(exp) �׸���, 
// ���� ���� ����Ű�� ��ũ(link) �ʵ�� �����Ǿ� �ִ�.
// 
// 
// 
// ���� �� ���׽� A(x)=3x^12+2x^8+1 �� B(x)=8x^12-3x^10+10x^6�� ������ ���� ǥ���ȴ�.
// 
// 2���� ���׽��� ���ϴ� ���� ���� C(x)=A(x)+B(x)�� ǥ���غ���. ����� ���� ���׽��� A(x)�� B(x)�� ���ϸ� �Ʒ��� ����.
// 
// (3x^12+2x^8+1)+(8x^12-3x^10+10x^6)=11x^12-3x^10+2x^8+10x^6+1
// 
// 
// ���׽��� ���Ḯ��Ʈ�� ǥ���Ǿ� �ֱ� ������ ������ ���� p�� q�� �̿��Ͽ� ���׽� A�� B�� �׵��� ���� ��ȸ�ϸ鼭 �� �׵��� ���ϸ� �ȴ�.
// 
// 
// 1) p.expon== q.expon:
//		�� ����� ���ؼ� 0�� �ƴϸ� ���ο� ���� ����� ��� ���׽� C�� �߰��Ѵ�. �׸��� p�� q�� ��� ���� ������ �̵��Ѵ�.
// 
// 
// 2) p.expon<q.expon:
//		q�� �����ϴ� ���� ���ο� ������ �����Ͽ� ��� ���׽� C�� �߰��Ѵ�. �׸��� q�� ���� ������ �̵��Ѵ�.
// 
// 3) p.expon> q.expon:
//		p�� �����ϴ� ���� ���ο� ������ �����Ͽ� ��� ���׽� C�� �߰��Ѵ�. �׸��� p�� ���� ������ �̵��Ѵ�.
// 
// 
// 
// ���� �������� p�� q �� �߿��� ��� �ϳ��� NULL�� �� ������ ��Ǯ�� �Ѵ�. p�� q �߿��� ��� �ϳ��� NULL�� �Ǹ� ���� ���� �ִ� �׵��� ���� C�� �������� �ȴ�.
// 
// 
// 
// ���α׷� 6.9�� �տ��� ������ �˰����� ������ ���̴�. ���� ������ a,b�� �� ���� �Է� ���׽��� ����Ų��. a,b�� ����Ű�� �� ó�� ��忡������ �񱳸� �����Ѵ�.
// ���� �� ���� ����� ������ ������ ����� ���Ͽ� ��� ���׽Ŀ� ���ο� ���� �����, ���� ��带 ����Ű���� ������ a��b�� ������Ų��. ���� a�� ����Ű�� ����� 
// ������ b�� ����Ű�� ����� �������� ������ a�� ���� ���� ��带 ���� ��� ���׽Ŀ� �߰���Ű�� ���� ��带 ����Ű���� a�� ������Ų��. �ݴ��� ��쵵 ����������
// �ϸ� �ȴ�. a�� b���� �ϳ��� ���� ������ �Ǹ� �����ִ� �׵��� ��� ��� ���׽����� �ű�� �ȴ�.
// 
// 
// ���⼭�� �ϳ��� ���� ����Ʈ�� �ΰ��� ������ head�� tail�� ǥ���ǰ� �ִ�. 
// 
//		head: ù ��° ���
//		tail: ������ ���
// 
// ������ ��� ���(header node)��� �ϴ� Ư���� ��尡 �ְ� �� ��� ��尡 head�� tail �����͸� ���ÿ� ������ �ִ�. �߰��� ���� ����Ʈ�� ��� �ִ� �׸���� ������ size
// ������ ������ ��찡 ����. �̷� ���, �ϳ��� ���� ����Ʈ�� �ϳ��� ��� ��忡 ���Ͽ� ǥ���ȴ�. �츮�� �̹� ��� ��带 ����ü ListType���� ����ؿԴ�. 
// 
// ���� ��� ��带 ����ϰ� �Ǹ� ���� ���� �ſ� ����. �ϳ��� ���� ��� �� ���� ��带 �߰��ϴ� ���, �ܼ� ���� ����Ʈ�� ���, �Ź� �߰��� ������ ó������ �����͸� ����
// ������ ���� �Ѵ�.
// 
// 
// �ݸ� ��� ����� ������ ����ϱ� ���ؼ��� �׻� ���� ����Ʈ�� ������ ����, �ʱ�ȭ�� �� �־�� �Ѵ�. ���⼭�� create() �Լ��� �̿��Ͽ� ��� ��带 �������� �����ϰ� �ʱ�ȭ
// �Ͽ���. ���⼭�� ���ο� ��尡 ������� ������ ��� ���׽��� ������ ��带 ã�� �۾��� ���ϱ� ���Ͽ� ������ ��带 ����Ű�� tail �����͸� ��� ��� �ȿ��� �����Ѵ�.
// insert_last() �Լ��� ���ο� ��带 ���� ���׽��� �������� �߰��ϴ� ������ �Ѵ�. �̶� ��� ��带 ����Ű�� �����Ͱ� �Լ��� �Ű� ������ ���޵Ǵ� ���� �����϶�. �̴� ����
// ���� �����͸� �����ϱ� ���� ���̴�.
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
	if (temp == NULL) error("�޸� �Ҵ� ����");
	
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;

	if (plist->tail == NULL) {
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;

		// ���߿� ���� �����Բ� ���庼 ��.// Ư�� �̺κ� �߿�
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

