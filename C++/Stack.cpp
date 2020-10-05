#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Could use class generic but it doesnt really matter. Supports primitives and classes
template <typename T> class Stack {

  private:
    // singly linked list for stack
    struct Node {
      T item;
      Node* prev;
    };
    struct Node* top;
    int size;

  public:
    // default constructor
    Stack(){
      top = NULL;
      size = 0;
    }

    // pushes node onto linked list
    void push(T item) {
      struct Node* current = (struct Node*)malloc(sizeof(struct Node));
      current->item = item;
      current->prev = top;
      top = current;
      size++;
    }

    // returns top item
    T peek() {
      return top->item;
    }

    // pops top item off -- frees top node
    T pop() {
      T item = top->item;
      // temp required to free it after
      struct Node* temp = top;
      top = top->prev;
      free(temp);
      size--;
      return item;
    }

    // returns if size is 0
    bool isEmpty() {
      if(!size){
        return true;
      }

      return false;
    }

    int getSize() {
      return size;
    }

};

// test main
int main() {
  Stack<int> stack;

  stack.push(10);
  printf("%d\n", stack.peek());
  printf("%d\n", stack.getSize());
  printf("%d\n", stack.pop());
  printf("%d\n", stack.getSize());
  if(stack.isEmpty()){
    printf("empty!\n");
  }

  return 0;
}
