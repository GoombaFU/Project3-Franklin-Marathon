#include "MenuUtils.h"


bool MenuUtils::validateRaceForDay(string race, string day) {
    if ((day == "Saturday" && (race == "5K" || race == "10K")) || (day == "Sunday" && (race == "Half" || race == "Full")) 
        || (race == "")) {
        return true;
    }
    else if ((day == "Saturday" && (race == "Half" || race == "Full")) || (day == "Sunday" && (race == "5K" || race == "10K"))) {
        if (day == "Saturday") {
            cerr << "Sign up failed. Cannot sign up for a Sunday race on Saturday." << endl;
        }
        else if (day == "Sunday") {
            cerr << "Sign up failed. Cannot sign up for a Saturday race on Sunday." << endl;
        }

        return false;
    }
    else {
        cerr << "Sign up failed. Invalid Race." << endl;
        return false;
    }
}

double MenuUtils::getAmountDue(string timestamp, string race1, string race2) {
    timestampUtils tsu;
    string racePeriod = tsu.getRaceCalendarPeriod(timestamp);
    double amountDue = 0;

    if (raceFees.find(race1) != raceFees.end()) {
        const auto periods = raceFees.at(race1);
        if (periods.find(racePeriod) != periods.end()) {
            amountDue += periods.at(racePeriod);
        }
    }

    if (raceFees.find(race2) != raceFees.end()) {
        const auto periods = raceFees.at(race2);
        if (periods.find(racePeriod) != periods.end()) {
            amountDue += periods.at(racePeriod);
        }
    }

    if (!race1.empty() && !race2.empty()) {
        amountDue = amountDue * 0.80;
    }

    return amountDue;
}

void MenuUtils::addRunnersToRoster(int numRunners, Roster& roster) {
    timestampUtils tsu;

    for (int i = 0; i < numRunners; ++i) {
        int onesDigit = i % 10;
        char letter = 'a' + (onesDigit == 0 ? 9 : onesDigit - 1);

        int tensDigit = (i / 10) % 10;
        string letterRepetitions(tensDigit + 1, letter);

        string firstName = "First" + letterRepetitions;
        string lastName = "Last" + letterRepetitions;
        string email = firstName + lastName + "@gmail.com";
        string dob = "20000704";
        string gender = "female";
        string registrationTimestamp = tsu.getCurrentTimeInEST();

        roster.addRunner(firstName, lastName, dob, gender, email, registrationTimestamp, 0);
    }
}