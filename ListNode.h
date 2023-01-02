/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file defines the ListNode class 

High Level Decisions Used:
None
*/

#ifndef LIST_NODE_H
#define LIST_NODE_H
#include <cstdlib>
#include <iostream>
using namespace std;
template <typename T>
class ListNode{
public:
  ListNode(T data);
  virtual ~ListNode();
  template <typename S>
  friend class DblList;
  template <typename S>
  friend class PQueue;
private:
  T m_data;
  ListNode<T>* m_next;
  ListNode<T>* m_prev;
};

#endif