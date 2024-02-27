#include "listnode.h"

int count_occurrences(Nodep head,int n){
	if(head ==NULL){
		printf("NULL list\n");
		return -1;
	}
	int count=0;
	for(;head != NULL;head=head->next)
		if(head->value == n)
			count++;	
	return count;
}
int Insert_node(Nodep head,int value){
	Nodep Newnode = malloc(sizeof(struct node));
	Nodep p;
	if(Newnode == NULL) return 1;
	Newnode -> next = NULL;
	Newnode -> value= value;
	for(p=head;p->next!=NULL;p=p->next);
	p -> next     = Newnode;

	return 0;
}

int Delete_node(Nodep head,int n){
	Nodep prev,cur;

	for(cur = head,prev = NULL;cur != NULL,cur->value !=n;prev = cur,cur = cur->next);
	prev->next = cur->next;
	free(cur);

	return 0;
}

int Clear_list(Nodep head){
	if(head->next!=NULL)
		Clear_list(head->next);
	printf("%d is cleard\n",head->value);
	free(head);

	return 0;
}
Nodep find_last(Nodep head,int n){
	Nodep prev;
	for(;head != NULL;head=head->next){
		if(head->value == n)
			prev = head;
	}
	return prev;
}

int ClearList(Nodep *head){
	Clear_list(*head);
	printf("Pointer set to NULL\n");
	*head =NULL;

	return 0;
}

Nodep Seach_node(Nodep head,int n){
	for(;head != NULL;head=head->next)
		if(head->value == n)
			return head;
	return NULL;
}

void dumplist(Nodep head){
	for(Nodep p=head; p!=NULL; p=p->next)
		printf("%d ",p->value);
	if(head->next == NULL)
		printf("NULL list");
	printf("\n");
}
Nodep Reverse(Nodep head){
	Nodep prev =NULL;
	Nodep cur  =head;

	for(cur;cur!=NULL;){
		Nodep right = cur->next;
		cur->next   = prev;
		prev = cur;
		cur = right;
	}
	return prev;
}
