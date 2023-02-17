//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
using namespace std;

class Question {
private:
    string prompt;
    int pointValue;

public:
    Question(string promptStr, int Value);
    int getPointValue()const;
    string getText();
    bool validate();
    virtual double scoreAnswer(string answer) const = 0;
};

#endif // QUESTION_H
