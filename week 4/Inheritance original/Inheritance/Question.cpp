//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <string>
#include "Question.h"
using namespace std;

Question::Question(string promptStr, int Value)
{
    prompt = promptStr;
    pointValue = Value;
};
int Question::getPointValue()const{
    return pointValue;
}
string Question::getText()
{
    return prompt + " (" + to_string(pointValue) + " pts)" ;
};
bool Question::validate()
{
    if(prompt == "" && pointValue < 0)
        return false;
    else
        return true;
};

