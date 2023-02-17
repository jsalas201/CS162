//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef NUMERICANSWER_H
#define NUMERICANSWER_H
#include <iostream>
#include <string>
#include "ShortAnswer.h"
using namespace std;

class NumericAnswer : public ShortAnswer
{
private:
    double allowableMargin;
public:
    NumericAnswer( string prompt2, int value2, string answer2, double margin);
    bool validate();
    double scoreAnswer(string answer) const;
};
#endif // NUMERICANSWER_H
