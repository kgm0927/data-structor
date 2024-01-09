#include <stdio.h>
#include <stdlib.h>
#define max(a,b)  (((a) > (b)) ? (a) : (b))

//
// 
//			8.7 트리의 응용: 수식 트리 처리
// 
// 이진 트리는 수식 트리(expression tree)를 처리하는데 사용될 수 있다.수식 트리는 산술 연산자와
// 피연산자로 만들어진다. 피연산자들은 단말노드가 되며 연산자는 비단말이 된다.
// 
// 
// 이들 수식 트리를 전위, 중위, 후위의 순회 방법으로 읽으면 각각 전위 표기 수기, 중위 표기 수식, 
// 후위 표기 수식이 된다.
// 
// 
// -------------------------------------------------------------------------------------------------------------------------
//		수식		|				a+b				|			a-(b*c)				|				(a<b)or(c<d)
// -------------------------------------------------------------------------------------------------------------------------
//		전위순회	|		+ a b					|		- a * b c				|			or < a b < c d
// -------------------------------------------------------------------------------------------------------------------------
//		중위순회	|		a + b					|		a-(b*c)					|			(a<b)or(c<d)
// -------------------------------------------------------------------------------------------------------------------------
//		후위순회	|		a b +					|		a b c * -				|			a b < c d < or
// -------------------------------------------------------------------------------------------------------------------------
// 
// 수식 트리로 표현된 수식의 값을 계산하는 문제를 생각해보면, 4장에서 우리는 스택을 이용하여 후위 표기 수식을 계산한 바 있다.
// 지금은 입력이 후위 표기 수식이 아니고 수식 트리임을 유의하여야 한다. 수식 트리의 루트 노드는 연산자이고 따라서 이 연산자의
// 피연산자인 자식들만 계산되면 전체 수식을 계산할 수 있다. 따라서 우리는 루트보다 자식 노드들이 먼저 방문되는 순회 방법을
// 사용하여야 수식의 값을 계산할 수 있을 것이다.
// 
// 루트 노드보다 자식 노드를 먼저 방문하는 순회 방법은 후위 순회이다.
// 
// 
// 수식 트리의 계산 알고리즘을 유사 코드로 살펴보면 다음과 같다.
// 
// 수식 트리 프로그램
// ------------------------------------------------------------------------------------------------------------------------------
//		evaluate(exp):
// 1.		if exp==NULL
// 2.			then return 0;
// 3.			else x<-evaluate(exp.left);
// 4.				 y<-evaluate(exp.right);
// 5.				 op<-exp.data
// 6.				 return (x op y);
// 7.
// 8.
// 9.
// 
// 
// 알고리즘 설명
// 
// -------------------------------------------------------------------------------------------------------------------------------
// 1. 만약 수식 트리가 공백 상태이면
// 2. 그냥 복귀한다.
// 3. 그렇지 않으면 왼쪽 서브 트리를 계산하기 위해 evaluate를 다시 순환호출한다. 이때 매개변수는 왼쪽 자식 노드가 된다.
// 4. 똑같은 식으로 오른쪽 서브 트리를 계산한다.
// 5. 루트 노드의 데이터 필드에서 연산자를 추출한다.
// 6. 추출된 연산자를 가지고 연산을 수행해서 반환한다.
// -------------------------------------------------------------------------------------------------------------------------------
// 
// 
// 
//
//
//		8.8 트리의 응용: 디렉토리 용량 계산
// 
// 다음과 같은 디렉토리 구조에서 루트 디렉토리인 "나의 문서"의 용량을 알려면 어떻게 하여야 할까?
// 
// 
// 하나의 디렉토리 안에 디렉토리가 있을 수 있으므로 먼저 서브 디렉토리의 용량을 모두 계산한 다음에 루트 디렉토리의 용량을
// 계산하여야 할 것이다. 따라서 '후위 순회'를 사용하여야 한다. 후위 순회를 사용하되 순환 호출되는 순회 함수가 용량을 반환하도록
// 만들어야 한다. 따라서 순회 함수를 조금 변경하면 된다.

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;

}TreeNode;


int calc_dir_size(TreeNode* root) {
	int left_size, right_size;
	if (root == NULL)return 0;

	left_size = calc_dir_size(root->left);
	right_size = calc_dir_size(root->right);

	return (root->data + left_size + right_size);
}
int get_height(TreeNode* node) {
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));

	return height;
}


int main(void) {
	TreeNode n5 = { 500,NULL,NULL };
	TreeNode n4 = { 200,NULL,NULL };
	TreeNode n3 = { 100,&n4,&n5 };
	TreeNode n2 = { 50,NULL,NULL };
	TreeNode n1 = { 0,&n2,&n3 };


	printf("디렉토리의 크기= %d\n", calc_dir_size(&n1));
	printf("높이=%d \n", get_height(&n1));
}
//
//		8.9 이진 트리의 추가 연산
// 
// 이진 트리와 관련된 여러 가지 추가적인 연산들에 대하여 살펴보자.
// 
//
// 
//			노드의 개수
// 
// 탐색 트리안의 노드의 개수를 세어 표시한다. 노드의 개수를 세기 위해서는 트리안의 노드들을 전체적으로 순회하여야 한다.
// 각각의 서브트리에 대하여 순환 호출한 다음, 반환되는 값에 1을 더하여 반환하면 된다. 다음은 의사 코드로 표시된 알고리즘이다.
// 
// 
//		알고리즘 8.6
// --------------------------------------------------------------------------------------------------------------------------
//		get_node_count(x):
// 
// if x!=NULL then
// return 1+get_node_count(x.left)+get_count(x.right);
// --------------------------------------------------------------------------------------------------------------------------
// 
// C언어로 나타낸 것
//

int get_node_count(TreeNode* node) {
	int count = 0;
	if (node != NULL)
		count = 1 + get_node_count(node->left) + get_node_count(node->right);

	return count;
}

//
//			단말노드 개수 구하기
// 
// 단말 노드의 개수를 세기 위해서는 트리안의 노드들을 전체적으로 순회하여야 한다. 순회하면서 만약 왼쪽자식과 오른쪽 자식이 동시에 0이 되면
// 단말노드이므로 1을 반환한다. 그렇지 않으면 비단말 노드이므로 각각의 서브트리에 대하여 순환 호출한 다음, 반환되는 값을 서로 더하면 된다.
// 
//		알고리즘 8.7
// --------------------------------------------------------------------------------------------------------------------------------------
//	get_leaf_count(T):
// 
// if T!=NULL then
//		if T.left==NULL and T.right==NULL
//			then return 1;
//			else return get_leaf_count(T.left)+get_leaf_count(T.right);
// 
// --------------------------------------------------------------------------------------------------------------------------------------
// 
//

int get_leaf_count(TreeNode* node) {
	int count = 0;
	if (node != NULL) {
		if (node->left == NULL && node->right == NULL)
			return 1;
		else
			count = get_leaf_count(node->left) + get_leaf_count(node->right);
	}

	return count;
}



//
// 
//			높이 구하기
// 
// 트리의 높이를 구하려면, 순환 호출을 완벽히 이해하고 있어야 한다. 여기서부터는 서브 트리의 반환값을 서로 더하는 것이 의미가 없다.
// 여기서는 서브 트리들의 반환값 중에서 최대값을 구하여 반환하여야 한다.
// 
// 
//		알고리즘 8.8 이진 탐색 트리에서 높이 구하는 알고리즘
// -------------------------------------------------------------------------------------------------------------------------------
//		get_height(T):
//		
//		if T!=NULL
//			return 1+max(get_height(T.left),get_height(T.right));
// -------------------------------------------------------------------------------------------------------------------------------
// 이 밑에 있는 것은 의사 코드를 C언어로 구현한 것이다.


int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL) {
		height  =1+ max(get_height(node->left), get_height(node->right));
	}

	return height;
}

