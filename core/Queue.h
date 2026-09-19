/*Abdullah Abdulmosen Al-Nooh*/

#pragma once 
#include "LinkedList.h"



 


// ======== Queue Template =====

template <typename T>
class Queue {

    Node<T>* front ;   // Points to the first item in the queue
    Node<T>* back ;    // Points to the last item in the queue
    int size ;         // Tracks how many items are in the queue

public :

    // Constructor start with an empty queue
    Queue() {


        front = nullptr ;
        back  = nullptr ;
        size  = 0 ;

    }

    // Destructor free all nodes from memory
    ~Queue() {


        while (front != nullptr) {

            Node<T>* temp = front ;
            front = front->next ;
            delete temp ;


            
        }
    }


    // ===== Enqueue Add item to the back of the queue =====
    void enqueue(T data) {

        Node<T>* newNode = new Node<T>(data) ;  // Create new node

        // If queue is empty , front and back both point to new node
        if (back == nullptr) {

            front = newNode ;
            back  = newNode ;

        } else {
            
            // Fix 75 
            back->next = newNode ;  // Link current back to new node
            back = newNode ;        // New node becomes the new back
        }

        size++ ;
        cout << "Enqueued successfully !@" << endl;
    }


    // ===== Dequeue : Remove item from the front of the queue =====
    void dequeue() {

        if (front == nullptr) {

            cout << "Queue is empty , nothing to dequeue !!" << endl;
            return ;
        }

        Node<T>* temp = front ;    // Save front node
        front = front->next ;      // Move front to next node

        // If queue becomes empty after dequeue , reset back to null
        if (front == nullptr) { back = nullptr ; } 


        

        delete temp ;
        size-- ;
        cout << "Dequeued successfully !" << endl;
    }


    // ===== Peek : View the front item without removing it =====
    Node<T>* peek() {  return front ; }


    // ===== Getters =====
    int getSize() { return size ; }

    bool isEmpty() { return front == nullptr ; }

    Node<T>* getFront() { return front ; }

};



