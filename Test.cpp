#include "doctest.h"
#include "snowman.hpp"
#include <stdlib.h>


using namespace std;
using namespace ariel;

//Hats

#define STRAW_HAT "     \n_===_\n"
#define MEXICAN_HAT " ___ \n.....\n"
#define FEZ "  _  \n /_\\ \n"
#define RUSSIAN_HAT " ___ \n(_*_)\n"

//Noses

#define NORMAL ","
#define DOT_NOSE "."
#define LINE "_"
#define NONE " "

//Eyes

#define DOT_EYE "."
#define BIGGER_DOT "o"
#define BIGGEST_DOT "O"
#define CLOSED "-"

//Left arm

#define NORMAL_LEFT_ARM ">"
#define UPWARDS_LEFT_ARM "/"
#define DOWNWARDS_LEFT_ARM "\\"
#define NONE_ARM " "

//Right arm

#define NORMAL_RIGHT_ARM "<"
#define UPWARDS_RIGHT_ARM "\\"
#define DOWNWARDS_RIGHT_ARM "/"


//Torso

#define BUTTONS " : "
#define VEST "] ["
#define INWARD_ARMS "> <"
#define NONE_TORSO_AND_BASE "   "

//Base

#define FEET "\" \""
#define FLAT "___"

string nospaces(string input) {
    erase(input, ' ');
    erase(input, '\t');
    erase(input, '\n');
    erase(input, '\r');
    return input;
}

TEST_CASE ("Testing throws") {
    CHECK_THROWS(snowman(444444445));
    CHECK_THROWS(snowman(-111111111));
    CHECK_THROWS(snowman(-23232323));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(12310123));
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(12312310));
    CHECK_THROWS(snowman(01231231));
    CHECK_THROWS(snowman(01231231));
    CHECK_THROWS(snowman(-2));
    CHECK_THROWS(snowman(-555));
    CHECK_THROWS(snowman(555));
    CHECK_THROWS(snowman(51111111));
    CHECK_THROWS(snowman(15111111));
    CHECK_THROWS(snowman(11511111));
    CHECK_THROWS(snowman(11151111));
    CHECK_THROWS(snowman(11115111));
    CHECK_THROWS(snowman(11111511));
    CHECK_THROWS(snowman(11111151));
    CHECK_THROWS(snowman(11111115));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(2));
    CHECK_THROWS(snowman(3));
}


TEST_CASE ("Testing all possible outcomes") {
    for (int a = 0; a < 20000; ++a) { // testing 20,000 tests, it is possible to make this number even
        int i, j, k, l, m, n, i1, j1; // higher but time is factor, could even test 65536 tests.
        i = rand() % 4 + 1;           // it is even possible to store the sequence number in an array and
        j = rand() % 4 + 1;           // run all possible scenarios, but it is wasteful.
        k = rand() % 4 + 1;
        l = rand() % 4 + 1;
        m = rand() % 4 + 1;
        n = rand() % 4 + 1;
        i1 = rand() % 4 + 1;
        j1 = rand() % 4 + 1;
        // take random number,  1 <= i <= 4
        string str =
                to_string(i) + to_string(j) + to_string(k) + to_string(l) + to_string(m) +
                to_string(n) + to_string(i1) + to_string(j1);
        // Build the string to hold the 8 number seq
        int num = stoi(str);
        // Cast string to int to be input

        string arr_hat[4] = {STRAW_HAT, MEXICAN_HAT, FEZ, RUSSIAN_HAT};
        string arr_nose[4] ={NORMAL, DOT_NOSE, LINE, NONE};
        string arr_eyes[4] ={DOT_EYE, BIGGER_DOT, BIGGEST_DOT, CLOSED};
        string arr_left_arm[4] = {NORMAL_LEFT_ARM, UPWARDS_LEFT_ARM, DOWNWARDS_LEFT_ARM, NONE_ARM};
        string arr_right_arm[4] = {NORMAL_RIGHT_ARM, UPWARDS_RIGHT_ARM, DOWNWARDS_RIGHT_ARM, NONE_ARM};
        string arr_torso[4] = {BUTTONS, VEST, INWARD_ARMS, NONE_TORSO_AND_BASE};
        string arr_base[4] = {BUTTONS, FEET, FLAT, NONE_TORSO_AND_BASE};
        // init the arrays

        string hat = arr_hat[i-1];
        string nose = arr_nose[j-1];
        string leftEye = arr_eyes[k-1];
        string rightEye = arr_eyes[l-1];
        string leftArm = arr_left_arm[m-1];
        string rightArm = arr_right_arm[n-1];
        string torso = arr_torso[i1-1];
        string base = arr_base[j1-1];
        //init all vars

        if ((leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM) &&
            (rightArm == UPWARDS_RIGHT_ARM || rightArm == NONE_ARM)) {
            string checkString = hat += rightArm += "(" +
                                                    rightEye += nose +=
                                 leftEye + ")" +=
                                 leftArm + "\n (" +=
                                 torso + ") \n" += "(" + base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } else if ((rightArm == UPWARDS_RIGHT_ARM || rightArm == NONE_ARM) &&
                   (leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM)) {
            string checkString = hat += rightArm += "(" +
                                                    rightEye += nose +=
                                 leftEye + ") " +=
                                 "\n (" + torso +=
                                 ")" + leftArm += "\n(" + base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } else if ((rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM) &&
                   (leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM)) {
            string checkString = hat += " (" + rightEye += nose +=
                                 leftEye + ")" +=
                                 leftArm + "\n" +=
                                 rightArm + "(" +=
                                 torso + ") \n" + "(" += base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } else if ((leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM) &&
                   (rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM)) {
            string checkString = hat += " (" + rightEye += nose +=
                                 leftEye + ") \n"
                                 + rightArm +=
                                 "(" + torso +=
                                 ")" + leftArm += "\n(" + base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } // Testing random possibilities
    }
}
