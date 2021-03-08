#include "doctest.h"
#include "snowman.hpp"

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

using namespace std;
using namespace ariel;


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
}



TEST_CASE ("Testing all possible outcomes") {
    for (int i = 1; i < 5; ++i) {
        for (int j = 1; j < 5; ++j) {
            for (int k = 1; k < 5; ++k) {
                for (int l = 1; l < 5; ++l) {
                    for (int m = 1; m < 5; ++m) {
                        for (int n = 1; n < 5; ++n) {
                            for (int i1 = 1; i1 < 5; ++i1) {
                                for (int j1 = 1; j1 < 5; ++j1) {
                                    string str =
                                            to_string(i) + to_string(j) + to_string(k) + to_string(l) + to_string(m) +
                                            to_string(n) + to_string(i1) + to_string(j1);
                                    // Build the string to hold the 8 number seq
                                    int num = stoi(str);
                                    // Cast string to int to be input
                                    string hat;
                                    string nose;
                                    string leftEye;
                                    string rightEye;
                                    string leftArm;
                                    string rightArm;
                                    string torso;
                                    string base;
                                    //init all vars
                                    switch (i) {
                                        case 1:
                                            hat = STRAW_HAT;
                                            break;
                                        case 2:
                                            hat = MEXICAN_HAT;
                                            break;
                                        case 3:
                                            hat = FEZ;
                                            break;
                                        case 4:
                                            hat = RUSSIAN_HAT;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (j) {
                                        case 1:
                                            nose = NORMAL;
                                            break;
                                        case 2:
                                            nose = DOT_NOSE;
                                            break;
                                        case 3:
                                            nose = LINE;
                                            break;
                                        case 4:
                                            nose = NONE;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (k) {
                                        case 1:
                                            leftEye = DOT_EYE;
                                            break;
                                        case 2:
                                            leftEye = BIGGER_DOT;
                                            break;
                                        case 3:
                                            leftEye = BIGGEST_DOT;
                                            break;
                                        case 4:
                                            leftEye = CLOSED;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (l) {
                                        case 1:
                                            rightEye = DOT_EYE;
                                            break;
                                        case 2:
                                            rightEye = BIGGER_DOT;
                                            break;
                                        case 3:
                                            rightEye = BIGGEST_DOT;
                                            break;
                                        case 4:
                                            rightEye = CLOSED;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (m) {
                                        case 1:
                                            leftArm = NORMAL_LEFT_ARM;
                                            break;
                                        case 2:
                                            leftArm = UPWARDS_LEFT_ARM;
                                            break;
                                        case 3:
                                            leftArm = DOWNWARDS_LEFT_ARM;
                                            break;
                                        case 4:
                                            leftArm = NONE_ARM;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (n) {
                                        case 1:
                                            rightArm = NORMAL_RIGHT_ARM;
                                            break;
                                        case 2:
                                            rightArm = UPWARDS_RIGHT_ARM;
                                            break;
                                        case 3:
                                            rightArm = DOWNWARDS_RIGHT_ARM;
                                            break;
                                        case 4:
                                            rightArm = NONE_ARM;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (i1) {
                                        case 1:
                                            torso = BUTTONS;
                                            break;
                                        case 2:
                                            torso = VEST;
                                            break;
                                        case 3:
                                            torso = INWARD_ARMS;
                                            break;
                                        case 4:
                                            torso = NONE_TORSO_AND_BASE;
                                            break;
                                        default:
                                            exit(1);
                                    }
                                    switch (j1) {
                                        case 1:
                                            base = BUTTONS;
                                            break;
                                        case 2:
                                            base = FEET;
                                            break;
                                        case 3:
                                            base = FLAT;
                                            break;
                                        case 4:
                                            base = NONE_TORSO_AND_BASE;
                                            break;
                                        default:
                                            exit(1);
                                    }
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
                                                    CHECK(nospaces(snowman(num))  == nospaces(checkString));
                                        } else if ((rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM) &&
                                                   (leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM)) {
                                            string checkString = hat += " (" + rightEye += nose +=
                                                                 leftEye + ")" +=
                                                                 leftArm + "\n" +=
                                                                 rightArm + "(" +=
                                                                 torso + ") \n" + "(" += base + ")";
                                                    CHECK(nospaces(snowman(num))  == nospaces(checkString));
                                    } else if ((leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM) &&
                                               (rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM)) {
                                        string checkString = hat += " (" + rightEye += nose +=
                                                             leftEye + ") \n"
                                                             + rightArm +=
                                                             "(" + torso +=
                                                             ")" + leftArm += "\n(" + base + ")";
                                                    CHECK(nospaces(snowman(num))  == nospaces(checkString));
                                    } // Checking all possible outcomes of the program
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}