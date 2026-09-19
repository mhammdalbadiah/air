

//Ahmed farraj Alotaibi


#pragma once 

    // =========== Node Template ========
    // Each node holds one data item and a pointer to the next node


    template <typename T>
    struct Node {

        T data ;         // The actual object stored in this node
        Node* next ;     // Pointer to the next node in the list

        // Constructor initialize data and set next to null
        Node(T d) : data(d) , next(nullptr){}

    };




    // ============ Linked List Template ========
    // A singly linked list that can hold any of our 4 data types

    template <typename T>
    class LinkedList {

        Node<T>* head ;   // Pointer to the first node in the list
        int size ;        // Tracks how many nodes are in the list

    public :

        // Constructor start with an empty list
        LinkedList(): head(nullptr) , size(0) {}

    
        // Destructor free all nodes from memory when list is destroyed

        ~LinkedList() {

            Node<T>* current = head ;

            while (current != nullptr) {

                Node<T>* temp = current ;
                current = current->next ;
                delete temp ;
            }
        }


        // ========== Insert at the end of the list ======
    void insert(T data) {

        Node<T>* newNode = new Node<T>(data) ;  // Create a new node

        // If list is empty , the new node becomes the head
        if (head == nullptr) {

            head = newNode ;

        } else {

            // Traverse to the last node
            Node<T>* current = head ;

            while (current->next != nullptr) {
                current = current->next ;
            }

            // Attach new node at the end
            current->next = newNode ;
        }

        size++ ;
        cout << "Inserted successfully !  " << endl;
    }


    // =========== Delete a node by its position =======

    void deleteByPosition(int pos) {

        // Check if list is empty
        if (head == nullptr) {

            cout << "List is empty , nothing to delete !! " << endl;
            return ;
        }

        // Check if position is valid
        if (pos < 1 || pos > size) {

            cout << "Invalid position !!! Must be between 1 and " << size << endl;
            return ;
        }

        Node<T>* temp ;

        // Special case : deleting the first node
        if (pos == 1) {

            temp = head ;
            head = head->next ;
            delete temp ;

        } else {

            // Traverse to the node just before the target position
            Node<T>* current = head ;

            for (int i = 1 ; i < pos - 1  ; i++) 
             current = current->next ; 


            

            temp = current->next ;            // Node to be deleted
            current->next = temp->next ;      // Skip over the deleted node
            delete temp ;
        }

        size-- ;
        cout << "Deleted successfully ! " << endl;
    }


    // =======- Get pointer to a node by position  =====
    // Used internally by Modify and Find


    Node<T>* getNodeAt(int pos) {

        if (pos < 1 || pos > size) {
            
            return nullptr ;
        }

        Node<T>* current = head ;

        for (int i = 1 ; i < pos ; i++)
          current = current->next ; 

        return current ;
    }


    // ===== Replace the data at a given position =====
    void modifyAt(int pos , T newData) {

        Node<T>* node = getNodeAt(pos) ;

        if (node == nullptr) {

            cout << "Invalid position !" << endl;
            return ;
        }

        node->data = newData ;
        cout << "Modified successfully !" << endl;
    }


    // ===== Getters =====
    int getSize() { return size ; }

    Node<T>* getHead() { return head ; }

    bool isEmpty() { return head == nullptr ; }

};



