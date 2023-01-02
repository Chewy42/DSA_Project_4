/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file is the implementation for the Office class. This class handles all the operations of an office in our simulation
and is the bread and butter of the program.

High Level Decisions Used:
A high level decision I did was to write out every step I think an office would need to take then implement it one by one
*/

#include "Office.h"

/*
Name Of Function: Office Constructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

Office::Office(){
    num_windows = 0;
    num_students = 0;
    windows = new Window[num_windows];
    students = new Customer[num_students];
    for(int i = 0; i < num_windows; ++i){
        windows[i] = Window();
    }
    wait_times = new int[num_students];
    wait_len = 0;
    position = 0;
}

/*
Name Of Function: Office Overloaded Constructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

Office::Office(int num_windows, int num_students, Customer* students){
    this->num_windows = num_windows;
    this->num_students = num_students;
    this->students = students;
    windows = new Window[num_windows];
    fillWindows();
    wait_times = new int[num_students];
    wait_len = 0;
    position = 0;

}

/*
Name Of Function: Office Destructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

Office::~Office(){

}

/*
Name Of Function: fillWindows

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void Office::fillWindows(){
    for(int i = 0; i < num_windows; ++i){
        windows[i] = Window(num_students, students);
    }
}

/*
Name Of Function: addToQueue

Description of Value Returned: 

Description of Parameters: Customer object that will be added to back of queue

Description of exceptions thrown: 
*/

void Office::addToQueue(Customer student){ // Adds customer to queue
    line.add(student);
    wait_len += 1;
    for(int i = 0; i < num_students; ++i){
    if(student.getNum() == students[i].getNum()){
        students[i].setIsInLine(true);
    }
  }
}

/*
Name Of Function: removeFromQueue

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void Office::removeFromQueue(){ // Removes from front of queue and puts in window
    Customer next = line.remove();
    int index;
    for(int i = 0; i < num_students; ++i){
        if(next.getNum() == students[i].getNum()){
        index = i;
        }
    }
    students[index].setWaitTime(wait_times[position]);
    position += 1;
    for (int i = 0; i < num_windows; ++i){
        if (windows[i].isWindowOccupied()){
        windows[i].approachWindow(students[index]);
        windows[i].setIsOccupied(false);
        break;
        }
    }  
}

/*
Name Of Function: headChangeTime

Description of Value Returned: 

Description of Parameters: integer time which is the time we will change of the student

Description of exceptions thrown: 
*/

void Office::headChangeTime(int time){
    for (int j = 0; j < num_windows; ++j){
        for(int i = 0; i < num_students; ++i){
            if(windows[j].getOccupant().getNum() == students[i].getNum()){
                students[i].changeTime(time);
            }
        }
    }
    for (int i = position; i < wait_len; ++i){
        wait_times[i] += time;
    }
    for (int i = 0; i < num_windows; ++i){
        windows[i].occupantFinished();
  }
}

/*
Name Of Function: getWindow

Description of Value Returned: Customer that is occupying the window at said location

Description of Parameters: integer i which is the position of the window array we are looking for an occupant

Description of exceptions thrown: 
*/

Customer Office::getWindow(int i){
  return windows[i].getOccupant();
}

/*
Name Of Function: windowOpen

Description of Value Returned: boolean if all the windows are open

Description of Parameters:

Description of exceptions thrown: 
*/

bool Office::windowOpen(){
  bool allOpen;
  for (int i = 0; i < num_windows; ++i){
    if(windows[i].isWindowOccupied()){
      allOpen = true;
      break;
    }
    else{
      allOpen = false;
    }
  }
  return allOpen;
}

/*
Name Of Function: allOpen

Description of Value Returned: boolean if all windows are open

Description of Parameters:

Description of exceptions thrown: 
*/

bool Office::allOpen(){
  bool allOpen = false;
  for (int i = 0; i < num_windows; ++i){
    if(windows[i].isWindowOccupied()){
        allOpen = true;
    }
    else{
      allOpen = false;
      break;
    }
  }
  return allOpen;
}

/*
Name Of Function: isLineEmpty

Description of Value Returned: boolean if the current queue / line is empty

Description of Parameters:

Description of exceptions thrown: 
*/

bool Office::isLineEmpty(){
  return line.isEmpty();
}

/*
Name Of Function: getSize

Description of Value Returned: integer of the size of the current queue / line

Description of Parameters:

Description of exceptions thrown: 
*/

int Office::getSize(){
  return line.size();
}

/*
Name Of Function: addIdleTime

Description of Value Returned: 

Description of Parameters: integer time which will add idle time to the windows that are open

Description of exceptions thrown: 
*/

void Office::addIdleTime(int time){
  for (int i = 0; i < num_windows; ++i){
    if (windows[i].isWindowOccupied()){
      windows[i].setIdleTime(time);
    }
  }
}

/*
Name Of Function: getIdleTime

Description of Value Returned: integer of the windows idle time sum

Description of Parameters: integer i which is the index of the windows we want to see from

Description of exceptions thrown: 
*/

int Office::getIdleTime(int i){
  return windows[i].getIdleTime();
}

/*
Name Of Function: idleFiveMin

Description of Value Returned: integer of amount of times the window was idle for five minutes

Description of Parameters:

Description of exceptions thrown: 
*/

int Office::idleFiveMin(){
  int e = 0;
  for (int i = 0; i < num_windows; ++i){
    if (windows[i].idleForFiveMins()){
      e += 1;
    }
  }
  return e;
}
