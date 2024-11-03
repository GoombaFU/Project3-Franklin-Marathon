#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include "timestampUtils.h"
#include "Runner.h"

using namespace std;

class Roster {
    private:
        string filename;
        string race;
        vector<Runner> roster;
        bool validateRunner(string, string, string, string, string, string);
        const unordered_map<string, unordered_map<string, int>> raceFees = {
            {"5K", {{"Super Early", 30}, {"Early", 40}, {"Baseline", 50}, {"Late", 64}}},
            {"10K", {{"Super Early", 50}, {"Early", 55}, {"Baseline", 70}, {"Late", 89}}},
            {"Half Marathon", {{"Super Early", 65}, {"Early", 70}, {"Baseline", 85}, {"Late", 99}}},
            {"Full Marathon", {{"Super Early", 75}, {"Early", 80}, {"Baseline", 85}, {"Late", 109}}}
        };
        int getAmountDue(string);

    public:
        Roster(string, string);
        void saveRosterToFile();
        void loadRosterFromFile();
        vector<Runner> getRoster();
        bool addRunner(string, string, string, string, string, string);
        void deleteRosterFile();
        void printRunner(string, string);
        bool runnerExists(string, string, string);
};
