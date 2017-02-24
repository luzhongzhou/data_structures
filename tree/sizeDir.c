//树的后序遍历

#include <stdio.h>

typedef struct TreeNode *ptrToNode;
typedef struct TreeNode{
        char *Name;
	int size;
        ptrToNode FirstChild;
        ptrToNode NextSibling;
}TreeNode;

int sizeDir(ptrToNode p){
	int totalSize = 0;
	if(p != NULL){
		totalSize = p->size + sizeDir(p->FirstChild) + sizeDir(p->NextSibling);
	}
	return totalSize;
}

int main(void){
	TreeNode root, bin, usr, etc;
	TreeNode file;
/*
目录结构及文件大小：
/(1)
	/bin(1)
		myFile(5)
	/usr(1)
		myFile(5)
	/etc(1)
*/
	root.Name = "/";
	root.size = 1;
	root.FirstChild = &bin;
	root.NextSibling = NULL;
	
	bin.Name = "/bin";
	bin.size = 1;
	bin.FirstChild = &file;
	bin.NextSibling = &usr;
	
	usr.Name = "/usr";
	usr.size = 1;
	usr.FirstChild = &file;
	usr.NextSibling = &etc;

	etc.Name = "/etc";
	etc.size = 1;
	etc.FirstChild = NULL;
	etc.NextSibling = NULL;

	file.Name = "myFile";
	file.size = 5;
	file.FirstChild = NULL;
	file.NextSibling = NULL;	
 
	printf("%d\n", sizeDir(&root));
	return 0;
}
