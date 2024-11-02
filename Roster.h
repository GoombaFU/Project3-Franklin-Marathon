#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "timestampUtils.h"
#include "Runner.h"

using namespace std;

class Roster {
    private:
        string filename;
        string race;
        vector<Runner> roster;
        bool validateRunner(string, string, string, string, string, string);

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
