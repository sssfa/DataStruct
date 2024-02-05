#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	struct node *next;
}*Nodep;

int Insert_node(Nodep head,int value);

int Delete_node(Nodep head,int n);

Nodep Seach_node(Nodep head,int n);

void dumplist(Nodep head);

int Clear_list(Nodep head);

Nodep find_last(Nodep head,int n);

int count_occurrences(Nodep head,int n);

Nodep Reverse(Nodep head);
