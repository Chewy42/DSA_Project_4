/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This file defines the Service Center class along with the methods and data we will need

High Level Decisions Used:
*/

#ifndef SERVICE_CENTER_H
#define SERVICE_CENTER_H

#include "Customer.h"
#include "Window.h"
#include "Office.h"
#include <cstdlib>
#include <iostream>

using namespace std;

class ServiceCenter{
    public:
    ServiceCenter();
    ServiceCenter(int num_windows_reg, int num_windows_cash, int num_windows_fin, int num_students);
    ~ServiceCenter();
    void addStudent(int studentTimes0, int studentTimes1, int studentTimes2, char office0, char office1, char office2);
    void locate(Customer s);
    Customer shortestTime();
    void Simulate();
    void getMeanWaitData();
    void getLongestWaitData();
    void getOverTenMinData();
    void getMeanIdleData();
    void getLongestIdleData();
    void getOverFiveMinData();
    private:
    int numWinRegister;
    int numWinCashier;
    int numWinFA;
    int numOfStudents; 
    int customerNum;
    Customer* students;
    Office* offices;
    };

#endif