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
    cout << "Your amount due is $" << roster5K.getAmountDue("20241016 21:07:38") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.2
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.2:" << endl;
    roster10K.addRunner("Sarah", "Wilson", "19950415", "Female", "sarah.wilson@gmail.com", "20241017 11:07:38");
    cout << "Your amount due is $" << roster10K.getAmountDue("20241017 11:07:38") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.3
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.3:" << endl;
    rosterHalf.addRunner("John", "Martinez", "19830505", "Male", "john.martinez@gmail.com", "20241016 21:07:38");
    cout << "Your amount due is $" << rosterHalf.getAmountDue("20241016 21:07:38") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.4
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.4:" << endl;
    rosterFull.addRunner("Lisa", "Roberts", "19910630", "Female", "lisa.roberts@gmail.com", "20241017 11:07:38");
    cout << "Your amount due is $" << rosterFull.getAmountDue("20241017 11:07:38") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.5
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.5:" << endl;
    roster5K.addRunner("David", "Evans", "19780909", "Male", "david.evans@gmail.com", "20241118 07:50:40");
    cout << "Your amount due is $" << roster5K.getAmountDue("20241118 07:50:40") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.6
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.6:" << endl;
    roster10K.addRunner("Maria", "Torres", "19850222", "Female", "maria.torres@gmail.com", "20241120 17:50:40");
    cout << "Your amount due is $" << roster10K.getAmountDue("20241120 17:50:40") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.7
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.7:" << endl;
    rosterHalf.addRunner("Kevin", "Brown", "19931019", "Male", "kevin.brown@gmail.com", "20250228 11:55:25");
    cout << "Your amount due is $" << rosterHalf.getAmountDue("20250228 11:55:25") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.8
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.8:" << endl;
    rosterFull.addRunner("Natalie", "Cooper", "19900707", "Female", "natalie.cooper@gmail.com", "20250203 16:10:00");
    cout << "Your amount due is $" << rosterFull.getAmountDue("20250203 16:10:00") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.9
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.9:" << endl;
    roster5K.addRunner("Justin", "Sanchez", "20000817", "Male", "justin.sanchez@gmail.com", "20250320 12:45:35");
    cout << "Your amount due is $" << roster5K.getAmountDue("20250320 12:45:35") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.10
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.10:" << endl;
    roster10K.addRunner("Emily", "Nguyen", "19980303", "Female", "emily.nguyen@gmail.com", "20250302 10:25:10");
    cout << "Your amount due is $" << roster10K.getAmountDue("20250302 10:25:10") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.11
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.11:" << endl;
    rosterHalf.addRunner("Ryan", "Kim", "19890725", "Male", "ryan.kim@gmail.com", "20250306 13:10:45");
    cout << "Your amount due is $" << rosterHalf.getAmountDue("20250306 13:10:45") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.12
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.12:" << endl;
    rosterFull.addRunner("Olivia", "Lewis", "19921112", "Female", "olivia.lewis@gmail.com", "20250310 09:30:00");
    cout << "Your amount due is $" << rosterFull.getAmountDue("20250310 09:30:00") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.13
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.13:" << endl;
    roster5K.addRunner("Thomas", "Walker", "19760404", "Male", "thomas.walker@gmail.com", "20250415 08:05:20");
    cout << "Your amount due is $" << roster5K.getAmountDue("20250415 08:05:20") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.14
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.14:" << endl;
    roster10K.addRunner("Mia", "Foster", "19950123", "Female", "mia.foster@gmail.com", "20250421 15:40:55");
    cout << "Your amount due is $" << roster10K.getAmountDue("20250421 15:40:55") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.15
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.15:" << endl;
    rosterHalf.addRunner("Ethan", "Clark", "19840614", "Male", "ethan.clark@gmail.com", "20250425 11:20:30");
    cout << "Your amount due is $" << rosterHalf.getAmountDue("20250425 11:20:30") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.1.16
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.1.16:" << endl;
    rosterFull.addRunner("Zoe", "King", "19990830", "Female", "zoe.king@gmail.com", "20250420 14:55:45");
    cout << "Your amount due is $" << rosterFull.getAmountDue("20250420 14:55:45") << endl;
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 3.2.1
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 3.2.1:" << endl;
    roster5K.addRunner("Adam", "Hall", "19871005", "Male", "adam.hall@gmail.com", "20251027 10:50:15");
    roster5K.printRunner("Adam", "Hall");
    cout << "\n\n";

    return 0;
}
