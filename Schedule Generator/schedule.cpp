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
#include <map>
#include <iostream>
#include "schedule.hpp"
#include "functions.hpp"

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

int getFitness(vector<Course> &vec, map<string, int> &roomCapacityMap, vector<string> &courseTimes)
{
    int fitness = 0;
    
    //check for valid instructors
    for (int i = 0; i < vec.size(); i++)
    {
        if (isValidInstructor(vec[i].getInstructor(), vec[i].getName()))
        {
            fitness += 3;
        }
    }
    
    
    //check for courses taught by staff
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].getInstructor() == "Staff")
        {
            fitness += 1;
        }
    }
    
    
    //Check to make sure course is only course scheduled in that room at that time
    int j = 0;
    while (j < vec.size())
    {
        for (int i = 0; i <= vec.size(); i++)
        {
            //Reach end of loop, so no conflicts. Increment fitness
            if (i == vec.size())
            {
                j++;
                fitness += 5;
                break;
            }
            
            //Don't check course against itself - Does this continue next iteration of loop?
            if (i == j)
            {
                continue;
            }
            
            if ((vec[i].getRoom() == vec[j].getRoom()) && (vec[i].getTime() == vec[j].getTime()))
            {
                j++;
                break;
            }
        }
    }
    
    
    //Check room capacity vs expected enrollment
    for (int i = 0; i < vec.size(); i++)
    {
        auto itr = roomCapacityMap.find(vec[i].getRoom());
        if (itr->second >= vec[i].getExpectedEnrollment())
        {
            fitness += 5;
            if ((vec[i].getExpectedEnrollment() * 2) <= itr->second)
            {
                fitness += 2;
            }
        }
    }
    
    //reset j counter used before
    j = 0;
    while (j < vec.size())
    {
        for (int i = 0; i <= vec.size(); i++)
        {
            //Reach end of loop, so no conflicts. Increment j and fitness
            if (i == vec.size())
            {
                j++;
                fitness += 5;
                break;
            }
            
            //Don't check course against itself
            if (i == j)
            {
                continue;
            }
            
            if ((vec[i].getInstructor() == vec[j].getInstructor()) && (vec[i].getTime() == vec[j].getTime()))
            {
                j++;
                break;
            }
        }
    }
    
    map<string, int> numCourses;
    
    //Check # schedules each instructor is teaching
    for (int i = 0; i <= vec.size(); i++)
    {
        //Finished looping through, so compare numbers for Hare, Bingham, Mitchell, and Rao
        if (i == vec.size())
        {
            auto hare = numCourses.find("Hare");
            auto bingham = numCourses.find("Bingham");
            auto mitchell = numCourses.find("Mitchell");
            auto rao = numCourses.find("Rao");
            
            if ((mitchell->second > hare->second || mitchell->second > bingham->second ||
                rao->second > hare->second || rao->second > bingham->second))
            {
                fitness -= 10;
            }
            //End loop
            break;
        }
        
        auto itr = numCourses.find(vec[i].getInstructor());
        
        //Add instructor to our map
        if (itr == numCourses.end())
        {
            numCourses.insert(pair<string, int>(vec[i].getInstructor(), 1));
        }
        
        //Increment number of courses professor is teaching
        else
        {
            itr->second++;
            if (itr->second > 4)
            {
                fitness -= 5;
            }
        }
    }
    
    //Checks for 101A and 191A
    if (vec[0].getTime() == vec[4].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[0].getTime())
            {
                if (vec[4].getTime() == courseTimes[j-1] || vec[4].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[0].getRoom() == "Katz 209")
                    {
                        if (vec[4].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[4].getRoom() != "Katz 209" && vec[4].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[0].getRoom() == "Bloch 0009")
                    {
                        if (vec[4].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[4].getRoom() != "Bloch 0009" && vec[4].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                }
                break;
            }
        }
    }
    
    
    //Check 101b and 191b
    if (vec[1].getTime() == vec[5].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[1].getTime())
            {
                if (vec[5].getTime() == courseTimes[j-1] || vec[5].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[1].getRoom() == "Katz 209")
                    {
                        if (vec[5].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[5].getRoom() != "Katz 209" && vec[5].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[1].getRoom() == "Bloch 0009")
                    {
                        if (vec[5].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[5].getRoom() != "Bloch 0009" && vec[5].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                }
                break;
            }
        }
    }
    
    
    //check for 201a and 291a
    if (vec[2].getTime() == vec[6].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[2].getTime())
            {
                if (vec[6].getTime() == courseTimes[j-1] || vec[6].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[2].getRoom() == "Katz 209")
                    {
                        if (vec[6].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[6].getRoom() != "Katz 209" && vec[6].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[2].getRoom() == "Bloch 0009")
                    {
                        if (vec[6].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[6].getRoom() != "Bloch 0009" && vec[6].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                }
                break;
            }
        }
    }

    
    //check for 201b and 291b
    if (vec[3].getTime() == vec[7].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[3].getTime())
            {
                if (vec[7].getTime() == courseTimes[j-1] || vec[7].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[3].getRoom() == "Katz 209")
                    {
                        if (vec[7].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[7].getRoom() != "Katz 209" && vec[7].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[3].getRoom() == "Bloch 0009")
                    {
                        if (vec[7].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[7].getRoom() != "Bloch 0009" && vec[7].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                }
                break;
            }
        }
    }
    
    
    //Check 101a to 191b
    if (vec[0].getTime() == vec[5].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[0].getTime())
            {
                if (vec[5].getTime() == courseTimes[j-1] || vec[5].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                     if (vec[0].getRoom() == "Katz 209")
                       {
                           if (vec[5].getRoom() == "Bloch 0009")
                           {
                               fitness -= 6;
                           }
                           else if (vec[5].getRoom() != "Katz 209" && vec[5].getRoom() != "Bloch 0009")
                           {
                               fitness -= 3;
                           }
                           
                       }
                       if (vec[0].getRoom() == "Bloch 0009")
                       {
                           if (vec[5].getRoom() == "Katz 209")
                           {
                               fitness -= 6;
                           }
                           else if (vec[5].getRoom() != "Bloch 0009" && vec[5].getRoom() != "Katz 209")
                           {
                               fitness -= 3;
                           }
                       }
                }
                break;
            }
        }
    }
    
   
    
    //Check 101b to 191a
    if (vec[1].getTime() == vec[4].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[1].getTime())
            {
                if (vec[4].getTime() == courseTimes[j-1] || vec[4].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[1].getRoom() == "Katz 209")
                    {
                        if (vec[4].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[4].getRoom() != "Katz 209" && vec[4].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[1].getRoom() == "Bloch 0009")
                    {
                        if (vec[4].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[4].getRoom() != "Bloch 0009" && vec[4].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                }
                break;
            }
        }
    }
    
    
    
    //Check 201a to 291b
    if (vec[2].getTime() == vec[7].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[2].getTime())
            {
                if (vec[7].getTime() == courseTimes[j-1] || vec[7].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[2].getRoom() == "Katz 209")
                    {
                        if (vec[7].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[7].getRoom() != "Katz 209" && vec[7].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[2].getRoom() == "Bloch 0009")
                    {
                        if (vec[7].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[7].getRoom() != "Bloch 0009" && vec[7].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                }
                break;
            }
        }
    }
    
    
    
    //Check 201b to 291a
    if (vec[3].getTime() == vec[6].getTime())
    {
        fitness -= 15;
    }
    else //Check if adjacent time
    {
        for (int j = 0; j < courseTimes.size(); j++)
        {
            if (courseTimes[j] == vec[3].getTime())
            {
                if (vec[6].getTime() == courseTimes[j-1] || vec[6].getTime() == courseTimes[j+1])
                {
                    fitness += 5;
                    
                    if (vec[3].getRoom() == "Katz 209")
                    {
                        if (vec[6].getRoom() == "Bloch 0009")
                        {
                            fitness -= 6;
                        }
                        else if (vec[6].getRoom() != "Katz 209" && vec[6].getRoom() != "Bloch 0009")
                        {
                            fitness -= 3;
                        }
                        
                    }
                    if (vec[3].getRoom() == "Bloch 0009")
                    {
                        if (vec[6].getRoom() == "Katz 209")
                        {
                            fitness -= 6;
                        }
                        else if (vec[6].getRoom() != "Bloch 0009" && vec[6].getRoom() != "Katz 209")
                        {
                            fitness -= 3;
                        }
                    }
                    
                }
                break;
            }
        }
    }

    //Check times for 191a, 191b, 291a, and 291b
    for (int j = 0; j < courseTimes.size(); j++)
    {
        if (courseTimes[j] == vec[4].getTime())
        {
            for (int i = 0; i <= j-3; i++)
            {
                if (courseTimes[i] == vec[5].getTime())
                {
                    fitness += 5;
                }
            }
            for (int i = j+3; i < vec.size(); i++)
            {
                if (courseTimes[i] == vec[5].getTime())
                {
                    fitness += 5;
                }
            }
        }
    }
    
    for (int j = 0; j < courseTimes.size(); j++)
    {
        if (courseTimes[j] == vec[5].getTime())
        {
            for (int i = 0; i <= j-3; i++)
            {
                if (courseTimes[i] == vec[6].getTime())
                {
                    fitness += 5;
                }
            }
            for (int i = j+3; i < vec.size(); i++)
            {
                if (courseTimes[i] == vec[6].getTime())
                {
                    fitness += 5;
                }
            }
        }
    }
    
    
    
    
    
    return fitness;
}
