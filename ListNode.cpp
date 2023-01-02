/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file is the implementation of the ListNode class. All it does is hold the values of the next and previous nodes as well as hold some data

High Level Decisions Used:
*/

#include "ListNode.h"

/*
Name Of Function: ListNode overloaded constructor

Description of Value Returned: 

Description of Parameters: T data which is the data assigned to this node

Description of exceptions thrown: 
*/

template <typename T>
ListNode<T>::ListNode(T data){
  m_data = data;
  m_next = NULL;
  m_prev = NULL;
}

/*
Name Of Function: ListNode destructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

template <typename T>
ListNode<T>::~ListNode(){
  m_next = NULL;
  m_prev = NULL;
}