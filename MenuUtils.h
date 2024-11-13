#pragma once
#include <iostream>
#include <string>
#include <map>
#include "timestampUtils.h"
#include "Roster.h"

using namespace std;

class MenuUtils {
    private:
        const map<string, map<string, int>> raceFees = {
        {"5K",   {{"Super Early", 30}, {"Early", 40}, {"Baseline", 50}, {"Late", 64}}},
        {"10K",  {{"Super Early", 50}, {"Early", 55}, {"Baseline", 70}, {"Late", 89}}},
        {"Half", {{"Super Early", 65}, {"Early", 70}, {"Baseline", 85}, {"Late", 99}}},
        {"Full", {{"Super Early", 75}, {"Early", 80}, {"Baseline", 85}, {"Late", 109}}}
    };

    public:
        bool validateRaceForDay(string, string);
        double getAmountDue(string, string, string);
        void addRunnersToRoster(int, Roster&);
};