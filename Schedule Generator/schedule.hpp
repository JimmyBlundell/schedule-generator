//
//  schedule.hpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/16/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#ifndef schedule_hpp
#define schedule_hpp

#include <stdio.h>
#include <map>
#include "fitnessHelperFunctions.hpp"

#endif /* schedule_hpp */



using namespace std;


class Course
{
private:
    string name;
    string time;
    string instructor;
    string room;
    
    int expectedEnrollment;
    
    
public:
    Course(string name, int expectedEnrollment);
    
    void setName(string name);
    void setTime(string time);
    void setInstructor(string instructor);
    void setRoom(string room);
    void setExpectedEnrollment(int expected);
    void setFitness(int fitness);
    
    string getName();
    string getTime();
    string getInstructor();
    string getRoom();
    
    int getExpectedEnrollment();
};

void initializeScheduleVec(vector<Course> &schedule, vector<string> &courseTimes, vector<string> &instructorVec, vector<string> &roomsVec);

void printSchedule(vector<Course> &vec);

int getFitness(vector<Course> &vec, map<string, int> &roomCapacityMap, vector<string> &courseTimes);

