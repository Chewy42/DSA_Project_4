/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file implements the methods for the customer class. In this class it has all the
needed data and methods necessary for a customer

High Level Decisions Used:
Just deciding what a customer role needs
*/

#include "Customer.h"

/*
Name Of Function: Customer Constructor

Description of Value Returned: None

Description of Parameters: None

Description of exceptions thrown: None
*/

Customer::Customer(){
  num = 0;
  isInLine = false;
}

/*
Name Of Function: Customer Overloaded Constructor

Description of Value Returned: 

Description of Parameters: integer i which is the customers number in order

Description of exceptions thrown: 
*/

Customer::Customer(int i){
  num = i;
  isInLine = false;
}

/*
Name Of Function: Customer Destructor

Description of Value Returned: 

Description of Parameters: 

Description of exceptions thrown: 
*/

Customer::~Customer(){

}

/*
Name Of Function: getTime

Description of Value Returned: The integer returned is of the time array and getting 
the current position they're at in their order

Description of Parameters: 

Description of exceptions thrown: 
*/

int Customer::getTime(){
  return time[position];
}

/*
Name Of Function: setTime

Description of Value Returned: 

Description of Parameters: int i which is the position in the time array
were setting and t which is the time were setting

Description of exceptions thrown: 
*/

void Customer::setTime(int i, int t){
  time[i] = t;
}

/*
Name Of Function: changeTime

Description of Value Returned: 

Description of Parameters: int t which is the value of time were changing in the time
array at our current position. Basically decrementing by t.

Description of exceptions thrown: 
*/
void Customer::changeTime(int t){
  time[position] -= t;
}

/*
Name Of Function: getOffice

Description of Value Returned: the character returned is the character representing
the office currently being visited

Description of Parameters: 

Description of exceptions thrown: 
*/

char Customer::getOffice(){
  return officesVisited[position];
}

/*
Name Of Function: getPreviousOffice

Description of Value Returned: the character being returned is the current office
were at with a -1 position

Description of Parameters: 

Description of exceptions thrown: 
*/

char Customer::getPreviousOffice(){
  return officesVisited[position-1];
}

/*
Name Of Function: setOffice

Description of Value Returned: 

Description of Parameters: int i is the office were setting and character o is the value
were setting to the office that will represent it

Description of exceptions thrown: 
*/

void Customer::setOffice(int i, char o){
  officesVisited[i] = o;
}

/*
Name Of Function: getSpecificOffice

Description of Value Returned: character that is the office at a specific index

Description of Parameters: int index which is the index of the office were
trying to find

Description of exceptions thrown: 
*/

char Customer::getSpecificOffice(int index){
  return officesVisited[index];
}

/*
Name Of Function: getWaitTime

Description of Value Returned: integer of the wait time at a specific location

Description of Parameters: integer i which is the index were looking for
in the wait times array

Description of exceptions thrown: 
*/

int Customer::getWaitTime(int i){
  return wait_times[i];

}

/*
Name Of Function: setWaitTime

Description of Value Returned: 

Description of Parameters: integer timeWaited is the time were setting to the 
current position in the wait times array

Description of exceptions thrown: 
*/

void Customer::setWaitTime(int timeWaited){
  wait_times[position] = timeWaited;
}

/*
Name Of Function: waitedTenMin

Description of Value Returned: boolean stating if they have waited over 10 minutes

Description of Parameters:

Description of exceptions thrown: 
*/

bool Customer::waitedTenMin(){
  if ((wait_times[0] + wait_times[1] + wait_times[2]) > 10){
    return true;
  }
  else{
    return false;
  }
}

/*
Name Of Function: getNum

Description of Value Returned: integer of the customers number in the order they came

Description of Parameters:

Description of exceptions thrown: 
*/

int Customer::getNum(){
  return num;
}

/*
Name Of Function: setNum

Description of Value Returned: 

Description of Parameters: integer n for the number were assigning to the customer

Description of exceptions thrown: 
*/

void Customer::setNum(int n){
  num = n;
}

/*
Name Of Function: incrementPosition

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void Customer::incrementPosition(){
  position += 1;
}

/*
Name Of Function: getPosition

Description of Value Returned: integer of our current position in which
office we are at

Description of Parameters:

Description of exceptions thrown: 
*/

int Customer::getPosition(){
  return position;
}

/*
Name Of Function: setIsInLine

Description of Value Returned: 

Description of Parameters: boolean l which says if were in a line or not

Description of exceptions thrown: 
*/

void Customer::setIsInLine(bool l){
  isInLine = l;
}

/*
Name Of Function: getIsInLine

Description of Value Returned: boolean that says if were in a line or not

Description of Parameters:

Description of exceptions thrown: 
*/

bool Customer::getIsInLine(){
  return isInLine;
}