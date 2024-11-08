#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>
#include "timestampUtils.h"
#include "Roster.h"
#include "Runner.h"

using namespace std;

bool validateRaceForDay(string race, string day) {
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

int getAmountDue(string timestamp, string race1, string race2) {
    timestampUtils tsu;
    string racePeriod = tsu.getRaceCalendarPeriod(timestamp);
    int amountDue = 0;

    if (race1 == "5K") {
        if (racePeriod == "Super Early") {
            amountDue += 30;
        }
        else if (racePeriod == "Early") {
            amountDue += 40;
        }
        else if (racePeriod == "Baseline") {
            amountDue += 50;
        }
        else if (racePeriod == "Late") {
            amountDue += 64;
        }
    }
    else if (race1 == "10K") {
       if (racePeriod == "Super Early") {
            amountDue += 50;
        }
        else if (racePeriod == "Early") {
            amountDue += 55;
        }
        else if (racePeriod == "Baseline") {
            amountDue += 70;
        }
        else if (racePeriod == "Late") {
            amountDue += 89;
        } 
    }

    if (race2 == "Half") {
        if (racePeriod == "Super Early") {
            amountDue += 65;
        }
        else if (racePeriod == "Early") {
            amountDue += 70;
        }
        else if (racePeriod == "Baseline") {
            amountDue += 85;
        }
        else if (racePeriod == "Late") {
            amountDue += 99;
        } 
    }
    else if (race2 == "Full") {
      if (racePeriod == "Super Early") {
            amountDue += 75;
        }
        else if (racePeriod == "Early") {
            amountDue += 80;
        }
        else if (racePeriod == "Baseline") {
            amountDue += 85;
        }
        else if (racePeriod == "Late") {
            amountDue += 109;
        }   
    }

    if ((!race1.empty() && !race2.empty())) {
        amountDue = amountDue * 0.80;
    }

    return amountDue;
}

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
    cout << "\nTEST CASE 4.1.1:" << endl;
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
        satRaceVerified = validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = validateRaceForDay(saturdayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
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
        satRaceVerified = validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = validateRaceForDay(sundayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
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
        satRaceVerified = validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = validateRaceForDay(sundayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
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
        satRaceVerified = validateRaceForDay(saturdayRace, "Saturday");
        sunRaceVerified = validateRaceForDay(sundayRace, "Sunday");
    }

    if (satRaceVerified && sunRaceVerified) {
        int amountDue = 0;

        if (saturdayRace == "5K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster5K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (saturdayRace == "10K") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            roster10K.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }

        if (sundayRace == "Half") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
            rosterHalf.addRunner(first, last, dob, gender, email, registrationTimestamp, amountDue);
        }
        else if (sundayRace == "Full") {
            amountDue = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
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
        getAmountDue(registrationTimestamp, saturdayRace, sundayRace));

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
        amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else if (runnerExists10K) {
        auto [previousAmountPaid, runnerPtr] = roster10K.getAmountPaidAndRunner(first, last, email);
        amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else if (runnerExistsHalf) {
        auto [previousAmountPaid, runnerPtr] = rosterHalf.getAmountPaidAndRunner(first, last, email);
        amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else if (runnerExistsFull) {
        auto [previousAmountPaid, runnerPtr] = rosterFull.getAmountPaidAndRunner(first, last, email);
        amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace) + previousAmountPaid;
        runnerPtr->setAmountPaid(amountPaid);
    }
    else {
        amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
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

    amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);

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

    amountPaid = getAmountDue(registrationTimestamp, saturdayRace, sundayRace);
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


    return 0;
}
