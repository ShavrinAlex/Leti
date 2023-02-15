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

void switchMaxMin(List* list){
	Node* cur = list -> head;
	int max = 0;
	int min = 1000;
	Node* Max = NULL;
	Node* Min = NULL;
	Node* prevMax = NULL;
	Node* prevMin = NULL;
	while (cur->next){
		if (cur -> next -> n > max){
			max = cur -> next -> n;
			prevMax = cur;
			Max = cur -> next;	
		}
		if (cur -> next -> n < min){
			min = cur -> next -> n;
			prevMin = cur;
			Min = cur -> next;	
		}
		cur = cur -> next;
	}
	if (prevMax && prevMin && Max && Min){
		if (prevMin -> n == max){
			prevMax -> next = Min;
			Max -> next = Min -> next;
			Min -> next = Max;
		}
		else{
			if (prevMax -> n == min){
				prevMin -> next = Max;
				Min -> next = Max -> next;
				Max -> next = Min;
			}
			else{
				prevMax -> next = Min;
				prevMin -> next = Max;
				Node* tmp = Max -> next;
				Max -> next = Min -> next;
				Min -> next = tmp;
			}
		}


	}
}

int main(){
	List* list = calloc(1, sizeof(List));
	int n;
	char c = ' ';
	while (c != '\n'){
		scanf("%d%c", &n, &c);
		pushBack(list, n);
	}
	switchMaxMin(list);
	printList(list);
	return 0;
}
