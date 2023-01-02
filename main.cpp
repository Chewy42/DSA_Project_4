/*
Name: Matt Favela
Student ID #: 2390407
Email: mfavela@chapman.edu
Course Number and Section: CPSC350-03
Assignment: PA4

Brief Overview: This is the main file that also acts as a file processor. Then it will initiate the simulation, then when it finishes it will
print out the data

High Level Decisions Used:
A high level decision was using the .eof method to know when we reached the end of a file. This
helped when finding the number of students that we will need to address*/

#include <iostream>
#include <string>
#include <fstream>
#include "ListQueue.h"
#include "Customer.h"
#include "Window.h"
#include "Office.h"
#include "ServiceCenter.h"
using namespace std;

/*
Name Of Function: main

Description of Value Returned: 

Description of Parameters: integer argc which is the count of arguments and character pointer pointer which is the inputted command line values

Description of exceptions thrown: 
*/

int main(int argc, char** argv){

    /*
    Loop through file initially to get total number of students prepped for the SSC
    */
    std::string input = argv[1];
    ifstream file(input);
    int windows[3] = {0, 0, 0};
    std::string useless = "";
    int adding;
    int totalStudents = 0;

    for (int i = 0; i < 3; ++i){
        file >> windows[i];
    }

    file >> useless;

    while(!file.eof()){
        file >> adding;
        totalStudents += adding;
        for (int i = 0; i < (adding * 6) + 1; ++i){
        file >> useless;
        }
    }

    file.close();
    cout << "\b";

    /*
    Create the SSC with dedicated windows for each office along with the total students
    */
    ServiceCenter SSC(windows[0], windows[1], windows[2], totalStudents);


    ifstream file2(input);
    int studentNum;
    int studentTimes[3] = {0, 0, 0};
    char studentOffices[3] = {' ', ' ', ' '};

    /*
    First 4 lines of file are not needed now
    */
    for (int i = 0; i < 4; ++i){
        file2 >> useless;
    }

    /*
    Keep going till we hit the end of file error
    */
    while(!file2.eof()){
        file2 >> studentNum;
        for (int i = 0; i < studentNum; ++i){
            for(int j = 0; j < 3; ++j){
                file2 >> studentTimes[j];
            }
            for(int j = 0; j < 3; ++j){
                file2 >> studentOffices[j];
            }
            SSC.addStudent(studentTimes[0], studentTimes[1], studentTimes[2], studentOffices[0], studentOffices[1], studentOffices[2]);
        }

        /*
        Run the Simulation
        */
        SSC.Simulate();
        
        /*
        Discard the last line
        */
        file2 >> useless;
    }

    file2.close();

    //Calculate and output the data
    SSC.getMeanWaitData();
    SSC.getLongestWaitData();
    SSC.getOverTenMinData();
    SSC.getMeanIdleData();
    SSC.getLongestIdleData();
    SSC.getOverFiveMinData();
    return 0;
}