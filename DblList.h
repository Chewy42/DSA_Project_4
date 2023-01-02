/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file defines the DblList class along with all the methods we will need to implement

High Level Decisions Used:
None
*/

#ifndef DBL_LIST_H
#define DBL_LIST_H
#include "ListNode.cpp"
#include <iostream>
using namespace std;
template <typename T>
class DblList{
public:
  DblList();
  virtual ~DblList();
  void print();

  int getSize();
  bool isEmpty();

  void addBack(T data);
  void addFront(T data);
  void add(int pos, T data);

  T removeBack();
  T removeFront();
  T remove(int pos);

  T get(int pos);
  bool contains(T data);
protected:
  ListNode<T>* m_front;
  ListNode<T>* m_back;
  int m_size;
};

#endif