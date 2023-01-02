/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This class handles all the simulation of the program and calculates the data we need to print out in the end.

High Level Decisions Used:
No high level decisions just tedious
*/

#include "ServiceCenter.h"

#include <iostream>
#include <string>

using namespace std;

/*
Name Of Function: ServiceCenter Constructor

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

ServiceCenter::ServiceCenter(){
  numWinRegister = 0;
  numWinCashier = 0;
  numWinFA = 0;
  numOfStudents = 0;
  customerNum = 0;
  students = new Customer[numOfStudents];
  Office reg(numWinRegister, numOfStudents, students);
  Office cashier(numWinCashier, numOfStudents, students);
  Office fa(numWinFA, numOfStudents, students);
  offices = new Office[3];
  offices[0] = reg;
  offices[1] = cashier;
  offices[2] = fa;
}

/*
Name Of Function: Service Center Overloaded Constructor

Description of Value Returned: 

Description of Parameters: we take in all of the integers representing the amount of number of windows each office will have as well as
the number of students

Description of exceptions thrown: 
*/

ServiceCenter::ServiceCenter(int num_windows_reg, int num_windows_cash, int num_windows_fin, int num_students){
  numWinRegister = num_windows_reg;
  numWinCashier = num_windows_cash;
  numWinFA = num_windows_fin;
  numOfStudents = num_students;
  customerNum = 0;
  students = new Customer[numOfStudents];
  Office reg(numWinRegister, numOfStudents, students);
  Office cashier(numWinCashier, numOfStudents, students);
  Office fa(numWinFA, numOfStudents, students);
  offices = new Office[3];
  offices[0] = reg;
  offices[1] = cashier;
  offices[2] = fa;
}

/*
Name Of Function: Service Center Destructor

Description of Value Returned: 

Description of Parameters: we take in the integers representing the times students will arrive and the character for each
office the student will visit in order

Description of exceptions thrown: 
*/

ServiceCenter::~ServiceCenter(){
}

void ServiceCenter::addStudent(int studentTimes0, int studentTimes1, int studentTimes2, char office0, char office1, char office2){
  customerNum += 1;
  Customer student(customerNum);
  student.setTime(0, studentTimes0);
  student.setTime(1, studentTimes1);
  student.setTime(2, studentTimes2);
  student.setOffice(0, office0);
  student.setOffice(1, office1);
  student.setOffice(2, office2);
  students[customerNum-1] = student;
}

/*
Name Of Function: locate

Description of Value Returned: 

Description of Parameters: We take in a Customer object called student 

Description of exceptions thrown: 
*/

void ServiceCenter::locate(Customer student){ 

  //Add the student to the queue of the office they are trying to visit
  if (student.getOffice() == 'R' && student.getPosition() < 3){
    offices[0].addToQueue(student);
  }
  else if (student.getOffice() == 'C' && student.getPosition() < 3){
    offices[1].addToQueue(student);
  }
  else if (student.getOffice() == 'F' && student.getPosition() < 3){
    offices[2].addToQueue(student);
  }
}

/*
Name Of Function: shortestTime

Description of Value Returned: The value returned is an object type Customer that has the shortest time

Description of Parameters:

Description of exceptions thrown: 
*/

Customer ServiceCenter::shortestTime(){ 
  //Set shortest time to an absurdly large number initially
  int shortest = 1000000;
  int customerNum;
  //Loop through the number of register windows
  for (int r = 0; r < numWinRegister; ++r){
    //Set student to the register offices windows
    Customer student = offices[0].getWindow(r);
    //Nested loop that compares each time to the shortest time until it reaches the shortest time
    for (int i = 0; i < numOfStudents; ++i){
      if(student.getNum() == students[i].getNum()){
        if(students[i].getTime() < shortest && students[i].getTime() > 0){
          shortest = students[i].getTime();
          customerNum = students[i].getNum();
        }
      }
    }
  }
  //Repeat above code for each window till we get a shortest time
  for (int c = 0; c < numWinCashier; ++c){
    Customer student = offices[1].getWindow(c);
    for (int i = 0; i < numOfStudents; ++i){
      if(student.getNum() == students[i].getNum()){
        if(students[i].getTime() < shortest && students[i].getTime() > 0){
          shortest = students[i].getTime();
          customerNum = students[i].getNum();
        }
      }
    }
  }
  for (int f = 0; f < numWinFA; ++f){
    Customer student = offices[2].getWindow(f);
    for (int i = 0; i < numOfStudents; ++i){
      if(student.getNum() == students[i].getNum()){
        if(students[i].getTime() < shortest && students[i].getTime() > 0){
          shortest = students[i].getTime();
          customerNum = students[i].getNum();
        }
      }
    }
  }
  for (int i = 0; i < customerNum; ++i){
    if(customerNum == students[i].getNum()){
      return students[i];
      break;
    }
  }
}

/*
Name Of Function: Simulate

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::Simulate(){ 
  //Locate first students to each office and add to queue
  for (int i = 0; i < numOfStudents; ++i){
    locate(students[i]);
  }
  //Loop through each office, check if empty, if not then remove from queue and add to all available windows
  for(int r = 0; r < numWinRegister; ++r){
    if(!offices[0].isLineEmpty()){
      offices[0].removeFromQueue();
    }
  }
  for(int c = 0; c < numWinCashier; ++c){
    if(!offices[1].isLineEmpty()){
      offices[1].removeFromQueue();
    }
  }
  for(int f = 0; f < numWinFA; ++f){
    if(!offices[2].isLineEmpty()){
      offices[2].removeFromQueue();
    }
  }

  //Use this to store the shortest time
  Customer time;

  while(true){
    //At every loop, calculate shortest time first
    time = shortestTime();

    //Setup all the times
    offices[0].addIdleTime(time.getTime());
    offices[1].addIdleTime(time.getTime());
    offices[2].addIdleTime(time.getTime());
    offices[0].headChangeTime(time.getTime());
    offices[1].headChangeTime(time.getTime());
    offices[2].headChangeTime(time.getTime());

    //Add students to open windows in each office
    if (!offices[0].isLineEmpty() && offices[0].windowOpen()){
      offices[0].removeFromQueue();
    }
    if (!offices[1].isLineEmpty() && offices[1].windowOpen()){
      offices[1].removeFromQueue();
    }
    if (!offices[2].isLineEmpty() && offices[2].windowOpen()){
      offices[2].removeFromQueue();
    }

    //Use this as a dot product type integer where 1 is if the student is done and 0 if they need to continue
    int allDone = 0;
    for(int j = 0; j < customerNum; ++j){
      if (students[j].getPosition() > 2){
        allDone = 1;
      }
      else{
        allDone = 0;
        break;
      }
    }
    if (allDone == 1){
      break;
    }

    //Loop through the students and check the previous office and send the student to the next appropriate one
    for (int h = 0; h < numOfStudents; ++h){
      //Check a few things to make sure they're in the right place
      if (!students[h].getIsInLine() && students[h].getPosition() < 3 && students[h].getPreviousOffice() == 'C'){
        if (students[h].getOffice() == 'R'){
          //Add that student to the queue
          offices[0].addToQueue(students[h]);
          if (offices[0].windowOpen()){
            //If there is an open window, add the student at the front of the queue to it
            offices[0].removeFromQueue();
          }
        }
        //Continue till we hit the appropriate office
        else if (students[h].getOffice() == 'C'){
          offices[1].addToQueue(students[h]);
          if (offices[1].windowOpen()){
            offices[1].removeFromQueue();
          }
        }
        else if (students[h].getOffice() == 'F'){
          offices[2].addToQueue(students[h]);
          if (offices[2].windowOpen()){
            offices[2].removeFromQueue();
          }
        }
      }
    }

    for (int h = 0; h < numOfStudents; ++h){
      if (!students[h].getIsInLine() && students[h].getPosition() < 3 && students[h].getPreviousOffice() == 'F'){
        if (students[h].getOffice() == 'R'){
          offices[0].addToQueue(students[h]);
          if (offices[0].windowOpen()){
            offices[0].removeFromQueue();
          }
        }
        else if (students[h].getOffice() == 'C'){
          offices[1].addToQueue(students[h]);
          if (offices[1].windowOpen()){
            offices[1].removeFromQueue();
          }
        }
        else if (students[h].getOffice() == 'F'){
          offices[2].addToQueue(students[h]);
          if (offices[2].windowOpen()){
            offices[2].removeFromQueue();
          }
        }
      }
    }

    for (int h = 0; h < numOfStudents; ++h){
      if (!students[h].getIsInLine() && students[h].getPosition() < 3 && students[h].getPreviousOffice() == 'R'){
        if (students[h].getOffice() == 'R'){
          offices[0].addToQueue(students[h]);
          if (offices[0].windowOpen()){
            offices[0].removeFromQueue();
          }
        }
        else if (students[h].getOffice() == 'C'){
          offices[1].addToQueue(students[h]);
          if (offices[1].windowOpen()){
            offices[1].removeFromQueue();
          }
        }
        else if (students[h].getOffice() == 'F'){
          offices[2].addToQueue(students[h]);
          if (offices[2].windowOpen()){
            offices[2].removeFromQueue();
          }
        }
      }
    }

  }
}

/*
Name Of Function: getMeanWaitData

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::getMeanWaitData(){
  double register_time = 0;
  double cashier_time = 0;
  double fa_time = 0;
  for(int i = 0; i < numOfStudents; ++i){
    for (int j = 0; j < 3; ++j){
      if (students[i].getSpecificOffice(j) == 'R'){
        register_time += students[i].getWaitTime(j);
      }
      else if (students[i].getSpecificOffice(j) == 'C'){
        cashier_time += students[i].getWaitTime(j);
      }
      else if (students[i].getSpecificOffice(j) == 'F'){
        fa_time += students[i].getWaitTime(j);
      }
    }
  }
  cout << "Mean Student Wait Times" << endl;
  cout << "Register: " << register_time/numOfStudents  << endl;
  cout << "Cashier: " << cashier_time/numOfStudents  << endl;
  cout << "Financial Aid: " << fa_time/numOfStudents  << endl;
}

/*
Name Of Function: getLongestWaitData

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::getLongestWaitData(){ 
  int register_longest = 0;
  int cashier_longest = 0;
  int fa_longest = 0;
  for(int i = 0; i < numOfStudents; ++i){
    for (int j = 0; j < 3; ++j){
      if (students[i].getSpecificOffice(j) == 'R'){
        if (students[i].getWaitTime(j) > register_longest){
          register_longest = students[i].getWaitTime(j);
        }
      }
      else if (students[i].getSpecificOffice(j) == 'C'){
        if (students[i].getWaitTime(j) > cashier_longest){
          cashier_longest = students[i].getWaitTime(j);
        }
      }
      else if (students[i].getSpecificOffice(j) == 'F'){
        if (students[i].getWaitTime(j) > fa_longest){
          fa_longest = students[i].getWaitTime(j);
        }
      }
    }
  }
  cout << "Longest Student Wait Times:" << endl;
  cout << "Register: " << register_longest  << endl;
  cout << "Cashier: " << cashier_longest  << endl;
  cout << "Financial Aid: " << fa_longest  << endl;
}

/*
Name Of Function: getOverTenMinData

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::getOverTenMinData(){ 
  int longWait = 0;
  for(int i = 0; i < numOfStudents; ++i){
    if (students[i].waitedTenMin()){
      longWait += 1;
    }
  }
  cout << "Number of Students Who Waited Over 10 Minutes: " << longWait << endl;
}

/*
Name Of Function: getMeanIdleData

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::getMeanIdleData(){
  double register_idle = 0;
  double cashier_idle = 0;
  double fa_idle = 0;
  for(int i = 0; i < numWinRegister; ++i){
    register_idle += offices[0].getIdleTime(i);
  }
  for(int i = 0; i < numWinCashier; ++i){
    cashier_idle += offices[1].getIdleTime(i);
  }
  for(int i = 0; i < numWinFA; ++i){
    fa_idle += offices[2].getIdleTime(i);
  }
  cout << "Mean Window Idle Times" << endl;
  cout << "Register: " << register_idle/numWinRegister  << endl;
  cout << "Cashier: " << cashier_idle/numWinCashier  << endl;
  cout << "Financial Aide: " << fa_idle/numWinFA  << endl;
}

/*
Name Of Function: getLongestIdleData

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::getLongestIdleData(){ 
  int register_longest = 0;
  int cashier_longest = 0;
  int fa_longest = 0;
  for(int i = 0; i < numWinRegister; ++i){
    if (offices[0].getIdleTime(i) > register_longest){
      register_longest = offices[0].getIdleTime(i);
    }
  }
  for(int i = 0; i < numWinCashier; ++i){
    if (offices[1].getIdleTime(i) > cashier_longest){
      cashier_longest = offices[1].getIdleTime(i);
    }
  }
  for(int i = 0; i < numWinFA; ++i){
    if (offices[2].getIdleTime(i) > fa_longest){
      fa_longest = offices[2].getIdleTime(i);
    }
  }
  cout << "Longest Window Idle Times" << endl;
  cout << "Register: " << register_longest  << endl;
  cout << "Cashier: " << cashier_longest  << endl;
  cout << "Financial Aide: " << fa_longest  << endl;
}

/*
Name Of Function: getOverFiveMinData

Description of Value Returned: 

Description of Parameters:

Description of exceptions thrown: 
*/

void ServiceCenter::getOverFiveMinData(){
  int w = 0;
  w += offices[0].idleFiveMin();
  w += offices[1].idleFiveMin();
  w += offices[2].idleFiveMin();
  cout << "Number of Windows Idle for Over 5 Min: " << w << endl;
}
