//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef MULTIPLECHOICE_H
#define MULTIPLECHOICE_H
#include <iostream>
#include <string>
#include "Question.h"
using namespace std;

class MultipleChoice :public Question{
private:
    string correctAnswer;
    string options[4];
public:
    MultipleChoice(string prompt3, int value3,string correctChoices);
    string getText();
    bool validate();
    void setOption(int index, string option);
    // could not figure out how to write this function, need help
    double scoreAnswer( string answer)const;
};

#endif // MULTIPLECHOICE_H
