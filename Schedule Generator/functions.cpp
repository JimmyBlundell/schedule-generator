//
//  functions.cpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/16/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <map>
#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
#include <algorithm>

#include "functions.hpp"
#include "schedule.hpp"

using namespace std;

void initializeRoomCapacityMap(map<string, int> &myMap)
{
    myMap.insert(pair<string, int>("Haag 301", 70));
    myMap.insert(pair<string, int>("Haag 201", 30));
    myMap.insert(pair<string, int>("Royall 204", 70));
    myMap.insert(pair<string, int>("Katz 209", 50));
    myMap.insert(pair<string, int>("Flarsheim 310", 80));
    myMap.insert(pair<string, int>("Flarsheim 260", 25));
    myMap.insert(pair<string, int>("Bloch 0009", 30));
}


void initializeInstructorVec(vector<string> &vec)
{
    vec.push_back("Hare");
    vec.push_back("Bingham");
    vec.push_back("Mitchell");
    vec.push_back("Kuhail");
    vec.push_back("Rao");
    vec.push_back("Staff");
}

void initializeCourseTimesVec(vector<string> &vec)
{
    vec.push_back("10A");
    vec.push_back("11A");
    vec.push_back("12P");
    vec.push_back("1P");
    vec.push_back("2P");
    vec.push_back("3P");
    vec.push_back("4P");
}

void initializeRoomsVec(vector<string> &vec)
{
    vec.push_back("Haag 201");
    vec.push_back("Haag 301");
    vec.push_back("Royall 204");
    vec.push_back("Katz 209");
    vec.push_back("Flarsheim 260");
    vec.push_back("Flarsheim 310");
    vec.push_back("Bloch 0009");
}

