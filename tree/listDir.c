#include <stdio.h>

typedef struct TreeNode *ptrToNode;
typedef struct TreeNode{
        char *Name;
        ptrToNode FirstChild;
        ptrToNode NextSibling;
}TreeNode;

// deepth控制缩进
void listDir(ptrToNode p, int deepth){
	if(p != NULL){
		int temp = deepth;
		while(temp > 0){
		       printf("\t");
		       temp--;
		}
		printf("%s\n", p->Name);
		listDir(p->FirstChild, deepth+1);
		listDir(p->NextSibling, deepth);
	}
}

int main(void){
	TreeNode root, bin, usr, etc;
	TreeNode file;
/*
目录结构：
/
	/bin
		myFile
	/usr
		myFile
	/etc
*/
//在结构体的初始化上，实例化类会方便一些
	root.Name = "/";
	root.FirstChild = &bin;
	root.NextSibling = NULL;
	
	bin.Name = "/bin";
	bin.FirstChild = &file;
	bin.NextSibling = &usr;
	
	usr.Name = "/usr";
	usr.FirstChild = &file;
	usr.NextSibling = &etc;

	etc.Name = "/etc";
	etc.FirstChild = NULL;
	etc.NextSibling = NULL;

	file.Name = "myFile";
	file.FirstChild = NULL;
	file.NextSibling = NULL;	
 
	listDir(&root, 0);
	return 0;
}
