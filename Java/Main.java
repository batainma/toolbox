// Test for Stack
public class Main {
  public static void main(String[] args) {
    Stack<Integer> mystack = new Stack<Integer>();
    int i = 1;
    mystack.push(i);
    System.out.println(mystack.peek());
    System.out.println(mystack.getSize());
    mystack.push(++i);
    System.out.println(mystack.getSize());
    mystack.pop();
    mystack.pop();
    boolean test = mystack.isEmpty();
    if(test){
      mystack.pop();
    }
  }
}
