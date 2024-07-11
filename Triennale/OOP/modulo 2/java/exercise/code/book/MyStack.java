/*
Implement from scratch a generic class MyStack and a main method that use it. 
MyStack is a class that represents a stack data structure. 
A stack is a collection of elements, with two main principal methods: 

    ● push, which adds an element to the collection 
    ● pop, which removes the most recently element from the collection 
    
The order in which elements come off a stack is LIFO (last in, first out).
 */

import java.util.Objects;

public class MyStack<T extends Object> {

    //stack implementation
    // create a way to allocate dinamically inside an array generics
    private final T[] stackArray;
    private int top;

    //constructor
    @SuppressWarnings("unchecked")
    public MyStack() {
        stackArray = (T[]) new Object[10]; // initial capacity of 10
        top = -1; // initialize top index
    }

    //push method
    public T push(T element) {
        if (equals(element)) {
             System.out.println("Element is a Float!!");
             return element;
        }
        top++;
        stackArray[top] = element;
        System.out.println("Element pushed: " + element.getClass());
        return null;
    }

    public void pop() {
        if (top == -1) {
            System.out.println("Stack is empty");
        } else {
            top--;
        }
    }

    public void print() {
        for (int i = 0; i <= top; i++) {
            if (i == top) {
                System.out.println(stackArray[i]);
            } else {
                System.out.print(stackArray[i] + " -> ");
            }
        }
    }

    @Override
    public boolean equals(Object element) {
         return (element == null || element instanceof Float);
    }
    
    @Override
    public int hashCode() {
        return Objects.hash(stackArray, top);
    }

    public static void main(String[] args) {
        MyStack<Object> stack = new MyStack<>(); // Change the type to Integer
        stack.push(1);
        stack.push(Float.valueOf(2));
        stack.push(3);
        stack.push("Ciao");
        stack.print();
        stack.pop();
        stack.pop();
        stack.pop();
        stack.print();
    }
}
