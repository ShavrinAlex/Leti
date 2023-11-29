#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int n;
	struct Node* next;
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
	Node* cur = list->head;
	while (cur->next){
		cur = cur-> next;
	}
	cur->next = last;
}

Node* maxNode(List* list){
	int mx = 0;
	Node* max;
	Node* cur = list->head;
	while (cur){
		if (cur->n > mx){
			mx = cur->n;
			max = cur;
		}
		cur = cur->next;
	}
	return max;
}

void printList(List* list){
	Node* cur = list->head;
	while (cur){
		printf("%d ", cur -> n);
		cur = cur->next;
	}
	printf("\n");
}

int main(){
	List* list = calloc(1, sizeof(List));
	int n;
	for (int i = 0; i < 10; i++){
		scanf("%d", &n);
		pushBack(list, n);
	}
	printList(list);
	Node* max = maxNode(list);
	printf("%d\n", max->n);
	return 0;
}
