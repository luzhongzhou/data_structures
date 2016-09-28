#include <stdio.h>
#include <stdlib.h>

//list
struct Node{
    int name;
    struct Node *next;
};

typedef struct Node *ptrToNode;
typedef struct Node *List;

//no head node
void insert(List L, int x){
	if(L == NULL){
		L = malloc(sizeof(struct Node));
		L->name = x;
	}else{
	    ptrToNode p;
	    p = malloc(sizeof(struct Node));
	    p->name = x;
	    p->next = L->next;
	    L->next = p;
	}
}

void printList(List L){
    while(L != NULL){
        printf("->%d", L->name);
        L = L->next;
    }
    printf("\n");
}
void reorderList(struct Node* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL) return;
    
    struct Node* p;
    struct Node* q;
    struct Node* pre_q;
    
    p = head;
    q = head;
    pre_q = head;
    
    while(pre_q->next->next != NULL) pre_q = pre_q->next;
    q = pre_q->next;
    
    q->next = p->next;
    p->next = q;
    
    p = q->next;
    
    pre_q->next = NULL;
    
    reorderList(p);
}

void reorderList2(struct Node* head) {
    if(head == NULL || head->next == NULL || head->next->next == NULL) return;
    
    struct Node* p;
    struct Node* q;
    struct Node* middle;
    
    p = head;
    q = head;
 	while(q->next != NULL && q->next->next != NULL){
		p = p->next;
		q = q->next->next;
	}   
 	middle = p;
	
	p = middle->next;	
	q = p->next;
	while(q!=NULL){
		p->next = q->next;
		q->next = middle->next;
		middle->next = q;
		
		q=p->next;
	}

	p=head;
	q=middle->next;
	while(p != middle){
		middle->next = q->next;
		q->next = p->next;
		p->next = q;
		q= middle->next;
		p=p->next->next;		
	}
}
int main(){
	List L; //未初始化的指针类型值为0

	int i;
	for(i=6;i>0;i--)
		insert(L, i);

	printf("before reorder:\n");
	printList(L);
	reorderList2(L);
	printf("after reorder:\n");
	printList(L);
	return 0;
}
