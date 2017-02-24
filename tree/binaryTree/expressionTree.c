//将后缀表达式转为表达式树

#include<stdio.h>
#include<stdlib.h>
typedef struct binaryTreeNode binaryTreeNode;
typedef struct binaryTreeNode *ptrToNode;
struct binaryTreeNode{
	char element;
	ptrToNode left;
	ptrToNode right;
};

typedef struct stack{
	int capacity;
	int top;
	ptrToNode *a;
}stack;

//中序遍历树
void inorderTraversal(ptrToNode p){
	if(p!=NULL){
		inorderTraversal(p->left);
		printf("%c ",p->element);
		inorderTraversal(p->right);
	}
}

int main(void){
	char *s = "ab+cde+**";
	
	stack S;
	ptrToNode a[10];
	S.capacity = 10;
	S.a = a;
	S.top = -1;
	
	int c;
	while((c = *s)!='\0'){
		if(c >= 97 && c <= 102){
			ptrToNode p = (ptrToNode)malloc(sizeof(binaryTreeNode));
			p->element = c;
			p->right = NULL;
			p->left = NULL;
			S.a[++S.top] = p;
		}
		else{
			ptrToNode p = (ptrToNode)malloc(sizeof(binaryTreeNode));
			p->element = c;
			p->right = S.a[S.top--];
			p->left = S.a[S.top--];
			S.a[++S.top] = p;
		}
		s++;
	}
	inorderTraversal(S.a[S.top]);
	return 0;
}


