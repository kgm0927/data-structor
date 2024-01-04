#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;

#define MAX_STACK_SIZE 100


typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s))
	{
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s))
	{
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}


element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int check_matching(const char* in) {

	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);
	init_stack(&s);

	for (i = 0; i < n; i++)
	{
		ch = in[i];

		switch (ch)
		{
		case '(': case'[':case'{':
			push(&s, ch);
			break;

		case ')':case ']':case '}':

			if (is_empty(&s)) return 0;
			else
			{
				open_ch = pop(&s);

				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}'))
				{
					return 0;
				}
				break;
			}

		}
	}
	if (!is_empty(&s)) return 0;

	return 1;

}


int main(void) {
	const char* p = "{ A[(i+1)]=0; }";
	if (check_matching(p)==1)
	{
		printf("%s 괄호검사성공\n", p);

	}
	else printf("%s 괄호 검사 실패\n", p);

	return 0;
}


//
// 
//		4.4 스택의 응용: 괄호 검사 문제
// 
// 
// 프로그램에서는 여러 가지 종류의 괄호들이 있는데, 괄호들은 항상 쌍이 되게금 사용되어야 한다.
// 프로그램에서 사용되는 괄호는 대괄호 [,], 중괄호{,}, 소괄호(,), 등이다. 이들이 올바르게
// 사용되었는지 스택을 사용하여 검사해야 한다. 괄호의 검사 조건은 다음의 3가지이다.
// 
// 
//		* 조건 1: 왼쪽 괄호의 개수와 오른쪽 괄호의 개수가 같아야 한다.
//		* 조건 2: 같은 종류의 괄호에서 왼쪽괄호은 오른쪽 괄호보다 먼저 나와야 한다
//		* 조건 3: 서로 다른 종류의 왼쪽 괄호와 오른쪽 괄호 쌍은 서로를 교차해서는 안된다.
// 
// 
// 
// 
// 
//		* 알고리즘 4.5(121.p)
// 
// 
//			check_matching(expr):
//		
//			while(입력 expr의 끝이 아니면)
//			ch<- expr의 다음 글자
//			switch(ch)
// 
//				case '(': case '[': case'{':
//					ch를 스택에 삽입
//					break
// 
//				case ')': case ']': case '}':
//					if(스택이 비어 있으면)
//						then 오류
//						else 스택에서 epen_ch를 꺼낸다.
//							if(ch와 open_ch가 같은 짝이 아니면)
//								then 오류 보고
//				break
//			
//			if(스택이 비어 있지 않으면)
//				then 오류
//		
// 
// 
// 
//