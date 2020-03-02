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
    /* - May not need this, check for staff separately
    if (instructor == "Staff")
    {
        return true;
    }
    */
    
    if ((instructor == "Hare") && (course == "CS 101A" || course == "CS 101B" || course == "CS 201A" ||
                                   course == "CS 201B" || course == "CS 291A" || course == "CS 291B" ||
                                   course == "CS 303" || course =="CS 449" || course == "CS 461"))
    {
        return true;
    }
    
    if ((instructor == "Bingham") && (course == "CS 101A" || course == "CS 101B" || course == "CS 201A" || course == "CS 201B" ||
                                      course == "CS 191A" || course == "CS 191B" || course == "CS 291A" || course == "CS 291B" ||
                                      course == "CS 449"))
    {
        return true;
    }
    
    if ((instructor == "Mitchell") && (course == "CS 191A" || course == "CS 191BA" || course == "CS 291A" || course == "CS 291B" ||
                                       course == "CS 303" || course == "CS 341"))
    {
        return true;
    }
    
    if ((instructor == "Kuhail") && (course == "CS 303" || course == "CS 341"))
    {
        return true;
    }
    
    if ((instructor == "Rao") && (course == "CS 291A" || course == "CS 291B" || course == "CS 303" || course == "CS 341" ||
                                  course == "CS 461"))
    {
        return true;
    }
    
    else
    {
        return false;
    }
}

