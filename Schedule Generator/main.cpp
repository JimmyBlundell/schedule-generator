//
//  main.cpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/16/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "schedule.hpp"
#include "functions.hpp"
#include "fitnessHelperFunctions.hpp"

using namespace std;

int main()
{
    //Global variables to keep track of number of changes/attemps and fitness
    int successfulChanges = 0;
    int iterationsWithoutChange = 0;
    int iterations = 0;
    float t = 0.99;
    int fitness = 0;
    
    map<string, int> roomCapacityMap;
    initializeRoomCapacityMap(roomCapacityMap);
    
    vector<string> roomsVec;
    initializeRoomsVec(roomsVec);
    
    vector<string> instructorVec;
    initializeInstructorVec(instructorVec);
    
    vector<string> courseTimes;
    initializeCourseTimesVec(courseTimes);
    
    vector<Course> schedule;
    initializeScheduleVec(schedule, courseTimes, instructorVec, roomsVec);
    
    
    fitness = getFitness(schedule, roomCapacityMap, courseTimes);
    cout << fitness << endl;
    
    srand(time(NULL));
    
    // Loop, making random changes and testing new fitness
        while (successfulChanges <= 400 || iterations <= 4000)
        {
            if (iterationsWithoutChange == 4000)
            {
                break;
            }

            if (successfulChanges == 400 || iterations == 4000)
            {
                successfulChanges = 0;
                iterations = 0;
                t = t * 0.99;
            }
            
            int changeCourse = (rand() % schedule.size());
            
            int x = (rand() % 3) + 1;
            switch (x) {
                case 1:
                {
                    //instructor change
                    string temp = instructorVec[(rand() % instructorVec.size())];
                    string old = temp;
                    schedule[changeCourse].setInstructor(temp);
                    int oldFitness = fitness;
                    fitness = getFitness(schedule, roomCapacityMap, courseTimes);
                    if (fitness > oldFitness)
                    {
                        successfulChanges += 1;
                        iterationsWithoutChange = 0;
                        break;
                    }
                    else if (fitness < oldFitness)
                    {
                        //anneal
                        float p = ((double) rand() / (RAND_MAX));
                        int delta = oldFitness - fitness;
                        float x = exp(delta*-1/t);
                        if (p < x)
                        {
                            successfulChanges += 1;
                            iterationsWithoutChange = 0;
                            break;
                        }
                        else
                        {
                            iterationsWithoutChange++;
                            fitness = oldFitness;
                            schedule[changeCourse].setInstructor(old);
                            break;
                        }
                    }
                    else
                    {//???
                        schedule[changeCourse].setInstructor(old);
                        iterationsWithoutChange++;
                        break;
                    }
                }
                    
                case 2:
                {
                    //room change
                    string temp = roomsVec[(rand() % roomsVec.size())];
                    string old = temp;
                    schedule[changeCourse].setRoom(temp);
                    int oldFitness = fitness;
                    fitness = getFitness(schedule, roomCapacityMap, courseTimes);
                    if (fitness > oldFitness)
                    {
                        successfulChanges += 1;
                        iterationsWithoutChange = 0;
                        break;
                    }
                   else if (fitness < oldFitness)
                    {
                        //anneal
                        float p = ((double) rand() / (RAND_MAX));
                        int delta = oldFitness - fitness;
                        float x = exp(delta*-1/t);
                        if (p < x)
                        {
                            successfulChanges += 1;
                            iterationsWithoutChange = 0;
                            break;
                        }
                        else
                        {
                            iterationsWithoutChange++;
                            fitness = oldFitness;
                            schedule[changeCourse].setRoom(old);
                            break;
                        }
                    }
                    else
                    {
                        schedule[changeCourse].setRoom(temp);
                        iterationsWithoutChange++;
                        break;
                    }
                }
                    
                case 3:
                {
                    //time change
                    string temp = courseTimes[(rand() % courseTimes.size())];
                    string old = temp;
                    schedule[changeCourse].setTime(temp);
                    int oldFitness = fitness;
                    fitness = getFitness(schedule, roomCapacityMap, courseTimes);
                    if (fitness > oldFitness)
                    {
                        successfulChanges += 1;
                        iterationsWithoutChange = 0;
                        break;
                    }
                    else if (fitness < oldFitness)
                    {
                        //anneal
                        float p = ((double) rand() / (RAND_MAX));
                        int delta = oldFitness - fitness;
                        float x = exp((delta*-1/t));
                        if (p < x)
                        {
                            successfulChanges += 1;
                            iterationsWithoutChange = 0;
                            break;
                        }
                        else
                        {
                            iterationsWithoutChange++;
                            fitness = oldFitness;
                            schedule[changeCourse].setTime(old);
                            break;
                        }
                    }
                    
                    else
                    {
                        iterationsWithoutChange++;
                        schedule[changeCourse].setTime(old);
                        break;
                    }
                }
                default:
                {
                    break;
                }
            }
            iterations++;
        }
    
    printSchedule(schedule);
    cout << fitness << endl;
    
    return 0;
}
