#include <stdio.h>
#include <string.h>

#define SIZE 20

typedef struct {
	int   key[SIZE];
	char* val[SIZE];
} HashTable;

size_t hash(int key){
	return key%SIZE;
}
void insert(HashTable *ht, int key, char* val){
	size_t index = hash(key);

	while(ht->key[index] != -1){
		index++;
		if(index == SIZE)
			index = 0;
	}
	ht->key[index] = key;
	ht->val[index] = strdup(val);
}
char* lookup(HashTable *ht, int key){
	size_t index = hash(key);
	while(ht->key[index] != key)
	{
		index++;
		if(index == SIZE)
			index = 0;
	}

	return ht->val[index];
}
void print(HashTable ht){
	printf("index ");
	for(size_t i=0;i < SIZE;i++)
		printf("|%3u", i);
	printf("\nkey   ");
	for(size_t i=0;i < SIZE;i++)
		printf("|%3d", ht.key[i]);
	printf("\nval   ");
	for(size_t i=0;i < SIZE;i++)
	{
		if(ht.val[i] == NULL)
		printf("|%3x", ht.val[i]);
		else
		printf("|%s", ht.val[i]);

	}
	printf("\n");

}
int main(){
	HashTable hashtable;
	for(int i=0;i < SIZE;i++){
		hashtable.key[i] = -1;
		hashtable.val[i] = NULL;
	}
	insert(&hashtable,101,"ykx");
	insert(&hashtable,298,"wxr");
	insert(&hashtable,333,"abc");
	insert(&hashtable,12,"zfz");
	insert(&hashtable,112,"wcc");
	insert(&hashtable,318,"wx2");
	insert(&hashtable,338,"wx3");
	printf("Look for %s\n",lookup(&hashtable,338));
	print(hashtable);

	return 0;
}
