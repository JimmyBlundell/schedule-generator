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
#include "schedule.hpp"
#include "functions.hpp"

using namespace std;

int main()
{
    //Global variables to keep track of number of changes and number of attempts. Determines when program stops.
    int successfulChanges = 0;
    int numberAttempts = 0;
    
    map<string, int> roomCapacityMap;
    initializeRoomCapacityMap(roomCapacityMap);
    
    vector<string> instructorVec;
    initializeInstructorVec(instructorVec);
    
    vector<string> courseTimes;
    initializeCourseTimesVec(courseTimes);
    
    //TODO: Big TODO for next time: we have tons of loops to check for each iteration to assess fitness. Consider making maps of instructors, classes, rooms, etc., of pair<string, bool>. When instructor is assigned, room is assigned, time slot is taken, or whatever, change bool available to false. Ask if this will make checks easier / code more readable.
    
    return 0;
}
