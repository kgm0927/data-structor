#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//
//			이진 탐색 트리의 분석
// 
// 이진 탐색 트리에서 탐색, 삽입, 삭제 연산의 시간 복잡도는 트리의 높이의 h라고 했을 대 O(h)가 된다.
// 따라서 n개의 노드를 가지는 이진 탐색 트리의 경우, 일반적인 이진 트리의 높이는 [log_2 n](ceil)이므로 
// 이진 탐색 트리 연산의 평균적인 경우의 시간 복잡도는 O(log_2 h)이다.
// 
// 그러나 이는 좌우의 서브 트리가 균형을 이룰 경우이고 최악의 경우에는 한쪽으로 치우치는 경사 트리가
// 되어서 트리의 높이가 n이 된다. 이 경우에는 탐색, 삭제, 삽입시간이 거의 선형 탐색과 같이 O(n)이 된다.
// 
// 따라서 선형탐새게 비하여 전혀 시간적으로 이득이 없다. 따라서 이러한 최악의 경우를 방지하기 위하여 트리의
// 높이를 [log_2 n]으로 한정시키는 균형 기법이 필요하다. 따라서 트리를 균형지게 만드는 기법으로 AVL트리를
// 비롯한 여러 기법들이 개발되었다. 균형 트리에 대한 기법은 12장에서 나온다.
// 
// 
// 
//			8.12 이진 탐색 트리의 응용: 영어 사전
// 
// 이진 탐색 트리를 이용하여 영어 사전을 구현하여 보자. 이진 탐색 트리는 탐색을 위한 자료 구조이기 때문에
// 탐색이 효율적으로 될 것임을 기대할 수 있다. 프로그램의 메뉴는 다음과 같다.
// 
// 가장 중요한 메뉴는 '입력', '탐색','삭제'이다. 입력이 선택되면 사용자로부터 단어와 그 의미를 입력받아
// insert_node 함수를 사용하여 이진 탐색 트리에 저장한다. 탐색이 선택되면 사용자로부터 입력받아 이진 탐색
// 트리에서 search 함수를 이용하여 탐색한 다음, 그 의미를 화면에 출력한다.
// 
// 삭제가 선택되면 delete_node 함수를 이용하여 입력된 단어를 찾아서 삭제한다.
// 
//


// 
// 여기서는 이진 탐색 트리에 저장되는 데이터가 정수가 아니다. 따라서 element 타입을 구조체로 정의하고 구조체 안에
// 우리가 필요한 필드들을 넣어야 한다. 필수적으로 영어 단어와 그 의미가 각각 저장되어야 하므로 우리는 두 개의 문자열
// 배열이 필요하다. 따라서 element 타입은 다음과 같이 word 배열과 meaning 필드를 가지도록 정의된다. 여기서 element
// 타입의 word 필드는 탐색의 기준이 되는 키 필드가 된다. 트리 노드도 element 타입을 데이터로 저장하도록 변경되었다.
//

#define MAX_WORD_SIZE		100
#define MAX_MEANING_SIZE	200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
}element;

typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
}TreeNode;

//
// 추가로 두 개의 element 항목의 순서를 비교하는 함수 compare가 필요하다. compare(e1,e2)함수는 e1과
//  e2를 알파벳 순서로 비교하여 e1이 e2보다 작으면 -1, 같으면 0, 크면 1을 각각 반환한다. compare 함수는
// strcmp 함수를 이용하여 구현되었다.
// 


// 만약 e1<e2 이면 -1 반환
// 만약 e1==e2 이면 0 반환
// 만약 e1>e2 이면 1 반환

int compare(element e1, element e2) {
	return strcmp(e1.word, e2.word);
}


// 이진 탐색 트리 출력 함수
void display(TreeNode* p) {

	if (p!=NULL)
	{
		printf("(");
		display(p->left);
		printf("%s:%s", p->key.word, p->key.meaning);
		display(p->right);
		printf(")");

	}
}

// 이진 탐색 트리 탐색 함수

TreeNode* search(TreeNode* root, element key) {
	TreeNode* p = root;
	while (p != NULL)
	{
		if (compare(key, p->key) == 0)
			return p;
		else if (compare(key, p->key) < 0)
			p = p->left;
		else if (compare(key, p->key) > 0)
			p = p->right;

	}
	return p; // 탐색에 실패했을 경우 NULL 반환
}

TreeNode* new_node(element item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, element key) {

	// 트리가 공백이면 새로운 노드를 반환한다.
	if (node == NULL)return new_node(key);

	// 그렇지 않으면 순환적으로 트리를 내려간다.
	if (compare(key, node->key) < 0)
		node->left = insert_node(node->left, key);

	else if (compare(key, node->key) > 0)
		node->right = insert_node(node->right, key);

	// 루트 포인터를 반환한다.
	return node;
}

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;

	// 맨 왼쪽 단말 노드를 찾으려 내려감
	while (current->left != NULL)
		current = current->left;

	return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고 새로운 루트 노드를 반환한다.

TreeNode* delete_node(TreeNode* root, element key) {
	
	if (root == NULL)return root;
	
	// 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것임
	if (compare(key, root->key) < 0)
		root->left = delete_node(root->left, key);
	
	// 만약 키가 루트보다 크면 오른쪽 서브 트리에 있는 것임
	if (compare(key, root->key) > 0)
		root->right = delete_node(root->right, key);


	//키가 루트와 같으면 이 노드를 삭제하면 됨
	else
	{
		// 첫 번째나 두 번째 경우
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		// 세 번째 경우
		TreeNode* temp = min_value_node(root->right);

		// 중위 순회시 후계 노드를 복사한다.
		root->key = temp->key;

		// 중위 순회시 후계 노드를 삭제한다.
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}

void help() {
	printf("\n**** i: 입력, d: 삭제, s:탐색, p: 출력, q: 종료 ****: ");
}

int main(void) {
	char command;
	element e;
	TreeNode* root = NULL;
	TreeNode* tmp;
	do
	{
		help();
		command = getchar();
		getchar();

		switch (command) {
		case 'i':
			printf("단어:");
			gets_s(e.word, MAX_WORD_SIZE);
			printf("의미:");

			gets_s(e.meaning, MAX_MEANING_SIZE);
			root = insert_node(root, e);
			break;
		
		case 'd':
			printf("단어:");
			gets_s(e.word, MAX_WORD_SIZE);
			root = delete_node(root, e);
			break;

		case 'p':
			display(root);
			printf("\n");
			break;

		case 's':
			printf("단어:");
			gets_s(e.word, MAX_WORD_SIZE);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미:%s\n", e.meaning);
			break;
		}
	} while (command!='q');
	return 0;
}