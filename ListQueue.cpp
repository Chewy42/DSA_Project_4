/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: The file is the implementation of the ListQueue class. It takes use of the DblList class and only uses certain methods from it
to create a List Queue

High Level Decisions Used:
None
*/

#include "ListQueue.h"

/*
Name Of Function: ListQueue Constructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
ListQueue<T>::ListQueue(){
  theList = new DblList<T>();
}

/*
Name Of Function: ListQueue Destructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
ListQueue<T>::~ListQueue(){
  delete theList;
}

/*
Name Of Function: size

Description of Value Returned: integer of the size of our queue

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
int ListQueue<T>::size(){
  return theList->getSize();
}

/*
Name Of Function: add

Description of Value Returned: 

Description of Parameters: T c which is the template type and data that will be added to back of queue

Description of exceptions thrown: 
*/

template <typename T>
void ListQueue<T>::add(T c){
  theList->addBack(c);
}

/*
Name Of Function: remove

Description of Value Returned: T which is the template type of what we removed from the queue 

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
T ListQueue<T>::remove(){
  return theList->removeFront();
}

/*
Name Of Function: peek

Description of Value Returned: T which is the template type of whats at the front of the queue

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
T ListQueue<T>::peek(){
  return theList->get(0);
}

/*
Name Of Function: getList

Description of Value Returned: DblList<T>* which is the list of our current queue

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
DblList<T>* ListQueue<T>::getList(){
  return theList;
}

/*
Name Of Function: isEmpty

Description of Value Returned: boolean saying if the queue is empty

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
bool ListQueue<T>::isEmpty(){
  return theList->isEmpty();
}