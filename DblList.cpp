/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This takes use of the ListNode class to create a Doubly Linked list

High Level Decisions Used:
None
*/

#include "DblList.h"

/*
Name Of Function: DblList Constructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/
template <typename T>
DblList<T>::DblList(){
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

/*
Name Of Function: DblList Destructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
DblList<T>::~DblList(){
  m_size = 0;
  m_front = NULL;
  m_back = NULL;
}

/*
Name Of Function: getSize

Description of Value Returned: returns the integer of the current size of the list

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
int DblList<T>::getSize(){
  return m_size;
}

/*
Name Of Function: isEmpty

Description of Value Returned: boolean saying if the list is empty

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
bool DblList<T>::isEmpty(){
  return (m_size==0);
}

/*
Name Of Function: get

Description of Value Returned: T which is the template type of the node were looking for

Description of Parameters:int pos for the position we wanna get

Description of exceptions thrown: 
*/

template <typename T>
T DblList<T>::get(int pos){
  int cPos = 0;
  ListNode<T>* current = m_front;
  while(cPos != pos){
    current = current->m_next;
    ++cPos;
  }
  return current->m_data;
}

/*
Name Of Function: contains

Description of Value Returned: bool is yes or no if it is in the list

Description of Parameters: T data which is the data were looking for in our list

Description of exceptions thrown: 
*/

template <typename T>
bool DblList<T>::contains(T data){
  bool found = false;
  ListNode<T>* current = m_front;
  while(current != NULL){
    if(data == current->m_data){
      found = true;
      break;
    }
    current = current->m_next;
  }
  return found;
}

/*
Name Of Function: addFront

Description of Value Returned: 

Description of Parameters: T data which is the data we are adding to the front of the list

Description of exceptions thrown: 
*/

template <typename T>
void DblList<T>::addFront(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_front->m_prev = newNode;
    newNode->m_next = m_front;
  } else{
    m_back = newNode;
  }
  m_front = newNode;
  ++m_size;
}

/*
Name Of Function: addBack

Description of Value Returned: 

Description of Parameters: T data which is the data we are adding to the back of the list

Description of exceptions thrown: 
*/

template <typename T>
void DblList<T>::addBack(T data){
  ListNode<T>* newNode = new ListNode<T>(data);
  if(!isEmpty()){
    m_back->m_next = newNode;
    newNode->m_prev = m_back;
  } else{
    m_front = newNode;
  }
  m_back = newNode;
  ++m_size;
}

/*
Name Of Function: add

Description of Value Returned: 

Description of Parameters: integer pos for the position we will add the node in at and T data for the data that will be added there

Description of exceptions thrown: 
*/

template <typename T>
void DblList<T>::add(int pos, T data){
  if(isEmpty()){
    addFront(data);
  } else if(pos==0){
    addFront(data);
  } else if(pos>=m_size-1){
    addBack(data);
  } else{
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos!=pos){
      current = current->m_next;
      ++cPos;
    }
    ListNode<T>* newNode = new ListNode<T>(data);
    current->m_prev->m_next = newNode;
    newNode->m_prev = current->m_prev;
    current->m_prev = newNode;
    newNode->m_next = current;
    ++m_size;
  }
}

/*
Name Of Function: removeFront

Description of Value Returned: T which is the template type

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
T DblList<T>::removeFront(){
  T data;
  data = m_front->m_data;
  if(m_size == 1){
    delete m_front;
    m_front = NULL;
    m_back = NULL;
  } else{
    ListNode<T>* currFront = m_front;
    m_front = m_front->m_next;
    m_front->m_prev = NULL;
    currFront->m_next = NULL;
    delete currFront;
  }
  --m_size;
  return data;
}

/*
Name Of Function: removeBack

Description of Value Returned: T which is the template type

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
T DblList<T>::removeBack(){
  T data;
  data = m_back->m_data;
  if(m_size == 1){
    delete m_front;
    m_front = NULL;
    m_back = NULL;
  } else{
    ListNode<T>* currBack = m_back;
    m_back = m_back->m_prev;
    m_back->m_next = NULL;
    currBack->m_prev = NULL;
    delete currBack;
  }
  --m_size;
  return data;
}

/*
Name Of Function: remove

Description of Value Returned: T for what we removed from the list

Description of Parameters: integer pos for position we will remove at

Description of exceptions thrown: 
*/

template <typename T>
T DblList<T>::remove(int pos){
  T data;
  if(pos<=0){
    data = removeFront();
  } else if(pos >= m_size-1){
    data = removeBack();
  } else{
    ListNode<T>* current = m_front;
    int cPos = 0;
    while(cPos != pos){
      current = current->m_next;
      ++cPos;
    }
    data = current->m_data;
    current->m_prev->m_next = current->m_next;
    current->m_next->m_prev = current->m_prev;
    current->m_next = NULL;
    current->m_prev = NULL;
    delete current;
    --m_size;
  }
  return data;
}

/*
Name Of Function: print

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
void DblList<T>::print(){
  ListNode<T>* current = m_front;
  while(current!=NULL){
    cout << current->m_data << endl;
    current = current->m_next;
  }
}