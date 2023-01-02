/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: 
This file defines the ListQueue class with the methods we will need to implement 

High Level Decisions Used:
None
*/

#ifndef LIST_QUEUE_H
#define LIST_QUEUE_H
#include "DblList.h"
#include "DblList.cpp"
#include <cstdlib>
using namespace std;
template <typename T>
class ListQueue{
public:
  ListQueue();
  ~ListQueue();
  int size();
  bool isEmpty();
  void add(T c);
  T remove();
  T peek();
  DblList<T>* getList();
private:
  DblList<T>* theList;
};

#endif