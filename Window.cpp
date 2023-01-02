/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file is the implementation for the Window class. In this class we handle all the needed methods to hold a student 
and calculate idle time. This is also used to support the needs of an office.

High Level Decisions Used:
None
*/

#include "Window.h"

/*
Name Of Function: Window Constructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

Window::Window(){
  total_idle_time = 0;
  num_students = 0;
  students = new Customer[num_students];
  bool isOpen = true;
}

/*
Name Of Function: Window Overloaded Constructor

Description of Value Returned: 

Description of Parameters: integer of the number of students and an array of customer objects

Description of exceptions thrown: 
*/

Window::Window(int num_s, Customer* s){
  total_idle_time = 0;
  num_students = num_s;
  students = s;
  bool isOpen = true;
}

/*
Name Of Function: Window Destructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

Window::~Window(){}

/*
Name Of Function: approachWindow

Description of Value Returned: 

Description of Parameters: Cutomer object that will be assigned to the current student

Description of exceptions thrown: 
*/

void Window::approachWindow(Customer s){
  student = s;
}

/*
Name Of Function: getOccupant

Description of Value Returned: Object type Customer of the current student at the window

Description of Parameters:

Description of exceptions thrown: 
*/

Customer Window::getOccupant(){
  return student;
}

/*
Name Of Function: setIsOccupied

Description of Value Returned: 

Description of Parameters: boolean open that will set the isOpen variable

Description of exceptions thrown: 
*/

void Window::setIsOccupied(bool open){
  isOpen = open;
}

/*
Name Of Function: occupantFinished

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void Window::occupantFinished(){
  Customer next(0);
  for(int i = 0; i < num_students; ++i){
    if(student.getNum() == students[i].getNum() && students[i].getTime() == 0){
      students[i].incrementPosition();
      students[i].setIsInLine(false);
      isOpen = true;
      student = next;
    }
  }
}

/*
Name Of Function: isWindowOccupied

Description of Value Returned: boolean that says if the window is open

Description of Parameters:

Description of exceptions thrown: 
*/

bool Window::isWindowOccupied(){
  return isOpen;
}

/*
Name Of Function: setIdleTime

Description of Value Returned: 

Description of Parameters: integer t for time that we will add to the idle time

Description of exceptions thrown: 
*/

void Window::setIdleTime(int t){
  total_idle_time += t;
}

/*
Name Of Function: getIdleTime

Description of Value Returned: integer of the total idle time

Description of Parameters:

Description of exceptions thrown: 
*/

int Window::getIdleTime(){
  return total_idle_time;
}

/*
Name Of Function: idleForFiveMins

Description of Value Returned: boolean saying if we had to idle for over five mins

Description of Parameters:

Description of exceptions thrown: 
*/

bool Window::idleForFiveMins(){
  if(total_idle_time > 5){
    return true;
  }
  else{
    return false;
  }
}
