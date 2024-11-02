#pragma once
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
using namespace chrono;

class timestampUtils {
    private:
        string calculateTDay(int year);
        string getCustomTimeInEST(time_t customTime);
        tm getTDay(int year);
        tm getSaturdayRaceDay(int year);
        tm getSundayRaceDay(int year);

    public:
        string getCurrentTimeInEST();
        void testDST(string timestampDST, string timestampEST);
        bool validateTimestamp(string timestamp);
        bool validateDateOfBirth(string dateOfBirth);
        string getRaceCalendarPeriod(string timestamp);
        pair<int, int> calculateAgeOnRaceDay(string dOB, int yearOfRace);
};