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
	cur -> n = n;
	cur -> next = next;
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
		cur = cur->next;
	}
	cur->next = last;
}

void Remove_even(List* list){
	Node* prev = NULL;
	Node* cur = list->head;
	int i = 1;
	while (cur){
		if (i%2 == 0){
			prev->next = cur->next;
			free(cur);
			cur = prev->next;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
		i++;
	}
}

void printList(List* list){
	Node* cur = list->head;
	while (cur){
		printf("%d ", cur -> n);
		cur = cur->next;
	}
}

int main(){
	List* list = calloc(1, sizeof(List));
	char c=' ';
	int n;
	while (c != '\n'){
		scanf("%d%c", &n, &c);
		pushBack(list, n);
	}
	Remove_even(list);
	printList(list);
	return 0;
}

