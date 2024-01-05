#include <stdio.h>
#include <stdlib.h>

//
//				7.3 ���� ���� ����Ʈ
// 
// 
// �ܼ� ���� ����Ʈ���� � ��忡�� �ļ� ��带 ã��� ���� ������, ���� ��带 ã������ ������
// ���� ��ƴ�. ���� ���� ����Ʈ��� �ϴ��� ���� ��ü ��带 ���ļ� ���ƿ;� �Ѵ�. ���� ����
// ���α׷����� Ư�� ��忡�� ��������� �����Ӱ� ������ �ʿ䰡 �ִٸ� �ܼ� ���� ����Ʈ ������ �������ϴ�.
// ���� ���� ����Ʈ�� �̷��� �������� �ذ��ϱ� ���Ͽ� ������� �ڷᱸ���̴�.
// 
// 
// '���� ���� ����Ʈ'�� �ϳ��� ��尡 ���� ���� �ļ� ��忡 ���� �� ���� ��ũ�� ������ ����Ʈ�̴�. ��ũ��
// ������̹Ƿ� ��������� �˻��� ����������. ������ ������ �ʹ� ���� �����ϰ� �ڵ尡 ���������ٴ� ���̴�.
// 
// 
// ���� ���뿡���� ���� ���� ����Ʈ�� ���� ���� ����Ʈ�� ȥ���� ���°� ���� ���ȴ�. �� ��� ���(head node)��� Ư����
// ��带 �߰��ϴ� ��찡 ����. ��� �����Ϳʹ� �����Ͽ��� �Ѵ�. ��� �����ʹ� ����Ʈ�� ù ��° ��带 ����Ű�� �������̰�,
// ��� ���� �����͸� ������ ���� ���� Ư���� ��带 �߰��ϴ� ���̴�. ��� ��尡 �����ϰ� �Ǹ� ����, ���� �˰�����
// ����������. 
// 
// ��� ����� �����ʹ� �ƹ� ������ ��� ���� �ʴ�. �ٸ� ���԰� ���� �˰����� �����ϰ� �ϱ� ���� �����Ѵ�.
// 
// 
//






//
// ����� ������ ����ü�� �̿��Ͽ� �����غ��� ������ ����. ����� ���� ��ũ �ʵ� llink�� �ٷ� �����带 ����Ű��, ������ ��ũ
// rlink�� �ļ� ��带 ����Ų��.
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
//			���� ����
// 
// ���� ���� ���꿡 ���Ͽ� ���캸��. ������� ��ũ �ʵ��� ���� �ٲٸ� �ȴ�. ���� �������
// ����� ��ũ�� ���� �ٲٴ� ���� �� �� �ִ�. ���� ������� ����� ��ũ�� �ƹ��� ������ 
// ������ ���� �ʱ� ������ �����Ͽ��� �����ϴ�.
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

//			 ������ ���α׷�
// 
// 
// �Ʒ��� ���α׷� main�Լ��� ���� ���� ����Ʈ�� ����� ������ ���α׷��̴�. ���� ���� ����Ʈ�� ������
// ����� �� �ִ� print_dlist �Լ��� ������ ���� ���� ����Ʈ�� �ʱ�ȭ�ϴ� �Լ��� init()�� �߰��Ǿ� �ִ�.
// 
// �� ���� �����ؾ� �� ���� ���� ���� ����Ʈ������ ���� ��� ��尡 �����ϹǷ� �ܼ� ���� ����Ʈó�� ���
// �����Ͱ� �ʿ����. �� ��� ��常 �˰� ������ � ���ε� ������ �� �ִ�. ��� ���� main �Լ� �ȿ�
// ������ head��� �̸����� �����Ǿ� �ִ�. head�� ������ ������ �ƴϰ� ����ü �������� �����ؾ� �Ѵ�.
// ���� ���� ����Ʈ�� ����ϱ� ���� �ݵ�� �ʱ�ȭ�� �ؾ� �Ѵٴ� ���� �����ؾ� �Ѵ�.
//



int main(void) {
	DListNode* head = (DListNode*)malloc(sizeof(DListNode));
	init(head);
	printf("�߰� �ܰ�");

	for (int i = 0; i < 5; i++) {
		dinsert(head, i);
		print_dlist(head);
	}

	printf("\n �����ܰ�\n");
	for (int i = 0; i < 5; i++) {
		print_dlist(head);
		ddelete(head, head->rlink);
	}
	free(head);
	return 0;
}