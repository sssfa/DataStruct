#include "listnode.h"

int main (){
	struct node *head;
	head = malloc(sizeof(struct node));
	head->next = NULL;
	head->value= 0;

	dumplist(head);
	Insert_node(head,1);
	Insert_node(head,2);
	Insert_node(head,3);
	Insert_node(head,4);
	Insert_node(head,5);
	dumplist(head);
	//Delete_node(head,2);
	//dumplist(head);
	//ClearList(&head);
	int count = count_occurrences(head,2);
	printf("%d occur %d\n",2,count);
	dumplist(find_last(head,3));
	dumplist( Reverse(head));
	dumplist(head);


	if(head!=NULL){
		free(head);
	}
	return 0;

}
