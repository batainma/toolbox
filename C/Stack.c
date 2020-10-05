//#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// what kind of stack do you want it to be?
// define type of "item"
#define TYPE int

// Tracks size of stack
int stackSize = 0;

// Simpl node structure for stack
struct StackNode {
  TYPE item;
  struct StackNode* prev;
};

// method to create new node
struct StackNode* createNode(TYPE item) {
  struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));
  node->item = item;
  node->prev = NULL;
  return node;
}

// Checks if empty
int isEmpty(struct StackNode* top) {
  // if top is NULL then it is not false (true)
  return !top;
}

// Adds node onto stack
void push(struct StackNode** top, TYPE item){
  struct StackNode* stackNode = createNode(item);
  stackNode->prev = *top;
  *top = stackNode;
  stackSize++;
}

// Pops node off of stack and returns item value
TYPE pop(struct StackNode** top) {
  if (isEmpty(*top)){
    fprintf(stderr, "Stack is empty; Cannot peek.");
    return NULL;
  }
  struct StackNode* temp = *top;
  *top = (*top)->prev;
  TYPE popped = temp->item;
  free(temp);
  stackSize--;
  return popped;
}

// returns top node item
TYPE peek(struct StackNode* top) {
  if (isEmpty(top)) {
    fprintf(stderr, "Stack is empty; Cannot peek.");
    return NULL;
  }
  return (top)->item;
}

// Main
int main()
{
    struct StackNode* top = NULL;

    push(&top, 10);
    push(&top, 20);
    push(&top, 30);

    printf("%d popped from stack\n", pop(&top));

    printf("Top element is %d\n", peek(top));

    printf("Size is %d\n", stackSize);

    return 0;
}
