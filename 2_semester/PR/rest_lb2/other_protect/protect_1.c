#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
	int n;
	struct Node *next;
} Node;

typedef struct List{
	Node* head;
} List;

Node* createNode(int n, Node* next){
	Node* cur = malloc(sizeof(Node));
	cur->n = n;
	cur->next = next;
	return cur;
}

void pushBack(List* list, int n){
	Node* last = createNode(n, NULL);
	if (! list->head){
		list->head = last;
       		return;	
	}
	Node* cur = list -> head;
	while (cur->next){
		cur = cur->next;
	}
	cur->next = last;
}

void printList(List* list){
	Node* cur = list->head;
	printf("%d", cur->n);
	cur = cur -> next;
	while (cur){
		printf("=>%d", cur->n);
		cur = cur -> next;
	}
}

int main(){
	List *list = calloc(1, sizeof(List));
	char c;
	int n;
	for (int i = 0; i < 5; i++){
		scanf("%d%c", &n, &c);
		pushBack(list, n);
	}
	printf("\n");
	printList(list);	
	return 0;
}
