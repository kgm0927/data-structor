#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

//
//			7.5 ���� ����Ʈ�� ������ ����
// 
// 
// ������ ���� ����Ʈ�� ���� �� ������? 3�忡�� �迭�� �̿��Ͽ� �����ϴ� ����� �Ұ��Ǿ���.
// �׷��� ������ ���Ḯ��Ʈ�� �̿��ؼ��� ������ �� �ִ�.
// 
// �̷��� �����̳� ť�� ����� ����(linked stack)�̶�� �Ѵ�. �ܺο��� ���⿡�� �迭�� �̿��� �����̳�
// ���� ����Ʈ�� �̿��� �����̳� ���� ���̰� ����. �� �����Ǵ� �ܺ� �������̽��� ������ �����ϴ�. �޶�����
// ���� �ܺ� �����̴�. ���� ����Ʈ�� �̿��Ͽ� ������ ����� �Ǹ� ������ ũ��. �� ũ�Ⱑ ���ѵ��� �ʴ´ٴ�
// ���̴�. ���� �޸� �Ҵ縸 �� �� �� �ִٸ� ���ÿ� ���ο� ��Ҹ� ������ �� �ִ�. �ݸ鿡 ���� ����Ʈ�� 
// �̿��� ������ ���� �޸� �Ҵ��̳� ������ �ؾ� �ϹǷ� �����̳� ���� �ð��� �� �� �ɸ� �� �ִ�.
// 
// 
// 
// ����� ������ �⺻������ ���� ����Ʈ�̱� ������ ������ ���� ��带 �����Ѵ�. ���� �츮�� �����ϰ� ����
// ������ �ʵ�� ���� ��带 ����Ű�� ���� �����Ͱ� ��� �ִ� ��ũ �ʵ�� �����ȴ�. ���� top�� �� �̻�
// ������ �ƴϰ� ��带 ����Ű�� �����ͷ� ����ȴ�. ���� ����� ���ÿ� ���õ� �����ʹ� top �����ͻ�������
// �ϰ����� ���Ͽ� LinkedStackType�̶�� ����ü Ÿ������ ���ǵǾ���. ��� �Լ����� �� ����ü�� �����͸�
// �Ű� ������ �޾Ƽ� ����Ѵ�.
// 
// 
// ����� ���ÿ����� ��� �����Ͱ� top�̶�� �̸����� �Ҹ��� �� �ܿ��� �� �������� ����. ���� ���꿡��
// ���� ���� �޸� �Ҵ����� ��带 ����� ù ��° ���� �����Ѵ�.
// 
// ���� ���꿡�� top�� ���� top->link�� �ٲٰ� ������ top�� ����Ű�� ��带 ���� �޸� �����ϸ� �ȴ�.
// 
// ����� ���ÿ��� ������´� ���� ����Ʈ�� ���������� top �����Ͱ� NULL�� ����̴�.
// 
//

typedef int element;

typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;


typedef struct {
	StackNode* top;
}LinkedStackType;


void init(LinkedStackType* s) {
	s->top = NULL;
}


int is_empty(LinkedStackType* s) {
	return(s->top == NULL);
}


int is_full(LinkedStackType* s) {
	return 0;
}


void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}


void print_stack(LinkedStackType* s) {
	for (StackNode *p = s->top; p !=NULL; p=p->link)
	{
		printf("%d->", p->data);
	}
	printf("NULL \n");
}


element pop(LinkedStackType* s) {
	if (is_empty(s))
	{
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}


element peek(LinkedStackType* s) {
	if (is_empty(s))
	{
		fprintf(stderr, "������ �������\n"); exit(1);
	}
	else {
		return s->top->data;
	}
}


int main(void) {
	LinkedStackType s;
	
	init(&s);
	push(&s, 1); print_stack(&s);
	push(&s, 2); print_stack(&s);
	push(&s, 3); print_stack(&s);

	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);
	pop(&s); print_stack(&s);

	return 0;
}