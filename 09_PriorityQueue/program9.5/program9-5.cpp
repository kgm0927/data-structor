#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int id;
	int avail;
}element;

typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

// 생성 함수

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

// 초기화 함수
void init(HeapType* h) {
	h->heap_size = 0;
}


// 현재 요소의 개수가 heap_size인 히프 h에 item을 삽입한다.
// 삽입 함수
void insert_min_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i!=1)&&(item.avail<h->heap[i/2].avail))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}


// 삭제함수
element delete_min_heap(HeapType* h) {
	int parent, child;
	element item, temp;


	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child<= h->heap_size)
	{

		if ((child < h->heap_size) && (h->heap[child].avail) > h->heap[child + 1].avail)child++;

		if (temp.avail < h->heap[child].avail) break; //temp.avail이 히프 avail보다 작다면 종료
		
		h->heap[parent] = h->heap[child];

		parent = child;
		child *= 2;


	}
	h->heap[parent] = temp;
	return item;

}

#define JOBS 7
#define MACHINES 3

int main(void) {
	int jobs[JOBS] = { 8,7,6,5,3,2,1 };
	element m = { 0,0 };
	HeapType* h;
	h = create();
	init(h);


	// 여기서 avail 값은 기계가 사용 가능하게 되는 시간이다.
	for (int i = 0; i < MACHINES; i++)
	{
		m.id = i + 1;
		m.avail = 0;
		insert_min_heap(h, m);
	}

	// 최소 히프에서 기계를 꺼내서 작업을 할당하고 사용가능 시간을 증가시킨 후에
	// 다시 최소 히프에 추가한다.

	for (int i = 0; i < JOBS; i++) {

		m = delete_min_heap(h);
		printf("JOB %d을 시간=%d부터 시간=%d까지 기계 %d번에 할당한다. \n",i,m.avail,m.avail+jobs[i]-1,m.id);

		m.avail += jobs[i];
		insert_min_heap(h, m);

	}
	return 0;
}