//遍历树,2017-2-24

#include<stdio.h>
#include<stdlib.h>

typedef struct binaryTreeNode binaryTreeNode;
typedef struct binaryTreeNode *ptrToNode;

struct binaryTreeNode{
	int element;
	ptrToNode left;
	ptrToNode right;
};

void inorderTraversal(ptrToNode p){
	if(p != NULL){
		inorderTraversal(p->left);
		printf("%c ", p->element);
		inorderTraversal(p->right);
	}
}

int main(void){
	binaryTreeNode a;
	a.element = 'a';
	a.left = NULL;
	a.right = NULL;

	binaryTreeNode b;
	b.element = 'b';
	b.left = NULL;
	b.right = NULL;

	binaryTreeNode root;
	root.element = '*';
	root.left = &a;
	root.right = &b;

	inorderTraversal(&root);
	
	return 0;
}
