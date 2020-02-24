//
//  schedule.cpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/16/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "schedule.hpp"

using namespace std;


//Constructor
Course::Course(string name, int expectedEnrollment)
{
    this->name = name;
    this->expectedEnrollment = expectedEnrollment;
}

//Setters
void Course::setName(string name)
{
    this->name = name;
}

void Course::setTime(string time)
{
    this->time = time;
}

void Course::setInstructor(string instructor)
{
    this->instructor = instructor;
}

void Course::setRoom(string room)
{
    this->room = room;
}

void Course::setExpectedEnrollment(int expected)
{
    this->expectedEnrollment = expected;
}



//Getters
string Course::getName()
{
    return this->name;
}

string Course::getTime()
{
    return this->time;
}

string Course::getInstructor()
{
    return this->instructor;
}

string Course::getRoom()
{
    return this->room;
}

int Course::getExpectedEnrollment()
{
    return this->expectedEnrollment;
}

void initializeScheduleVec(vector<Course> &schedule, vector<string> &courseTimes, vector<string> &instructorVec, vector<string> &roomsVec)
{
     Course cs101a("CS 101A", 40);
     schedule.push_back(cs101a);
     Course cs101b("CS 101B", 25);
     schedule.push_back(cs101b);
     Course cs201a("CS 201A", 30);
     schedule.push_back(cs201a);
     Course cs201b("CS 201B", 30);
     schedule.push_back(cs201b);
     Course cs191a("CS 191A", 60);
     schedule.push_back(cs191a);
     Course cs191b("CS 191B", 20);
     schedule.push_back(cs191b);
     Course cs291a("CS 291A", 20);
     schedule.push_back(cs291a);
     Course cs291b("CS 291B", 40);
     schedule.push_back(cs291b);
     Course cs303("CS 303", 50);
     schedule.push_back(cs303);
     Course cs341("CS 341", 40);
     schedule.push_back(cs341);
     Course cs449("CS 449", 55);
     schedule.push_back(cs449);
     Course cs461("CS 461", 40);
     schedule.push_back(cs461);
    
    srand(time(NULL));
    
    for (int i = 0; i < schedule.size(); i++)
     {
         string instructor = instructorVec[(rand() % instructorVec.size())];
         string room = roomsVec[(rand() % roomsVec.size())];
         string time = courseTimes[(rand() % courseTimes.size())];
         schedule[i].setInstructor(instructor);
         schedule[i].setRoom(room);
         schedule[i].setTime(time);
     }
    
}


void printSchedule(vector<Course> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
     
        cout << "Class: " << vec[i].getName() << endl;
        cout << "Instructor: " << vec[i].getInstructor() << endl;
        cout << "Room: " << vec[i].getRoom() << endl;
        cout << "Time: " << vec[i].getTime() << endl;
        cout << "------------------" << endl;
        
    }
}
