//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <string>
#include "NumericAnswer.h"
using namespace std;

NumericAnswer::NumericAnswer(string prompt2, int value2, string answer2, double margin)
    :ShortAnswer(prompt2,value2,answer2)
{
    allowableMargin = margin;
}
bool NumericAnswer::validate(){
    if(allowableMargin < 0)
        return false;
    else
        return true;
}
double NumericAnswer::scoreAnswer(string answer) const
{
    double answer1 = stof(answer);
    double correctAnswer1 = stoi(ShortAnswer::getCorrectAnswer());
    double calcMargin = abs(answer1-correctAnswer1);
    if(calcMargin <= allowableMargin)
        return Question::getPointValue();
    else
        return 0;

}
