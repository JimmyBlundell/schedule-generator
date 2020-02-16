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

#endif /* schedule_hpp */



using namespace std;


class Schedule
{
private:
    string name;
    string time;
    string instructor;
    string room;
    
    int expectedEnrollment;
    int fitness;
    
    
public:
    Schedule(string name, int expectedEnrollment);
    
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
    int getFitness();
};

