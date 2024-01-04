#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_QUEUE_SIZE 5

typedef struct {
	int id;
	int arrival_time;
	int service_time;
}element;



typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}


void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}


int is_empty(QueueType* q) {

	return(q->front == q->rear);
}


int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}


void queue_print(QueueType* q) {

	printf("QUEUE(front=%d rear=%d)=", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;

		do
		{
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);

	}
	printf("\n");
}


void enqueue(QueueType* q, element item) {
	if (is_full(q))
	{
		error("ť�� ��ȭ�����Դϴ�.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}

element dequeue(QueueType* q) {
	if (is_empty(q))
	{
		error("ť�� ��������Դϴ�.");

	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


//
//			5.6 ť�� ����: �ùķ��̼�
// 
// 
// ť�� �ַ� 'ť�� �̷�'�� ���� �ý����� Ư���� �ùķ��̼��Ͽ� �м��ϴµ� �̿�ȴ�. ť�׸���� ���� ���� ���񽺸� �����ϴ� ������ ���񽺸� �޴�
// ����� �̷������. ���ѵ� ���� ���� ������ ������ ���񽺸� �ޱ� ���� ��� ��Ŀ��� ��ٸ��� �ȴ�.
// 
// ���⼭�� ���࿡�� ���� ���ͼ� ���񽺸� �ް� ������ ������ �ùķ��̼��� ����. �츮���� �ʿ��� ���� ������ ��ٸ��� ��սð��� �󸶳� �Ǵ����̴�.
// ���� ��ٸ��� �ð��� �ʹ� ��ٸ� ����� �� �����Ͽ� ���ð��� �ٿ��� �� ���̴�.
// 
// 
// ���⼭�� �ִ��� �����ϰ� �����Ͽ� �ùķ��̼��� �ٽ����� ���븸 �˾ƺ���. ���� �����ϴ� ����� �ѻ���̶�� ��������. ���� �������� ť�� �ùķ��̼�
// �ȴ�. �־��� �ð����� ���� ������ �������� ť�� ���´�. ������ ���� �ð��� �Ѱ谪 �ȿ��� �����ϰ� �����ȴ�. ť�� ����ִ� ������ ������� ���񽺸�
// �޴´�. �� ���� ���񽺰� ������ ť�� �� �տ� �ִ� �ٸ� ���� ���񽺸� �ޱ� �����Ѵ�. ������ �ð������� �ùķ��̼��� ������ ������ ��մ��ð��� ����Ͽ� ����Ѵ�.
// 
// 
// 
// 
// �ùķ��̼��� �ϳ��� �ݺ� ������ �̷������.
// 
// (1) ���� ����ð��� ��Ÿ���� clock�̶�� ������ �ϳ� �����Ѵ�.
// 
// (2) [0,10] ���̿� ������ �����Ͽ� 3���� ������ ���ο� ���� ���Դٰ� �Ǵ��Ѵ�. ���ο� ���� ������ ����ü��
// �����ϰ� ���⿡ ���� ���̵�, �����ð�, ���� �ð� ���� ������ �����Ѵ�. ���⼭ ���� �ʿ�� �ϴ� ���� �ð���
// ���� ������ �����Ѵ�. �� ����ü�� enqueue()�� ȣ���Ͽ��� ť�� �߰��Ѵ�. ���� ������ service_time�� ���� ó�� ����
// ���� ���� �ð��� �����صд�.
// 
// (3) service_time�� 0�� �ƴ����� ���캻��. ���� service_time�� 0�� �ƴϸ� � ���� ���� ���񽺸� �ް� �ִ� ������
// �ǹ��Ѵ�. clock�� �ϳ� service_time�� �ϳ� ���ҽ�Ų��. ���� service_time�� 0�̸� ���� ���� �޴� ���� ���ٴ� ����
// �ǹ��Ѵ�. ���� ť���� �� ����ü�� �ϳ� ������ ���񽺸� �����Ѵ�. �� ���񽺸� �����Ѵٴ� �ǹ̴� �������� service_time��
// ���� ���� �ð��� �����Ѵٴ� ���̴�. ���� ������ ó���� �ùķ��̼��ϸ� �ڵ带 �߰��ؾ� �Ѵ�.
// 
// (4) 60���� �ð��� ������ ������ ��ٸ� �ð��� ���� ���Ͽ� ȭ�鿡 ����Ѵ�. 
// 
//

int main() {

	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueType queue;
	init_queue(&queue);

	srand(time(NULL));

	for (int clock = 0; clock < minutes; clock++)
	{
		printf("����ð�%d\n", clock);
		if ((rand()%10)<3)
		{
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);

			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð�= %d��\n",customer.id,customer.arrival_time,customer.service_time);

		}
		if (service_time>0)
		{
			printf("�� %d ����ó�����Դϴ�. \n", service_customer);
			service_time--;
		}
		else
		{
			if (!is_empty(&queue))
			{
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;


				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�. \n", customer.id, clock, clock - customer.arrival_time);

				total_wait += clock - customer.arrival_time;


			}
		}
	}

	printf("��ü ��� �ð�=%d�� \n", total_wait);

	return 0;

}