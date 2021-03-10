#include "doctest.h"
#include "snowman.hpp"
#include <stdlib.h>
#include <array>


using namespace std;
using namespace ariel;

//Hats

const string STRAW_HAT = "     \n_===_\n";
const string MEXICAN_HAT = " ___ \n.....\n";
const string FEZ = "  _  \n /_\\ \n";
const string RUSSIAN_HAT = " ___ \n(_*_)\n";

//Noses

const string NORMAL = ",";
const string DOT_NOSE = ".";
const string LINE = "_";
const string NONE = " ";

//Eyes

const string DOT_EYE = ".";
const string BIGGER_DOT = "o";
const string BIGGEST_DOT = "O";
const string CLOSED = "-";

//Left arm

const string NORMAL_LEFT_ARM = "<";
const string UPWARDS_LEFT_ARM = "\\";
const string DOWNWARDS_LEFT_ARM = "/";
const string NONE_ARM = " ";

//Right arm

const string NORMAL_RIGHT_ARM = ">";
const string UPWARDS_RIGHT_ARM = "/";
const string DOWNWARDS_RIGHT_ARM = "\\";

//Torso

const string BUTTONS = " : ";
const string VEST = "] [";
const string INWARD_ARMS = "> <";
const string NONE_TORSO_AND_BASE = "   ";

//Base

const string FEET = "\" \"";
const string FLAT = "___";

string nospaces(string input) {
    erase(input, ' ');
    erase(input, '\t');
    erase(input, '\n');
    erase(input, '\r');
    return input;
}

TEST_CASE ("Testing throws") { // Testing bad inputs
    CHECK_THROWS(snowman(444444445));
    CHECK_THROWS(snowman(-23232323));
    CHECK_THROWS(snowman(0));
    CHECK_THROWS(snowman(12310123));
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(-11));
    CHECK_THROWS(snowman(-111));
    CHECK_THROWS(snowman(-1111));
    CHECK_THROWS(snowman(-11111));
    CHECK_THROWS(snowman(-111111));
    CHECK_THROWS(snowman(-1111111));
    CHECK_THROWS(snowman(-111111111));
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
    CHECK_THROWS(snowman(11111110));
    CHECK_THROWS(snowman(11111101));
    CHECK_THROWS(snowman(11111011));
    CHECK_THROWS(snowman(11110111));
    CHECK_THROWS(snowman(11101111));
    CHECK_THROWS(snowman(11011111));
    CHECK_THROWS(snowman(10111111));
    CHECK_THROWS(snowman(01111111));
    CHECK_THROWS(snowman(1));
    CHECK_THROWS(snowman(11));
    CHECK_THROWS(snowman(111));
    CHECK_THROWS(snowman(1111));
    CHECK_THROWS(snowman(11111));
    CHECK_THROWS(snowman(111111));
    CHECK_THROWS(snowman(1111111));
    CHECK_THROWS(snowman(2));
    CHECK_THROWS(snowman(3));
}
TEST_CASE ("Testing good outcomes") {
    // Testing Hats.
    CHECK(nospaces(snowman(11111111)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(21111111)) == nospaces(" ___ \n.....\n (.,.) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(31111111)) == nospaces("  _  \n /_\\ \n (.,.) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(41111111)) == nospaces(" ___ \n(_*_)\n (.,.) \n<( : )>\n( : )"));
    // Testing Nose
    CHECK(nospaces(snowman(12111111)) == nospaces("     \n_===_\n (...) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(13111111)) == nospaces("     \n_===_\n (._.) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(14111111)) == nospaces("     \n_===_\n (. .) \n<( : )>\n( : )"));
    // Testing Left Eye
    CHECK(nospaces(snowman(11211111)) == nospaces("     \n_===_\n (o,.) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(11311111)) == nospaces("     \n_===_\n (O,.) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(11411111)) == nospaces("     \n_===_\n (-,.) \n<( : )>\n( : )"));
    // Testing Right Eye
    CHECK(nospaces(snowman(11121111)) == nospaces("     \n_===_\n (.,o) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(11131111)) == nospaces("     \n_===_\n (.,O) \n<( : )>\n( : )"));
    CHECK(nospaces(snowman(11141111)) == nospaces("     \n_===_\n (.,-) \n<( : )>\n( : )"));
    // Testing Left Arm
    CHECK(nospaces(snowman(11112111)) == nospaces("     \n_===_\n\\(.,.) \n ( : )>\n( : )"));
    CHECK(nospaces(snowman(11113111)) == nospaces("     \n_===_\n (.,.) \n/( : )>\n( : )"));
    CHECK(nospaces(snowman(11114111)) == nospaces("     \n_===_\n (.,.) \n ( : )>\n( : )"));
    // Testing Right Arm
    CHECK(nospaces(snowman(11111211)) == nospaces("     \n_===_\n (.,.)/\n<( : ) \n( : )"));
    CHECK(nospaces(snowman(11111311)) == nospaces("     \n_===_\n (.,.) \n<( : )\\\n( : )"));
    CHECK(nospaces(snowman(11111411)) == nospaces("     \n_===_\n (.,.) \n<( : ) \n( : )"));
    // Testing Torso
    CHECK(nospaces(snowman(11111121)) == nospaces("     \n_===_\n (.,.) \n<(] [)>\n( : )"));
    CHECK(nospaces(snowman(11111131)) == nospaces("     \n_===_\n (.,.) \n<(> <)>\n( : )"));
    CHECK(nospaces(snowman(11111141)) == nospaces("     \n_===_\n (.,.) \n<(   )>\n( : )"));
    //Testing Base
    CHECK(nospaces(snowman(11111112)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n(\" \")"));
    CHECK(nospaces(snowman(11111113)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n(___)"));
    CHECK(nospaces(snowman(11111114)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n(   )"));
}


TEST_CASE ("Testing random possible outcomes") {
    for (int i = 0; i < 1500; ++i) {      // testing 1,500 cases, it is possible to make this number even
                                          // higher but time is factor, could even test 65536 tests.
        int a = rand() % 4 + 1;           // it is even possible to store the sequence number in an array and
        int b = rand() % 4 + 1;           // run all possible scenarios, but it is wasteful.
        int c = rand() % 4 + 1;           // for best results, run with higher cases.
        int d = rand() % 4 + 1;
        int e = rand() % 4 + 1;
        int f = rand() % 4 + 1;
        int g = rand() % 4 + 1;
        int h = rand() % 4 + 1;

        // take random number,  1 <= i <= 4
        string str =
                to_string(a) + to_string(b) + to_string(c) + to_string(d) + to_string(e) +
                to_string(f) + to_string(g) + to_string(h);
        // Build the string to hold the 8 number seq
        int num = stoi(str);
        // Cast string to int to be input

        std::array<string, 4> arr_hat {STRAW_HAT, MEXICAN_HAT, FEZ, RUSSIAN_HAT};
        std::array<string, 4> arr_nose {NORMAL, DOT_NOSE, LINE, NONE};
        std::array<string, 4> arr_eyes {DOT_EYE, BIGGER_DOT, BIGGEST_DOT, CLOSED};
        std::array<string, 4> arr_left_arm {NORMAL_LEFT_ARM, UPWARDS_LEFT_ARM, DOWNWARDS_LEFT_ARM, NONE_ARM};
        std::array<string, 4> arr_right_arm {NORMAL_RIGHT_ARM, UPWARDS_RIGHT_ARM, DOWNWARDS_RIGHT_ARM, NONE_ARM};
        std::array<string, 4> arr_torso {BUTTONS, VEST, INWARD_ARMS, NONE_TORSO_AND_BASE};
        std::array<string, 4> arr_base {BUTTONS, FEET, FLAT, NONE_TORSO_AND_BASE};
        // init the arrays

        string hat = arr_hat.at(a-1);
        string nose = arr_nose.at(b-1);
        string leftEye = arr_eyes.at(c-1);
        string rightEye = arr_eyes.at(d-1);
        string leftArm = arr_left_arm.at(e-1);
        string rightArm = arr_right_arm.at(f-1);
        string torso = arr_torso.at(g-1);
        string base = arr_base.at(h-1);
        //init all vars

        // this is very important, there could be 4 possible out comes for the snowman:
        // both hands up, left up right down, left down right up, both down.
        // it is needed to check those scenarios to see which pattern is needed to be printed.
        if ((leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM) &&
            (rightArm == UPWARDS_RIGHT_ARM || rightArm == NONE_ARM)) { // check if both up
            string checkString = hat += leftArm += "(" +
                                 leftEye += nose +=
                                 rightEye + ")" +=
                                 rightArm + "\n (" +=
                                 torso + ") \n" += "(" + base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } else if ((leftArm == UPWARDS_LEFT_ARM || leftArm == NONE_ARM) &&
                   (rightArm == DOWNWARDS_RIGHT_ARM || leftArm == NORMAL_RIGHT_ARM)) { // check if left is down and right is up
            string checkString = hat += leftArm += "(" +
                                 leftEye += nose +=
                                 rightEye + ") " +=
                                 "\n (" + torso +=
                                 ")" + rightArm += "\n(" + base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } else if ((leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM) &&
                   (rightArm == UPWARDS_RIGHT_ARM || rightArm == NONE_ARM)) {// check if right is down and left is up
            string checkString = hat += " (" + leftEye += nose +=
                                 rightEye + ")" +=
                                 rightArm + "\n" +=
                                 leftArm + "(" +=
                                 torso + ") \n" + "(" += base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } else if ((leftArm == DOWNWARDS_LEFT_ARM || leftArm == NORMAL_LEFT_ARM) &&
                   (rightArm == DOWNWARDS_RIGHT_ARM || rightArm == NORMAL_RIGHT_ARM)) { // check if both hands down
            string checkString = hat += " (" + leftEye += nose +=
                                 rightEye + ") \n"
                                 + leftArm +=
                                 "(" + torso +=
                                 ")" + rightArm += "\n(" + base + ")";
                    CHECK(nospaces(snowman(num)) == nospaces(checkString));
        } // Testing random possibilities
    }
}
