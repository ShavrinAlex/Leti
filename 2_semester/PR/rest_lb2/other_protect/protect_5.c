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
	while (cur){
		printf("%d ", cur->n);
		cur = cur -> next;
	}
}

void switchMaxMin(List* list){
	Node* cur = list->head;
	int max = 0;
	int min = 1000;
	Node* prevMax;
	Node* prevMin;
	while (cur->next){
		if (cur->next->n > max){
			max = cur -> next->n;
			prevMax = cur;
		}
		if (cur->next->n < min){
			min = cur -> next->n;
			prevMin = cur;
		}
		cur = cur->next;
	}
	if (prevMax && prevMin){
		if (prevMin->n == max){
			Node* max = prevMax->next;
	        	Node* min = prevMin -> next;	
			
			prevMax->next = min;
			prevMin->next = min->next;
			min->next = prevMin;
		}
		if (prevMax->n == min){
			Node* max = prevMax->next;
	        	Node* min = prevMin -> next;	
			
			prevMin->next = max;
			prevMax->next = max->next;
			max->next = prevMax;
		}
		else{
			Node* max = prevMax->next;
	        	Node* min = prevMin -> next;	

			prevMax->next = min;
			prevMin->next = max;
			Node* tmp = min->next;
			min -> next = max -> next;
			max->next = tmp;
		}	
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
	switchMaxMin(list);
	printList(list);	
	return 0;
}
