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
    int numberIterationsWithoutChange = 0;
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
    
    
    
    //For test purposes
    printSchedule(schedule);
    
    fitness += getFitness(schedule, roomCapacityMap, courseTimes);
    cout << fitness << endl;
    
 
    
    return 0;
}
