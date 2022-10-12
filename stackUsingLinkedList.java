/*
Implementing Stack using Linked List in java.


Stack is A data structure Which uses the principal of FILO(First In Last Out).
Means the element inserted in the last will be removed first.

Insertion -> Push;
Removing Element from Stack -> Pop;
See last Element -> peek;
 */

package Stacks;

import java.util.Scanner;

public class stackUsingLinkedList {

    private Node top;
    private int length;

//    Node class
    private static class Node{
        private int data;
        private Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }


//    Constructor
    public stackUsingLinkedList(){
        top = null;
        length = 0;
    }

//    Method to get the length of the stack
    public int getLength(){
        return length;
    }

//    Method to check is stack empty or not
    public boolean isEmpty(){
        return length == 0;
    }


//    Method to Push ot Insert the data into the stack
    public void push(int data){
        Node temp = new Node(data);

        temp.next = top;
        top = temp;
        length++;
    }

//    Method to pop or remove the Elemnt from the Stack
    public int pop(){
        int value = top.data;
        top = top.next;
        length--;
        return value;
    }

//    Method to see the top elemnt of the stack
    public int peek(){
        return top.data;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        stackUsingLinkedList stack = new stackUsingLinkedList();

        while(true){
            System.out.println("Please select One Option : \n" +
                    "To push data Press 1 \n" +
                    "To pop data Press 2 \n" +
                    "To peek top data Press 3 \n" +
                    "To get length Press 4 \n" +
                    "Press 0 to Exit \n");
            int choice = sc.nextInt();

            switch (choice){

                case 0 -> {
                    System.exit(0);
                }
                case 1 -> {
                    System.out.println("Enter the data : \n");
                    int data = sc.nextInt();
                    stack.push(data);
                }
                case 2 -> {
                    System.out.println("Popped Element is " + stack.pop());
                }
                case 3 -> {
                    System.out.println("Top Element is " + stack.peek());
                }
                case 4 -> {
                    System.out.println("Length of the stack is " + stack.getLength());
                }
                default -> {
                    System.out.println("Wrong Input");
                }
            }
        }
    }
}
