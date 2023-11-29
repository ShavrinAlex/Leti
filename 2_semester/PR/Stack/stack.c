#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_SIZE 300

struct Node{
  char data;
  struct Node *next;
};

typedef struct Stack{
  struct Node *head;
  int size;
}Stack;

int isPairBracket(char left_bkt, char right_bkt)
{
    switch (left_bkt)
    {
        case '(':
            return right_bkt == ')';
        case '[':
            return right_bkt == ']';
        case '{':
            return right_bkt == '}';
        case '<':
            return right_bkt == '>';
    }
    return 0;
}

int isBracket(char bkt){
    switch (bkt){
        case '(':
        case '[':
        case '{':
        case '<':
            return -1;
        case ')':
        case ']':
        case '}':
        case '>':
            return 1;
    }
    return 0;
}

Stack initStack(){
  Stack stack={NULL, 0};
  return stack;
}

char pop(Stack *stack){
  struct Node *node = stack->head;
  stack->head = stack->head->next;
  char res = node->data;
  free(node);
  stack->size--;
  return res;
}

void push(Stack *stack, char new_element){
  struct Node *node = malloc(sizeof(struct Node));
  node->data = new_element;
  node->next = stack->head;
  stack->head = node;
  stack->size++;
}

char top(Stack *stack){   
    if (stack->head->data == -1) return '\0';
    return stack->head->data;
}

int isEmpty(Stack *stack){
  return !stack->size;
}

int count(Stack *stack){
  return stack->size;
}

int main(){
    Stack stack = initStack();
    char character;
    scanf("%c", &character);
    while (character != '\n'){
        switch (isBracket(character)){
            case -1:
                push(&stack, character);
                break;
            case 1:
                if (isEmpty(&stack)){
                    printf("wrong");
                    return 0;
                }
                if (isPairBracket(top(&stack), character))
                    pop(&stack);
                else{
                    printf("wrong");
                    return 0;
                }
                break;
        }
        scanf("%c", &character);
    }
    if (isEmpty(&stack))
        printf("correct");
    else
        printf("wrong");
    return 0;
}

