/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file defines the Office class along with the necessary methods and data

High Level Decisions Used:
None
*/

#ifndef OFFICE_H
#define OFFICE_H

#include <string>
#include "Customer.h"
#include "ListQueue.h"
#include "ListQueue.cpp"
#include "Window.h"
#include <iostream>

using namespace std;

class Office{
    public:
    Office();
    Office(int num_windows, int num_students, Customer* students);
    virtual ~Office();
    void fillWindows();
    void addToQueue(Customer customer);
    void removeFromQueue();
    void headChangeTime(int time);
    Customer getWindow(int i);
    bool windowOpen();
    bool allOpen();
    bool isLineEmpty();
    int getSize();
    void addIdleTime(int time);
    int getIdleTime(int i);
    int idleFiveMin();
    private:
    Window* windows;
    int num_windows;
    int num_students;
    int* wait_times;
    int wait_len;
    int position;
    ListQueue<Customer> line;
    Customer* students;
};

#endif