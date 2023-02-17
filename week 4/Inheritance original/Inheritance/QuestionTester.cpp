//----------------------------------------------------------
// CS162 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

//Bring in unit testing code and tell it to build a main function
//If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

//This pragma supresses a bunch of warnings QTCreator produces (and should not)
#pragma clang diagnostic ignored "-Woverloaded-shift-op-parentheses"

//Hide some false warnings - this is supposed to look commented out
// clazy:skip

//Tell clang analyzer to ignore doctest.h
#ifndef __clang_analyzer__
#include "doctest.h"
#endif

//Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include "Question.h"
#include "ShortAnswer.h"
#include "NumericAnswer.h"
#include "MultipleChoice.h"

using namespace std;

 TEST_CASE("ShortAnswer") {
     cout << "1: ShortAnswer" << endl;
     ShortAnswer q1("Chemeketa Community _", 2, "College");
     CHECK(q1.getPointValue() == 2);
     CHECK(q1.getText() == "Chemeketa Community _ (2 pts)");
     CHECK(q1.getCorrectAnswer() == "College");
     //To compile, you also will need to make sure there is a scoreAnswer(string) function for ShortAnswer
     //It does not have to work correctly yet - it can just return 0
 }

 TEST_CASE("ShortAnswer as Question") {
     cout << "2: ShortAnswer" << endl;
     ShortAnswer q1("What month is Thanksgiving in?", 10, "November");
     Question* p = &q1;
     CHECK(p->getPointValue() == 10);
     CHECK(p->getText() == "What month is Thanksgiving in? (10 pts)");
 }

 TEST_CASE("ShortAnswer validate") {
     cout << "3a: ShortAnswer validate" << endl;
     ShortAnswer q1("What month is Thanksgiving in?", 10, "November");
     CHECK(q1.validate());

     ShortAnswer q2("", 10, "November");
     CHECK(!q2.validate());
 }

 TEST_CASE("ShortAnswer validate as question") {
     cout << "3b: ShortAnswer validate as question" << endl;
     ShortAnswer q1("What month is Thanksgiving in?", 10, "November");
     CHECK(q1.validate());

     ShortAnswer q2("What month is Thanksgiving in?", 10, "");
     CHECK(!q2.validate());

     ShortAnswer q3("", 10, "November");
     Question* p = &q3;
     CHECK(!p->validate());
 }

 TEST_CASE("ShortAnswer score") {
     cout << "4a: ShortAnswer score" << endl;
     ShortAnswer q1("What month is Thanksgiving in?", 8, "November");
     CHECK(q1.scoreAnswer("November") == Approx(8));
     CHECK(q1.scoreAnswer("november") == Approx(0));
     CHECK(q1.scoreAnswer("") == Approx(0));
 }

 TEST_CASE("ShortAnswer score as Question") {
     cout << "4a: ShortAnswer score as Question" << endl;
     ShortAnswer q1("What month is Thanksgiving in?", 4, "November");
     Question* p = &q1;
     CHECK(p->scoreAnswer("November") == Approx(4));
     CHECK(p->scoreAnswer("november") == Approx(0));
 }


 TEST_CASE("NumericAnswer") {
     cout << "5: NumericAnswer" << endl;
     NumericAnswer q1("3 + 2", 1, "5", 0);
     CHECK(q1.getPointValue() == 1);
     CHECK(q1.getText() == "3 + 2 (1 pts)");
     CHECK(q1.getCorrectAnswer() == "5");
 }

 TEST_CASE("NumericAnswer score") {
     cout << "6: NumericAnswer score" << endl;
     NumericAnswer q1("3 + 2", 1, "5", 0);
     CHECK(q1.scoreAnswer("5") == Approx(1));
     CHECK(q1.scoreAnswer("5.000001") == Approx(0));

     NumericAnswer q2("sqrt(2)", 4, "1.414", 0.005);
     CHECK(q2.scoreAnswer("1.414") == Approx(4));
     CHECK(q2.scoreAnswer("1.41") == Approx(4));
     CHECK(q2.scoreAnswer("1.42") == Approx(0));
     CHECK(q2.scoreAnswer("1.4") == Approx(0));
 }

 TEST_CASE("NumericAnswer validate") {
     cout << "7: NumericAnswer validate" << endl;
     NumericAnswer q1("3 + 2", 1, "5", 0);
     CHECK(q1.validate());

     NumericAnswer q2("3 + 2", 1, "5", -10);
     CHECK(!q2.validate());
 }

 TEST_CASE("NumericAnswer as ShortAnswer") {
     cout << "8a: NumericAnswer as ShortAnswer" << endl;
     NumericAnswer q1("3 + 2", 1, "5", 0);
     ShortAnswer* p = &q1;

     CHECK(p->getCorrectAnswer() == "5");
 }

 TEST_CASE("NumericAnswer as Question") {
     cout << "8b: NumericAnswer as Question" << endl;
     NumericAnswer q1("3 + 2", 1, "5", 0);
     Question* p = &q1;

     CHECK(p->getPointValue() == 1);
     CHECK(p->getText() == "3 + 2 (1 pts)");
 }


// TEST_CASE("MultipleChoice") {
//     cout << "9a: MultipleChoice" << endl;
//     MultipleChoice q1("Select the mammal", 5, "B");
//     CHECK(q1.getPointValue() == 5);
// }

// TEST_CASE("MultipleChoice setOption") {
//     cout << "9b: MultipleChoice" << endl;
//     MultipleChoice q1("Select the mammal", 5, "B");

//     q1.setOption(0, "Shark");
//     q1.setOption(1, "Dolphin");
//     q1.setOption(2, "Eel");
//     q1.setOption(3, "Squid");

//     string correctText = "Select the mammal (5 pts)\nA: Shark\nB: Dolphin\nC: Eel\nD: Squid";

//     CHECK(q1.getText() == correctText);
// }

 TEST_CASE("MultipleChoice as Question") {
     cout << "9c: MultipleChoice" << endl;
     MultipleChoice q1("Select the mammal", 5, "B");
     Question* p = &q1;

     CHECK(p->getPointValue() == 5);
     CHECK(p->getText() == "Select the mammal (5 pts)\nA: \nB: \nC: \nD: ");
 }


 TEST_CASE("MultipleChoice validate") {
     cout << "10a: MultipleChoice validate" << endl;
     MultipleChoice q1("Select the mammal", 5, "B");
     CHECK(q1.validate());

     MultipleChoice q2("Select the mammal", 5, "");
     CHECK(!q2.validate());

     MultipleChoice q3("Select the fruit", 5, "AC");
     CHECK(q3.validate());

     MultipleChoice q4("Select the fruit", -1, "AC");
     CHECK(!q4.validate());

     MultipleChoice q5("", 5, "AC");
     CHECK(!q5.validate());
 }

 TEST_CASE("MultipleChoice validate as Question") {
     cout << "10b: MultipleChoice validate as Question" << endl;
     MultipleChoice q1("Select the mammal", 5, "B");
     Question* p1 = &q1;
     CHECK(p1->validate());

     MultipleChoice q2("Select the mammal", 5, "");
     Question* p2 = &q2;
     CHECK(!p2->validate());
 }


 TEST_CASE("MultipleChoice scoreAnswer") {
     cout << "11a: MultipleChoice scoreAnswer" << endl;
     MultipleChoice q1("Select the mammal", 5, "B");
     CHECK(q1.scoreAnswer("B") == Approx(5));
     CHECK(q1.scoreAnswer("BC") == Approx(0));
     CHECK(q1.scoreAnswer("C") == Approx(0));
 }

 TEST_CASE("MultipleChoice scoreAnswer partial") {
     cout << "11b: MultipleChoice scoreAnswer partial" << endl;
     MultipleChoice q1("Select the mammals", 6, "ABC");
     CHECK(q1.scoreAnswer("B") == Approx(2));
     CHECK(q1.scoreAnswer("C") == Approx(2));
     CHECK(q1.scoreAnswer("BCD") == Approx(2));
     CHECK(q1.scoreAnswer("BC") == Approx(4));
     CHECK(q1.scoreAnswer("ABC") == Approx(6));
     CHECK(q1.scoreAnswer("ABCD") == Approx(4));
     CHECK(q1.scoreAnswer("AD") == Approx(0));
     CHECK(q1.scoreAnswer("") == Approx(0));
 }

 TEST_CASE("MultipleChoice scoreAnswer as Question") {
     cout << "11c: MultipleChoice scoreAnswer as Question" << endl;
     MultipleChoice q1("Select the ex-Presidents", 4, "AB");
     Question* p = &q1;

     CHECK(p->scoreAnswer("B") == Approx(2));
     CHECK(p->scoreAnswer("BD") == Approx(0));
 }

