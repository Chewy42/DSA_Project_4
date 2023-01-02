/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview:
This file defines the Customer class

High Level Decisions Used:
None
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <cstdlib>
#include <iostream>


using namespace std;

class Customer{
    public:
    Customer();
  Customer(int i);
  ~Customer();
    int getTime();
    void setTime(int index, int t);
    void changeTime(int t);
    char getOffice();
    char getPreviousOffice();
    void setOffice(int index, char office);
    char getSpecificOffice(int index);
    int getWaitTime(int index);
    void setWaitTime(int timeWaited);
    bool waitedTenMin();
    int getNum();
    void setNum(int n);
    void incrementPosition();
    int getPosition();
    void setIsInLine(bool l);
    bool getIsInLine();
    private:
    int num;
    int time[3] = {0, 0, 0};
    char officesVisited[3] = {' ', ' ', ' '};
    int wait_times[3] = {0, 0, 0};
    int position = 0;
    bool isInLine;
};

#endif