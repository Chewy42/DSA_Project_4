/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file defines the Window class along with all the necessary methods and data we will need for a window

High Level Decisions Used:
*/

#ifndef WINDOW_H
#define WINDOW_H

#include "Customer.h"
#include "ListQueue.h"
#include <cstdlib>
#include <iostream>

class Window{
    public:
    Window();
    Window(int num_students, Customer* students);
    ~Window();
    void fillWindows();
    void setIsOccupied(bool isOccupied);
    bool isWindowOccupied();
    void approachWindow(Customer student);
    void occupantFinished();
    Customer getOccupant();
    int getIdleTime();
    void setIdleTime(int time);
    bool idleForFiveMins();
    private:
    int total_idle_time;
    int num_students;
    Customer* students;
    Customer student;
    bool isOpen;
};

#endif