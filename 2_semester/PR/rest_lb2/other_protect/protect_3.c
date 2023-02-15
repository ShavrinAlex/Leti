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

int Remove(int n, List* list){
	Node* prev = NULL;
	Node* cur = list->head;
	while (cur){
		if (cur -> n == n){
			if (!prev){
				list->head = cur->next;
				free(cur);
			}
			else{
				prev->next = cur->next;
				free(cur);
			}
			return 1;
		}
		prev = cur;
		cur = cur->next;
	}
	return -1;
}

int main(){
	List* list = calloc(1, sizeof(List));
	char c;
	int n, r;
	int i = 0;
	scanf("%d%c", &r, &c);
	while (c != '\n'){
		scanf("%d%c", &n, &c);
		pushBack(list, n);
		i++;
	}
	printf("%d\n", Remove(r, list));
	return 0;
}
