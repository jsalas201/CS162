//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;
#include "MultipleChoice.h"

MultipleChoice::MultipleChoice(string prompt3, int value3,string correctChoices)
:Question(prompt3,value3)
{
    correctAnswer = correctChoices;
}
void MultipleChoice::setOption(int index, string option){
    options[index]= option;
}
string MultipleChoice::getText(){
    return Question::getText() + '\n'
            + "A: " + options[0] + '\n'
            + "B: " + options[0] + '\n'
            + "C: " + options[0] + '\n'
            + "D: " + options[0] + '\n';
}

bool MultipleChoice::validate(){
    if(correctAnswer == "")
        return false;
    else
        return true;
}
double MultipleChoice::scoreAnswer(string answer)const{
    double answer1 = stof(answer);
    return answer1;
}
