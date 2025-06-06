#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include "timestampUtils.h"
#include "Roster.h"
#include "Runner.h"
#include "MenuUtils.h"

using namespace std;

int main() {
    timestampUtils tsu;
    MenuUtils msu;
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

    /* //---------------------------------------------------------------------------------------
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
    cout << "\n\n"; */
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.1
    //---------------------------------------------------------------------------------------
    /* cout << "\nTEST CASE 4.1.1:" << endl;
    string first = "Bob";
    string last = "Smith";
    string dob = "19980707";
    string gender = "Male";
    string email = "smith665@gmail.com";
    string registrationTimestamp = "20250301 08:00:00";
    string saturdayRace = "5K";
    string sundayRace = "10K";
    bool satRaceVerified = false;
    bool sunRaceVerified = false;

    if ((saturdayRace.empty() && sundayRace.empty())) {
       cerr << "Sign up failed. Must select at least one race." << endl;
    }
    else {
        satRaceVerified = msu.validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = msu.validateRaceForDay(saturdayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        cout << "Your amount due is $" << amountDue << endl;
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.2
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.1.2:" << endl;
    first = "Sarah";
    last = "Wilson";
    dob = "19950415";
    gender = "Female";
    email = "sarah.wilson@gmail.com";
    registrationTimestamp = "20250302 12:15:30";
    saturdayRace = "Half";
    sundayRace = "Full";
    satRaceVerified = false;
    sunRaceVerified = false;

    if ((saturdayRace.empty() && sundayRace.empty())) {
       cerr << "Sign up failed. Must select at least one race." << endl;
    }
    else {
        satRaceVerified = msu.validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = msu.validateRaceForDay(sundayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        cout << "Your amount due is $" << amountDue << endl;
    }
 
    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.3
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.1.3:" << endl;
    first = "Sarah";
    last = "Wilson";
    dob = "19950415";
    gender = "Female";
    email = "sarah.wilson@gmail.com";
    registrationTimestamp = "20250302 12:15:30";
    saturdayRace = "";
    sundayRace = "";
    satRaceVerified = false;
    sunRaceVerified = false;

    if ((saturdayRace.empty() && sundayRace.empty())) {
       cerr << "Sign up failed. Must select at least one race." << endl;
    }
    else {
        satRaceVerified = msu.validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = msu.validateRaceForDay(sundayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        cout << "Your amount due is $" << amountDue << endl;
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.4
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.1.4:" << endl;
    first = "John";
    last = "Martinez";
    dob = "19830505";
    gender = "Male";
    email = "john.martinez@gmail.com";
    registrationTimestamp = "20250303 14:30:45";
    saturdayRace = "10K";
    sundayRace = "Half";
    satRaceVerified = false;
    sunRaceVerified = false;

    if ((saturdayRace.empty() && sundayRace.empty())) {
       cerr << "Sign up failed. Must select at least one race." << endl;
    }
    else {
        satRaceVerified = msu.validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = msu.validateRaceForDay(sundayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        cout << "Your amount due is $" << amountDue << endl;
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.5
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.1.5:" << endl;
    first = "Lisa";
    last = "Roberts";
    dob = "19910630";
    gender = "Female";
    email = "lisa.roberts@gmail.com";
    registrationTimestamp = "20250304 09:45:15";
    saturdayRace = "5K";
    sundayRace = "";

    roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, 
        msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace));

    registrationTimestamp = "20250305 09:45:15";
    saturdayRace = "";
    sundayRace = "Half";

    int amountPaid = 0;

    bool runnerExists5K = roster5K.runnerExists(first, last, email);
    bool runnerExists10K = roster10K.runnerExists(first, last, email);
    bool runnerExistsHalf = rosterHalf.runnerExists(first, last, email);
    bool runnerExistsFull = rosterFull.runnerExists(first, last, email);

    if (runnerExists5K) {
        auto [previousAmountPaid, runnerPtr] = roster5K.getAmountPaidAndRunner(first, last, email);
        amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else if (runnerExists10K) {
        auto [previousAmountPaid, runnerPtr] = roster10K.getAmountPaidAndRunner(first, last, email);
        amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else if (runnerExistsHalf) {
        auto [previousAmountPaid, runnerPtr] = rosterHalf.getAmountPaidAndRunner(first, last, email);
        amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else if (runnerExistsFull) {
        auto [previousAmountPaid, runnerPtr] = rosterFull.getAmountPaidAndRunner(first, last, email);
        amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else {
        amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
    }

    rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);

    roster5K.printRunner(first, last);
    cout << "\n";
    rosterHalf.printRunner(first, last);

    cout << "\n\n";

    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.6
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.1.6:" << endl;
    first = "David";
    last = "Evans";
    dob = "20000504";
    gender = "Male";
    email = "david.evans@gmail.com";
    registrationTimestamp = "20250310 13:20:50";
    saturdayRace = "5K";
    sundayRace = "Full";

    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

    roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
    rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);

    roster5K.printRunner(first, last);
    cout << "\n";
    rosterFull.printRunner(first, last);

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.1.7
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.1.7:" << endl;
    first = "Maria";
    last = "Torres";
    dob = "19850222";
    gender = "Female";
    email = "maria.torres@gmail.com";
    registrationTimestamp = "20250312 16:35:25";
    saturdayRace = "5K";
    sundayRace = "";
    satRaceVerified = false;
    sunRaceVerified = false;

    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
    roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
    cout << "User has been added to the 5K roster successfully!" << endl;

    saturdayRace = "10K";
    sundayRace = "";
    registrationTimestamp = "20250313 16:35:25";

    runnerExists5K = roster5K.runnerExists(first, last, email);
    runnerExists10K = roster10K.runnerExists(first, last, email);
    runnerExistsHalf = rosterHalf.runnerExists(first, last, email);
    runnerExistsFull = rosterFull.runnerExists(first, last, email);

    if ((runnerExists5K || runnerExists10K) && !saturdayRace.empty()) {
        cerr << "Sign up failed. Cannot sign up for both Saturday races." << endl;
    }
    else if ((runnerExistsHalf || runnerExistsFull) && !sundayRace.empty()) {
        cerr << "Sign up failed. Cannot sign up for both Sunday races." << endl;
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.2.1
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.2.1:" << endl;
    first = "Kevin";
    last = "Brown";
    dob = "19931019";
    gender = "Male";
    email = "kevin.brown@gmail.com";
    registrationTimestamp = "20250423 11:55:25";
    saturdayRace = "10K";
    sundayRace = "";

    roster5K.clearRoster();
    roster10K.clearRoster();
    msu.addRunnersToRoster(39, roster5K);
    msu.addRunnersToRoster(60, roster10K);

    int saturdayRaceSize = roster5K.getRosterSize() + roster10K.getRosterSize();
    int sundayRaceSize = rosterHalf.getRosterSize() + rosterFull.getRosterSize();
    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

    if (saturdayRace == "5K") {
        if (saturdayRaceSize < 100) {
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 5K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 5K roster as Saturday races are full." << endl;
        }
    }
    else if (saturdayRace == "10K") {
        if (saturdayRaceSize < 100) {
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 10K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 10K roster as Saturday races are full." << endl;
        }
    }

    if (sundayRace == "Half") {
        if (sundayRaceSize < 100) {
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Half Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Half Marathon roster as Sunday races are full." << endl;
        }
    }
    else if (sundayRace == "Full") {
        if (sundayRaceSize < 100) {
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Full Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Full Marathon roster as Sunday races are full." << endl;
        }
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.2.2
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.2.2:" << endl;
    first = "Emily";
    last = "Nguyen";
    dob = "19900707";
    gender = "Female";
    email = "emily.nguyen@gmail.com";
    registrationTimestamp = "20250420 14:40:20";
    saturdayRace = "";
    sundayRace = "Half";

    rosterHalf.clearRoster();
    rosterFull.clearRoster();
    msu.addRunnersToRoster(52, rosterHalf);
    msu.addRunnersToRoster(47, rosterFull);

    saturdayRaceSize = roster5K.getRosterSize() + roster10K.getRosterSize();
    sundayRaceSize = rosterHalf.getRosterSize() + rosterFull.getRosterSize();
    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

    if (saturdayRace == "5K") {
        if (saturdayRaceSize < 100) {
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 5K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 5K roster as Saturday races are full." << endl;
        }
    }
    else if (saturdayRace == "10K") {
        if (saturdayRaceSize < 100) {
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 10K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 10K roster as Saturday races are full." << endl;
        }
    }

    if (sundayRace == "Half") {
        if (sundayRaceSize < 100) {
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Half Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Half Marathon roster as Sunday races are full." << endl;
        }
    }
    else if (sundayRace == "Full") {
        if (sundayRaceSize < 100) {
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Full Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Full Marathon roster as Sunday races are full." << endl;
        }
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.2.3
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.2.3:" << endl;
    first = "Justin";
    last = "Sanchez";
    dob = "20000817";
    gender = "Male";
    email = "justin.sanchez@gmail.com";
    registrationTimestamp = "20250422 07:50:30";
    saturdayRace = "5K";
    sundayRace = "";

    roster5K.clearRoster();
    roster10K.clearRoster();
    msu.addRunnersToRoster(40, roster5K);
    msu.addRunnersToRoster(60, roster10K);

    saturdayRaceSize = roster5K.getRosterSize() + roster10K.getRosterSize();
    sundayRaceSize = rosterHalf.getRosterSize() + rosterFull.getRosterSize();
    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

    if (saturdayRace == "5K") {
        if (saturdayRaceSize < 100) {
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 5K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 5K roster as Saturday races are full." << endl;
        }
    }
    else if (saturdayRace == "10K") {
        if (saturdayRaceSize < 100) {
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 10K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 10K roster as Saturday races are full." << endl;
        }
    }

    if (sundayRace == "Half") {
        if (sundayRaceSize < 100) {
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Half Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Half Marathon roster as Sunday races are full." << endl;
        }
    }
    else if (sundayRace == "Full") {
        if (sundayRaceSize < 100) {
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Full Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Full Marathon roster as Sunday races are full." << endl;
        }
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.2.4
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.2.4:" << endl;
    first = "Natalie";
    last = "Cooper";
    dob = "19980303";
    gender = "Female";
    email = "natalie.cooper@gmail.com";
    registrationTimestamp = "20250425 18:25:45";
    saturdayRace = "";
    sundayRace = "Full";

    rosterHalf.clearRoster();
    rosterFull.clearRoster();
    msu.addRunnersToRoster(52, rosterHalf);
    msu.addRunnersToRoster(48, rosterFull);

    saturdayRaceSize = roster5K.getRosterSize() + roster10K.getRosterSize();
    sundayRaceSize = rosterHalf.getRosterSize() + rosterFull.getRosterSize();
    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

    if (saturdayRace == "5K") {
        if (saturdayRaceSize < 100) {
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 5K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 5K roster as Saturday races are full." << endl;
        }
    }
    else if (saturdayRace == "10K") {
        if (saturdayRaceSize < 100) {
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 10K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 10K roster as Saturday races are full." << endl;
        }
    }

    if (sundayRace == "Half") {
        if (sundayRaceSize < 100) {
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Half Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Half Marathon roster as Sunday races are full." << endl;
        }
    }
    else if (sundayRace == "Full") {
        if (sundayRaceSize < 100) {
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Full Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Full Marathon roster as Sunday races are full." << endl;
        }
    }

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 4.2.5
    //---------------------------------------------------------------------------------------
    cout << "TEST CASE 4.2.5:" << endl;
    first = "Ryan";
    last = "Kim";
    dob = "19890725";
    gender = "Male";
    email = "ryan.kim@gmail.com";
    registrationTimestamp = "20250406 13:10:45";
    saturdayRace = "10K";
    sundayRace = "Half";

    roster5K.clearRoster();
    roster10K.clearRoster();
    rosterHalf.clearRoster();
    rosterFull.clearRoster();
    msu.addRunnersToRoster(39, roster5K);
    msu.addRunnersToRoster(60, roster10K);
    msu.addRunnersToRoster(52, rosterHalf);
    msu.addRunnersToRoster(48, rosterFull);

    saturdayRaceSize = roster5K.getRosterSize() + roster10K.getRosterSize();
    sundayRaceSize = rosterHalf.getRosterSize() + rosterFull.getRosterSize();
    amountPaid = msu.getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

    if (saturdayRace == "5K") {
        if (saturdayRaceSize < 100) {
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 5K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 5K roster as Saturday races are full." << endl;
        }
    }
    else if (saturdayRace == "10K") {
        if (saturdayRaceSize < 100) {
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the 10K roster sucessfully!" << endl;
        }
        else {
            cerr << "User was not added to the 10K roster as Saturday races are full." << endl;
        }
    }

    if (sundayRace == "Half") {
        if (sundayRaceSize < 100) {
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Half Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Half Marathon roster as Sunday races are full." << endl;
        }
    }
    else if (sundayRace == "Full") {
        if (sundayRaceSize < 100) {
            rosterFull.addRunner(first, last, dob, gender, email, registrationTimestamp, amountPaid);
            cout << "User has been added to the Full Marathon roster successfully!" << endl;
        }
        else {
            cerr << "User was not added to the Full Marathon roster as Sunday races are full." << endl;
        }
    }

    cout << "\n\n"; */
    //---------------------------------------------------------------------------------------
    // TEST CASE 5.1.1
    //---------------------------------------------------------------------------------------
    cout << "\nTEST CASE 5.1.1:" << endl;

    roster5K.addRunner("Lisa", "Roberts", "19910630", "Female", "lisa.roberts@gmail.com", "20241004 09:45:15", 
        msu.getAmountDue("20241004 09:45:15", "5K", ""));

    roster5K.addRunner("Bob", "Smith", "19980707", "Male", "smith665@gmail.com", "20241101 08:00:00", 
        msu.getAmountDue("20241101 08:00:00", "5K", ""));

    roster5K.addRunner("Sarah", "Wilson", "19950415", "Female", "sarah.wilson@gmail.com", "20250302 12:15:30", 
        msu.getAmountDue("20250302 12:15:30", "5K", ""));
    
    roster5K.addRunner("John", "Martinez", "19830505", "Male", "john.martinez@gmail.com", "20250303 14:30:45", 
        msu.getAmountDue("20250303 14:30:45", "5K", ""));

    roster5K.addRunner("David", "Evans", "20000504", "Male", "david.evans@gmail.com", "20250410 13:20:50", 
        msu.getAmountDue("20250410 13:20:50", "5K", ""));

    roster5K.printRoster();

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 5.1.2
    //---------------------------------------------------------------------------------------
    cout << "\nTEST CASE 5.1.2:" << endl;

    roster10K.addRunner("Maria", "Torres", "19850222", "Female", "maria.torres@gmail.com", "20241012 16:35:25", 
        msu.getAmountDue("20241012 16:35:25", "10K", ""));

    roster10K.addRunner("Kevin", "Brown", "19931019", "Male", "kevin.brown@gmail.com", "20241123 11:55:25", 
        msu.getAmountDue("20241123 11:55:25", "10K", ""));

    roster10K.addRunner("Emily", "Nguyen", "19900707", "Female", "emily.nguyen@gmail.com", "20250320 14:40:20", 
        msu.getAmountDue("20250320 14:40:20", "10K", ""));
    
    roster10K.addRunner("Justin", "Sanchez", "20000817", "Male", "justin.sanchez@gmail.com", "20250322 07:50:30", 
        msu.getAmountDue("20250322 07:50:30", "10K", ""));

    roster10K.addRunner("Natalie", "Cooper", "19980303", "Female", "natalie.cooper@gmail.com", "20250425 18:25:45", 
        msu.getAmountDue("20250425 18:25:45", "10K", ""));

    roster10K.printRoster();

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 5.1.3
    //---------------------------------------------------------------------------------------
    cout << "\nTEST CASE 5.1.3:" << endl;

    rosterHalf.addRunner("Ryan", "Kim", "19890725", "Male", "ryan.kim@gmail.com", "20241006 13:10:45", 
        msu.getAmountDue("20241006 13:10:45", "Half", ""));

    rosterHalf.addRunner("Sarah", "Lee", "19910515", "Female", "sarah.lee@gmail.com", "20241102 09:45:30", 
        msu.getAmountDue("20241102 09:45:30", "Half", ""));

    rosterHalf.addRunner("Michael", "Johnson", "19851003", "Male", "michael.johnson@hotmail.com", "20250305 16:22:10", 
        msu.getAmountDue("20250305 16:22:10", "Half", ""));

    rosterHalf.addRunner("Emily", "Chen", "19980127", "Female", "emily.chen@yahoo.com", "20250410 08:10:55", 
        msu.getAmountDue("20250410 08:10:55", "Half", ""));

    rosterHalf.printRoster();

    cout << "\n\n";
    //---------------------------------------------------------------------------------------
    // TEST CASE 5.1.4
    //---------------------------------------------------------------------------------------
    cout << "\nTEST CASE 5.1.4:" << endl;

    rosterFull.addRunner("Jessica", "Taylor", "19930806", "Female", "jessica.taylor@gmail.com", "20241015 12:05:20", 
        msu.getAmountDue("20241015 12:05:20", "Full", ""));

    rosterFull.addRunner("William", "Martinez", "19880311", "Male", "william.martinez@yahoo.com", "20241018 17:50:35", 
        msu.getAmountDue("20241018 17:50:35", "Full", ""));

    rosterFull.addRunner("Sophia", "Garcia", "19950922", "Female", "sophia.garcia@aol.com", "20241122 10:15:00", 
        msu.getAmountDue("20241122 10:15:00", "Full", ""));

    rosterFull.addRunner("Daniel", "Lee", "19820430", "Male", "daniel.lee@gmail.com", "20241125 13:40:25", 
        msu.getAmountDue("20241125 13:40:25", "Full", ""));

    rosterFull.addRunner("Ashley", "Wilson", "19991212", "Female", "ashley.wilson@hotmail.com", "20250328 09:55:15", 
        msu.getAmountDue("20250328 09:55:15", "Full", ""));

    rosterFull.addRunner("David", "Brown", "19900219", "Male", "david.brown@outlook.com", "20250412 14:32:45", 
        msu.getAmountDue("20250412 14:32:45", "Full", ""));

    rosterFull.printRoster();

    cout << "\n\n";

    return 0;
}
