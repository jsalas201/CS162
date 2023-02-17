//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef SHORTANSWER_H
#define SHORTANSWER_H
#include <iostream>
#include <string>
#include "Question.h"
using namespace std;

class ShortAnswer: public Question
{
private:
    string correctAnswer;
public:
    ShortAnswer(string prompt1, int value1, string answer1);

    bool validate();

    double scoreAnswer(string answer)const;

    string getCorrectAnswer()const;
};
#endif // SHORTANSWER_H
