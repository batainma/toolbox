/**
 ** Stack implementation with stack size variable
 ** Singly linked list ; generic stack type
 ** Mohammed Bataineh
 **/
public class Stack<T> {

  // node for singly linked list
  private class Node {
    T item;
    Node prev;
  }

  // class variables
  private Node top;
  private int size;

  // return size
  public int getSize() {
    return size;
  }

  // First node in list must point to null
  // Initialize top as null is required for first push
  Stack() {
    top = null;
  }

  // add a node onto list
  public void push(T item) {
    Node current = new Node();
    current.item = item;
    current.prev = top;
    top = current;
    size++;
  }

  // remove top node
  public void pop() {
    // if size is 0
    if(size == 0){
      System.out.println("Stack is empty.");
      return;
    }
    top = top.prev;
    size--;
  }

  // Alternative pop method:
  // this one allows for pop to return the item as well
  // Disadvantage: if T is a large object then the copy
  // may result in performance reductions
  /*
  public T pop() {
    T item = top;
    top = top.prev;
    return item;
    }
  */

  // check top item
  public T peek() {
    // if size is 0
    if(size == 0){
      System.out.println("Stack is empty.");
      return null;
    }
    return top.item;
  }

  // checks if size is 0
  public boolean isEmpty(){
    if(size == 0){
      return true;
    }
    else{
      return false;
    }
  }

}
