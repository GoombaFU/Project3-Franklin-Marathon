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
    rosterFull.deleteRosterFile(); // Delete file for testing purposes ONLY!!!

    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.1
    //---------------------------------------------------------------------------------------
    cout << "\nTEST CASE 3.1.1:" << endl;
    roster5K.addRunner("Bob", "Smith", "19980707", "Male", "smith665@gmail.com", "20241016 21:07:38");

    cout << "\n\n";

    return 0;
}
