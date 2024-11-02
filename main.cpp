#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include "timestampUtils.h"
#include "Roster.h"
#include "Runner.h"

using namespace std;

int main() {
    timestampUtils tsu;
    string race1 = "5K_roster.dat";
    string race2 = "10K_roster.dat";
    string race3 = "half_roster.dat";
    string race4 = "full_roster.dat";
    Roster roster5K(race1, "5K");
    Roster roster10K(race2, "10K");
    Roster rosterHalf(race3, "Half Marathon");
    Roster rosterFull(race4, "Full Marathon");

    cout << "---------------------------------------------------------------------------------------" << endl;
    cout << "OUTPUT FROM DELETING ROSTER FILES TO RESET THEM FOR TESTING PURPOSES. PLEASE IGNORE." << endl;
    cout << "---------------------------------------------------------------------------------------" << endl;
    roster5K.deleteRosterFile(); // Delete file for testing purposes ONLY!!!
    roster10K.deleteRosterFile(); // Delete file for testing purposes ONLY!!!
    rosterHalf.deleteRosterFile(); // Delete file for testing purposes ONLY!!!
    rosterFull.deleteRosterFile(); // Delete file for testing purposes ONLY!!! haha

    //---------------------------------------------------------------------------------------
    // TEST CASE 2.2.1
    //---------------------------------------------------------------------------------------
    cout << "\nTEST CASE 2.2.1:" << endl;
    rosterHalf.addRunner("Ethan", "Davis", "20000504", "Male", "ethan.davis@gmail.com", "20250325 17:30:50");
    rosterHalf.printRunner("Ethan", "Davis");
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 2.2.2
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 2.2.2:" << endl;
    roster5K.printRunner("Ethan", "Davis");
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 2.2.3
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 2.2.3:" << endl;
    
    bool in5K = roster5K.runnerExists("Ethan", "Davis", "ethan.davis@gmail.com");
    bool in10K = roster10K.runnerExists("Ethan", "Davis", "ethan.davis@gmail.com");
    bool inHalf = rosterHalf.runnerExists("Ethan", "Davis", "ethan.davis@gmail.com");
    bool inFull = rosterFull.runnerExists("Ethan", "Davis", "ethan.davis@gmail.com");

    if (in5K == false && in10K == false && inHalf == false && inFull == false) {
        rosterHalf.addRunner("Ethan", "Davis", "20000504", "Male", "ethan.davis@gmail.com", "20250325 17:30:50");
    }
    else {
        if (in5K == true) {
            cout << "Sign up failed. User already in 5K roster" << endl;
        }
        else if (in10K == true) {
            cout << "Sign up failed. User already in 10K roster" << endl;
        }
        else if (inHalf == true) {
            cout << "Sign up failed. User already in Half Marathon roster" << endl;
        }
        else if (inFull == true) {
            cout << "Sign up failed. User already in Full Marathon roster" << endl;
        }
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 2.2.4
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 2.2.4:" << endl;
    string raceBeingRan = "15K";
    
    if (raceBeingRan == "5K") {
        roster5K.addRunner("Isabella", "Garcia", "19950814", "Female", "isabella.garcia@gmail.com", "20250328 07:40:15");
    }
    else if (raceBeingRan == "10K") {
        roster10K.addRunner("Isabella", "Garcia", "19950814", "Female", "isabella.garcia@gmail.com", "20250328 07:40:15");
    }
    else if (raceBeingRan == "Half") {
        rosterHalf.addRunner("Isabella", "Garcia", "19950814", "Female", "isabella.garcia@gmail.com", "20250328 07:40:15");
    }
    else if (raceBeingRan == "Full") {
        rosterFull.addRunner("Isabella", "Garcia", "19950814", "Female", "isabella.garcia@gmail.com", "20250328 07:40:15");
    }
    else {
        cerr << "Sign up failed. Invalid or missing race." << endl;
    }

    cout << "\n\n";

    return 0;
}
