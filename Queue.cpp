
#ifndef QUEUE_CPP
#define QUEUE_CPP
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//Templated linked list
//Note: Because the linked list is a templated class,
//      there is only ONE file (Queue.cpp)

//Templated node class
template <class T>
class Node {
public:
  Node( const T& data ); //Constructor
  T& GetData(); //Gets data from node
  void SetData( const T& data ); //Sets data in node
  Node<T>* GetNext(); //Gets next pointer
  void SetNext( Node<T>* next ); //Sets next pointer
private:
  T m_data;
  Node<T>* m_next;
};

//Overloaded constructor for Node
template <class T>
Node<T>::Node( const T& data ) {
   m_data = data;
   m_next = NULL;
}

//Returns the data from a Node
template <class T>
T& Node<T>::GetData() {
   return m_data;
}

//Sets the data in a Node
template <class T>
void Node<T>::SetData( const T& data ) {
   m_data = data;
}

//Gets the pointer to the next Node
template <class T>
Node<T>* Node<T>::GetNext() {
   return m_next;
}

//Sets the next Node
template <class T>
void Node<T>::SetNext( Node<T>* next ) {
   m_next = next;
}

template <class T>
class Queue {
 public:
  // Name: Queue() Queue from a linked list - Default Constructor
  // Desc: Used to build a new linked queue (as a linked list)
  // Preconditions: None
  // Postconditions: Creates a new queue where m_head and m_tail
  //                 point to nullptr and m_size = 0
  Queue();
  // Name: ~Queue() - Destructor
  // Desc: Used to destruct a Queue
  // Preconditions: There is a Queue
  // Postconditions: Queue is deallocated (including dynamically allocated nodes)
  //                 Can just call Clear()
 ~Queue();
  // Name: Queue (Copy Constructor)
  // Preconditions: Creates a copy of existing Queue in separate memory
  //                address (deep copy)
  //                Requires one already existing Queue
  // Postconditions: Copy of existing Queue
  Queue(const Queue&);
  // Name: operator= (Overloaded Assignment Operator)
  // Preconditions: When two Queue objects exist, sets one to equal another
  //                Requires two Queue objects
  // Postconditions: When completed, you have two Queues in
  //                 separate memory addresses with the same
  //                 number of nodes with the same values in each node
  Queue<T>& operator= (Queue&);
  // Name: PushBack
  // Preconditions: Takes in data. Creates new node. 
  //                Requires a Queue
  // Postconditions: Adds a new node to the end of the Queue.
  void PushBack(const T&);
  // Name: PopFront
  // Preconditions: Queue with at least one node. 
  // Postconditions: Removes first node in the queue and
  //                 returns the data in the first node
  T PopFront();
  // Name: Display
  // Preconditions: Outputs the queue.
  // Postconditions: Displays the data in each node of queue
  // Required (used only for queue testing)
  void Display();
  // Name: Front
  // Preconditions: Requires a Queue with at least one node
  // Postconditions: Returns whatever data is pointed at by m_head -
  //                 Does NOT remove node
  T Front();
  // Name: IsEmpty
  // Preconditions: Requires a queue
  // Postconditions: Returns if the queue is empty.
  bool IsEmpty();
  // Name: GetSize
  // Preconditions: Requires a queue
  // Postconditions: Returns m_size
  int GetSize();
  // Name: Find()
  // Preconditions: Requires a queue
  // Postconditions: Iterates and if it finds the thing, returns index, else -1
  int Find(T);
  // Name: Clear
  // Preconditions: Requires a queue
  // Postconditions: Deallocates and removes all nodes in a queue. No memory leaks
  void Clear();
  // Name: At
  // Precondition: Existing Queue
  // Postcondition: Returns object from Queue at a specific location
  // Desc: Iterates to node x and returns data from Queue
  T& At (int x);
  // Name: Swap(int)
  // Preconditions: Requires a queue
  // Postconditions: Swaps the nodes at the index with the node prior to it.
  // Example: Swap(1) would swap the node 0 with node 1 so
  //          that node 1 would now be m_head
  // Desc: Swaps two nodes by updating the pointers (not just the value)
  // Hint: Think about the special cases! Implement before Sort
  void Swap(int);
  // Name: Sort()
  // Preconditions: Requires a queue with a minimum of 2 nodes
  //                (otherwise notifies user)
  // Postconditions: Sorts the Queue (may use overloaded < or >).
  // Desc: This is used to sort anything in the Queue assuming the
  //       < or > is overloaded
  //        Uses bubble sort and Swap function above.
  //        Ensure working with queue_test before rest of project.
  // Note: Allowed to use the break command in just this function if necessary
  void Sort();
private:
  Node <T> *m_head; //Node pointer for the head
  Node <T> *m_tail; //Node pointer for the tail
  int m_size; //Number of nodes in queue
};


//**********Implement Queue Class Here***********
//**********All Functions Are Required Even If Not Used for Project**************
//**********No references to anything from Movie here*****************

  // Queue
  // Creates a new queue where m_head and m_tail,
  // point to nullptr and m_size = 0
  template <class T>
  Queue<T>::Queue(){
   m_head = nullptr;
   m_tail = nullptr;
   m_size = 0;
  }

  // ~Queue 
  // Queue is deallocated (including dynamically allocated nodes)
  template <class T>
  Queue<T>::~Queue(){
   // dellocates queue
   Queue<T>::Clear();
 }

  // Queue(X)
  // Creates a copy of existing Queue in separate memory address (deep copy)
  template <class T>
  Queue<T>::Queue(const Queue& other){
   // using overloaded operator=
   m_head = other.m_head;
   m_tail = other.m_tail;
   m_size = other.m_size;

  }

  // operator= 
  // Given two Queue objects sets one to equal another
  template <class T>
  Queue<T>& Queue<T>::operator= (Queue& other){

    // validates initialization
    if (this != &other){
        // Deallocate data in current Queue
        Node<T> *current = m_head; 
        while(current != nullptr){
            Node<T> *next = current->GetNext(); 
            delete current;
            current = next;
        }

        // Copy data from other Queue
        Node<T> *otherCurrent = other.m_head;
        while (otherCurrent != nullptr) {
            Queue<T>::PushBack(otherCurrent->GetData());
            otherCurrent = otherCurrent->GetNext();
        }
    }

    // returns copy
    return *this;
  }

  // PushBack
  // Adds a new node to the end of the Queue.
  template <class T>
  void Queue<T>::PushBack(const T& data){

    // dynamically creates new Node
    Node<T> *newNode = new Node(data);
    
    // case 1: Queue is empty 
    if(m_head == nullptr){ 
      m_head = newNode; 
      m_tail = newNode; 

      // increments Queue size
      m_size++;
    }

    // case 2: Queue contains 1 or more Nodes
    else{
        m_tail->SetNext(newNode); 
        m_tail = newNode; // Update m_tail to the newly created node

        // increments Queue size
        m_size++;
    }
  }

  // PopFront
  // Removes first node in the queue and
  // returns the data in the first node
  template <class T>
  T Queue<T>::PopFront(){

   // Queue contains one or more Nodes
   if(Queue<T>::IsEmpty() == false){
      Node<T> *temp = nullptr; 

      // case 1: Queue contains 1 Node
      if(Queue<T>::GetSize() == 1){
         temp = m_head;
         m_head = nullptr;
         m_tail = nullptr;
         --m_size;
         return temp->GetData();
      }

      // case 2: Queue contains 2 or more Nodes
      else{

        // Points to found airport after iteration
        temp = m_head;
        m_head = temp->GetNext();
        --m_size;
        return temp->GetData();
      }
   }

   // Queue Empty
   return nullptr;
  }

  // Display
  // Displays the data in each node of queue
  // Required (used only for queue testing)
  template <class T>
  void Queue<T>::Display(){

   // Queue Empty
   if(Queue<T>::IsEmpty() == true){
      cout << "\nQueue is Empty" <<endl;
   }

   // Queue contains one more Nodes
   else{

      // pointer to iterate over Queue
      Node<T> *temp = m_head; 
      
      while(temp != nullptr) {
         // prints data in the Node
         cout << temp->GetData() << endl;

         // iterates to next Node                           
         temp = temp->GetNext(); 
      } 
   }     

  }

  // Front
  // Returns whatever data is pointed at by m_head 
  template <class T>
  T Queue<T>::Front(){

   // Queue contains one or more Nodes
   if(Queue<T>::IsEmpty() == false){
      Node<T> *temp = m_head;
      return temp->GetData();
   }

   // Queue Empty
   return nullptr;
  }

  // IsEmpty
  // Returns true if the queue is empty.
  template <class T>
  bool Queue<T>::IsEmpty(){

   // Queue is empty
   if(Queue<T>::GetSize() < 1){
      return true;
   }
   
   // Queue is not empty
   return false;
  }

  // GetSize
  // Returns m_size
  template <class T>
  int Queue<T>::GetSize(){
   return m_size;
  }

  // Find
  // Returns index if Node found, else -1
  template <class T>
  int Queue<T>::Find(T data){

   // temp pointer to point to m_head 
   Node<T> *temp = m_head;

   // gets the Node in queue at given index
   for(int i = 0; i < Queue<T>::GetSize(); i++){

      // compares passed integer (Data) to i          
      if(data == temp->GetData()){ 
         return i;
      }

      // iterates to next Node in Queue
      temp = temp->GetNext();
   }

   // Node not found
   return -1;
  }
  

  // Clear
  // Deallocates and removes all nodes in a queue. No memory leaks
  template <class T>
  void Queue<T>::Clear(){
   
      // pointer to point to m_head
      Node<T> *temp = m_head;  

      // deallocate until last Node in queue
      while(m_head != nullptr){
         temp = m_head->GetNext(); 
         delete m_head;
         m_head = temp;
         temp = nullptr;
         --m_size;
      }

      //Resets all of the static queue pointers
      m_head = nullptr; 
      m_tail = nullptr; 
  }

  // At
  // Iterates to node x and returns data from Queue
  template <class T>
  T& Queue<T>::At (int x){

      // pointer to iterate over Queue
      Node<T> *temp = m_head; 
      
      // gets the Node in the queue at given index
      for(int i = 0; i < m_size; i++){

          // compares passed integer (x) to i          
          if(x == i){ 
            break;
          }
          
          // iterates to next Node in queue
          else{
               temp = temp->GetNext();  
          }

      }

   // returns data
   return temp->GetData();
  }

  // Swap
  // Swaps two nodes by updating the pointers (not just the value)
  template <class T>
  void Queue<T>::Swap(int nodeIndex){

      // prevNode trails currentNode
      Node<T> *prevNode = nullptr;

      // start from head of queue 
      Node<T> *currentNode = m_head;

      // Traverse to find the node to swap with
      for (int i = 0; i < nodeIndex - 1; i++) {
         prevNode = currentNode;
         currentNode = currentNode->GetNext();
      }

      // Special case: swapping with head node
      if (prevNode == nullptr) {
         Node<T> *nextNode = currentNode->GetNext();
         currentNode->SetNext(nextNode->GetNext());
         nextNode->SetNext(currentNode);
         m_head = nextNode;

         // updates m_tail if the next node becomes the new tail
         if (nextNode->GetNext() == nullptr) {
               m_tail = currentNode;
         }

      } 
      
      else {
         
         // Nodes other than head of queue
         // Store the next node and the node after that
         Node<T> *nextNode = currentNode->GetNext();
         Node<T> *nextNextNode = nextNode->GetNext();
         
         // Perform the swap
         prevNode->SetNext(nextNode);
         nextNode->SetNext(currentNode);
         currentNode->SetNext(nextNextNode);
         
         // Special case: swapping with tail node
         // If the nextNextNode is null, it means we swapped the current node with the last node
         // Hence, the current node becomes the new tail
         if (nextNextNode == nullptr) {
               m_tail = currentNode;
         }
      }

  }

  // Sort
  // Uses bubble sort and Swap function above to Sort anything in the Queue assuming the < or > is overloaded
  template <class T>
  void Queue<T>::Sort(){

   // tracks if swap occured
   bool swapped;

   // ptr1 used to traverse queue
   Node<T> *ptr1;

   // lptr points to last node swapped 
   Node<T> *lptr = nullptr;

   do {

      // resets swap flag
      swapped = false;

      // start from head of queue
      ptr1 = m_head;

      // trails ptr1 (previous Node)
      Node<T> *prev = nullptr;

      // iterates until end of queue reached
      while (ptr1->GetNext() != lptr) {
         
         // compares two adjacent Nodes 
         if (ptr1->GetData() > ptr1->GetNext()->GetData()) {

            // Swap nodes
            Node<T> *temp = ptr1->GetNext();
            ptr1->SetNext(temp->GetNext());
            temp->SetNext(ptr1);

            // updates the head of queue if swapping with first Node
            if (prev == nullptr) {
               m_head = temp;
            } 
            
            // Connects previous node to swapped node
            else {
               prev->SetNext(temp);
            }

            // Sets flag to true
            swapped = true;
         }

         // moves previous pointer
         prev = (prev == nullptr) ? m_head : prev->GetNext();

         // moves pointer to next node
         ptr1 = prev->GetNext();
      }

      // updates last node Swapped 
      lptr = ptr1;

   } while (swapped); // continues iterating until no more swaps 

   // Update m_tail to point to the last node in the sorted queue
   Node<T> *tempTail = m_head;

   // iterates until end of queue 
   while (tempTail->GetNext() != nullptr) {
      tempTail = tempTail->GetNext();
   }

   // updates m_tail of the sorted queue
   m_tail = tempTail;

   cout << endl;
}

#endif
