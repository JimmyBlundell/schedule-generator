//
//  functions.hpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/16/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
/*#include <map>
#include <vector>
#include <string>
#include <set>
#include <iostream>
 */
using namespace std;

#endif /* functions_hpp */

void initializeRoomCapacityMap(map<string, int> &myMap);


void initializeInstructorVec(vector<string> &vec);


void initializeCourseTimesVec(vector<string> &vec);


bool isValidInstructor(string instructor, string course);

