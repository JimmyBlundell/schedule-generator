//
//  schedule.cpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/16/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <stdio.h>
#include <string>
#include "schedule.hpp"

using namespace std;


//Constructor
Schedule::Schedule(string name, int expectedEnrollment)
{
    this->name = name;
    this->expectedEnrollment = expectedEnrollment;
}

//Setters
void Schedule::setName(string name)
{
    this->name = name;
}

void Schedule::setTime(string time)
{
    this->time = time;
}

void Schedule::setInstructor(string instructor)
{
    this->instructor = instructor;
}

void Schedule::setRoom(string room)
{
    this->room = room;
}

void Schedule::setExpectedEnrollment(int expected)
{
    this->expectedEnrollment = expected;
}

void Schedule::setFitness(int fitness)
{
    this->fitness = fitness;
}


//Getters
string Schedule::getName()
{
    return this->name;
}

string Schedule::getTime()
{
    return this->time;
}

string Schedule::getInstructor()
{
    return this->instructor;
}

string Schedule::getRoom()
{
    return this->room;
}

int Schedule::getExpectedEnrollment()
{
    return this->expectedEnrollment;
}

int Schedule::getFitness()
{
    return this->fitness;
}
