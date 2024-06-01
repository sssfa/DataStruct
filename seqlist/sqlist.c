#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define FUNP printf("##%s called\n",__func__)
typedef int ElemType;
typedef struct {
	ElemType *Data;
	int Maxsize;
	int Length;
} seqlist;

void InitList(seqlist *L){
	FUNP;
	L->Length  = 0;
	L->Maxsize = 20;
	L->Data    = malloc(L->Maxsize*sizeof(ElemType));
}

int  Length(seqlist L) { return L.Length;}

bool Empty(seqlist L){ return !L.Length;}

int LocateElem(seqlist L,ElemType e){
	FUNP;
	if(Empty(L))
		return -1;
	for(int i=0;i<L.Length;i++)
		if(L.Data[i]==e)
			return i;
	return -1;
}
int GetElem(seqlist L,int i){
	if(Empty(L))
		return -1;
	return L.Data[i];	
}
void ListExpand(seqlist *L){
	FUNP;
	printf("Len: %d Maxsize: %d Data: %p\n",Length(*L),L->Maxsize,L->Data);
	L->Maxsize *=2;
	realloc(L->Data,L->Maxsize*sizeof(ElemType));
}
int ListInsert(seqlist *L,int i,ElemType e){
	FUNP;
	if(i<0 || i>=L->Maxsize)
		return -1;
	if(L->Length >= L->Maxsize)
		ListExpand(L);
		
	for(int j=L->Length+1;j>i;j--){
		L->Data[j]=L->Data[j-1];
	}
	L->Length ++;
	L->Data[i] = e;
	return 0;
}
int ListDelete(seqlist *L,int i,ElemType *e){
	FUNP;
	if(i>= L->Length || i<0)
		return -1;
	e = L->Data[i];
	for(int j=i;j<L->Length;j++){
		L->Data[j]=L->Data[j+1];
	}
	L->Length--;
	return 0;
}
void Dumplist(seqlist L) {
	FUNP;
	if(Empty(L)){
		printf("The list is Empty\n");
		return;
	}
	for(int i=0;i<L.Length;i++)
		printf("%02d:%2d\n",i,L.Data[i]);
	printf("****\n");
}
void DestroyList(seqlist *L){
	FUNP;
	L->Length =0;
	free(L->Data);
}

int main(){
	seqlist sq;
	ElemType e;

	FUNP;
	InitList(&sq);
	for(int i=0;i<99;i++)
		ListInsert(&sq,0,i);
	printf("Len: %d Maxsize: %d Data0: %d\n",Length(sq),sq.Maxsize,*sq.Data);
	Dumplist(sq);
	ListDelete(&sq,2,&e);
	ListDelete(&sq,2,&e);
	printf("Len: %d Maxsize: %d Data0: %d\n",Length(sq),sq.Maxsize,*sq.Data);
	Dumplist(sq);
	//DestroyList(&sq);
	printf("The num %d locate at index %d\n",3,LocateElem(sq,3));
	printf("The num %d locate at index %d\n",GetElem(sq,1),1);
	return 0;
}
