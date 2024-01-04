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
		error("큐가 포화상태입니다.");
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

}

element dequeue(QueueType* q) {
	if (is_empty(q))
	{
		error("큐가 공백상태입니다.");

	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element peek(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}


//
//			5.6 큐의 응용: 시뮬레이션
// 
// 
// 큐는 주로 '큐잉 이론'에 따라 시스템의 특성을 시뮬레이션하여 분석하는데 이용된다. 큐잉모딜은 고객에 대한 서비스를 수행하는 서버와 서비스를 받는
// 고객들로 이루어진다. 제한된 수의 서버 때문에 고객들은 서비스를 받기 위해 대기 행렬에서 기다리게 된다.
// 
// 여기서는 은행에서 고객이 들어와서 서비스를 받고 나가는 과정을 시뮬레이션해 보자. 우리에게 필요한 것은 고객들이 기다리는 평균시간이 얼마나 되느냐이다.
// 만약 기다리는 시간이 너무 길다면 행원을 더 투입하여 대기시간을 줄여야 할 것이다.
// 
// 
// 여기서는 최대한 간단하게 설정하여 시뮬레이션의 핵심적인 내용만 알아보자. 먼저 서비스하는 행원은 한사람이라고 가정하자. 고객의 대기행렬은 큐로 시뮬레이션
// 된다. 주어진 시간동안 고객은 랜던한 간격으로 큐에 들어온다. 고객들의 서비스 시간도 한계값 안에서 랜덤하게 결정된다. 큐에 들어있는 고객들은 순서대로 서비스를
// 받는다. 한 고객의 서비스가 끝나면 큐의 맨 앞에 있는 다른 고객이 서비스를 받기 시작한다. 정해진 시간동안의 시뮬레이션이 끝나면 고객들의 평균대기시간을 계산하여 출력한다.
// 
// 
// 
// 
// 시뮬레이션은 하나의 반복 루프로 이루어진다.
// 
// (1) 먼저 현재시각을 나타내는 clock이라는 변수를 하나 증가한다.
// 
// (2) [0,10] 사이에 난수를 생성하여 3보다 작으면 새로운 고객이 들어왔다고 판단한다. 새로운 고객이 들어오면 구조체를
// 생성하고 여기에 고객의 아이디, 도착시간, 서비스 시간 등의 정보를 복사한다. 여기서 고객이 필요로 하는 서비스 시간도
// 역시 난수로 생성한다. 이 구조체를 enqueue()를 호출하여서 큐에 추가한다. 전역 변수인 service_time에 현재 처리 중인
// 고객의 서비스 시간을 저장해둔다.
// 
// (3) service_time이 0이 아닌지를 살펴본다. 만약 service_time이 0이 아니면 어떤 고객이 지금 서비스를 받고 있는 중임을
// 의미한다. clock이 하나 service_time을 하나 감소시킨다. 만약 service_time이 0이면 현재 서비스 받는 고객이 없다는 것을
// 의미한다. 따라서 큐에서 고객 구조체를 하나 꺼내어 서비스를 저장한다. 즉 서비스를 시작한다는 의미는 전역변수 service_time에
// 고객의 서비스 시간을 저장한다는 것이다. 보다 복잡한 처리를 시뮬레이션하면 코드를 추가해야 한다.
// 
// (4) 60분의 시간이 지나면 고객들이 기다린 시간을 전부 합하여 화면에 출력한다. 
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
		printf("현재시각%d\n", clock);
		if ((rand()%10)<3)
		{
			element customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueue(&queue, customer);

			printf("고객 %d이 %d분에 들어옵니다. 업무처리시간= %d분\n",customer.id,customer.arrival_time,customer.service_time);

		}
		if (service_time>0)
		{
			printf("고객 %d 업무처리중입니다. \n", service_customer);
			service_time--;
		}
		else
		{
			if (!is_empty(&queue))
			{
				element customer = dequeue(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;


				printf("고객 %d이 %d분에 업무를 시작합니다. 대기시간은 %d분이었습니다. \n", customer.id, clock, clock - customer.arrival_time);

				total_wait += clock - customer.arrival_time;


			}
		}
	}

	printf("전체 대기 시간=%d분 \n", total_wait);

	return 0;

}