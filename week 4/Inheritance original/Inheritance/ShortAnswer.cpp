//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <string>
#include "ShortAnswer.h"
using namespace std;


ShortAnswer::ShortAnswer(string prompt1, int value1, string answer1)
    :Question(prompt1,value1)
{
    correctAnswer = answer1;
};

bool ShortAnswer::validate()
{
    if(correctAnswer.empty())
        return false;
    else
        return true;
};
string ShortAnswer::getCorrectAnswer() const{
    return correctAnswer;
}
double ShortAnswer::scoreAnswer(string answer) const{
    if(answer == correctAnswer)
        return Question::getPointValue();
    else
        return 0;
}
