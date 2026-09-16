/*Abdullah Abdulmosen Al-Nooh*/

#pragma once 
#include "LinkedList.h" 

 


// ======== Stack Template ========

template <typename T>
class Stack {

    Node<T>* top ;    // Points to the top element of the stack
    int size ;        // Tracks how many items are in the stack

public :

    // Constructor : start with an empty stack
    Stack() { top = nullptr ;  size = 0 ;  }

    // Destructor : free all nodes from memory
    ~Stack() {


        // There is a logical error in the loop and i solve it 
        // By Mohammed 
        // 4/12/2026
        while (top != nullptr) {

            Node<T>* temp = top ;
            top = top->next ;
            delete temp ;
        }
    }


    // ===== Push Add item to the top of the stack =======
    void push(T data) {

        Node<T>* newNode = new Node<T>(data) ;  // Create new node

        newNode->next = top ;  // New node points to the old top
        top = newNode ;        // New node becomes the new top

        size++ ;
        cout << "Pushed successfully !!" << endl;
    }


    // ===== Pop : Remove item from the top of the stack ==
    void pop() {

        if (top == nullptr) {

            cout << "Stack is empty , nothing to pop ! " << endl;
            return ;
        }

        Node<T>* temp = top ;  // Save the top node
        top = top->next ;      // Move top down one level
        delete temp ;          // Free memory

        size-- ;
        cout << "Popped succesfully !" << endl;
    }


    // ===== Peek : View top item without removing it =====
    Node<T>* peek() { return top ;}

    // ===== Getters =====
    int getSize() { return size ; }

    bool isEmpty() { return top == nullptr ; }

    Node<T>* getTop() { return top ; }

};


