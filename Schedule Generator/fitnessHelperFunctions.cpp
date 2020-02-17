//
//  fitnessHelperFunctions.cpp
//  Schedule Generator
//
//  Created by Jimmy Blundell on 2/17/20.
//  Copyright © 2020 Jimmy Blundell. All rights reserved.
//

#include <string>
#include <map>
#include <vector>

#include "fitnessHelperFunctions.hpp"

using namespace std;

//Check if instructor is allowed to teach the course they are assigned
bool isValidInstructor(string instructor, string course)
{
    if (instructor == "Staff")
    {
        return true;
    }
    
    if ((instructor == "Hare") && (course == "CS 101" || course == "CS 201" || course == "CS 291" ||
                                   course == "CS 303" || course =="CS 449" || course == "CS 461"))
    {
        return true;
    }
    
    if ((instructor == "Bingham") && (course == "CS 101" || course == "CS 201"|| course == "CS 191" ||
                                      course == "CS 291" || course == "CS 449"))
    {
        return true;
    }
    
    if ((instructor == "Mitchell") && (course == "CS 191" || course == "CS 291" || course == "CS 303" ||
                                       course == "CS 341"))
    {
        return true;
    }
    
    if ((instructor == "Kuhail") && (course == "CS 303" || course == "CS 341"))
    {
        return true;
    }
    
    if ((instructor == "Rao") && (course == "CS 291" || course == "CS 303" || course == "CS 341" ||
                                  course == "CS 461"))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}
