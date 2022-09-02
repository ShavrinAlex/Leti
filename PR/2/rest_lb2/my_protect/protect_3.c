#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int n;
	struct Node* next;
} Node;

typedef struct List{
	Node* head;
} List;

Node* createNode(int n, Node* next){
	Node* cur = malloc(sizeof(Node));
	cur -> n = n;
	cur -> next = next;
	return cur;
}

void pushBack(List* list, int n){
	Node* last = createNode(n, NULL);
	if (! list -> head){
		list -> head = last;
		return;
	}
	Node* cur = list -> head;
	while (cur -> next){
		cur = cur -> next;
	}
	cur -> next = last;
}

void printList(List* list){
	Node* cur = list -> head;
	while (cur){
		printf("%d ", cur -> n);
		cur =  cur -> next;
	}
}

void pushFront(List* list, int n){
	Node* first = createNode(n, list -> head);
	list -> head = first;
}

int main(){
	List* list = calloc(1, sizeof(List));
	int n;
	int p;
	char c = ' ';
	while (c != '\n'){
		scanf("%d%c", &n, &c);
		pushBack(list, n);
	}
	scanf("%d%c", &p, &c);

	pushFront(list, p);
	printList(list);
	return 0;
}
