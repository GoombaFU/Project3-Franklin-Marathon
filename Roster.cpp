#include "Roster.h"

Roster::Roster(string name, string raceName) {
    filename = name;

    if (raceName != "5K" && raceName != "10K" && raceName != "Half Marathon" && raceName != "Full Marathon") {
        throw invalid_argument("Invalid race name. Allowed values are: '5K', '10K', 'Half Marathon', or 'Full Marathon'.");
    }
    else {
        race = raceName;
    }
}

bool Roster::validateRunner(string fn, string ln, string dateOfBirth, string gen, string mail, string time) {
    timestampUtils tsu;
    bool fnContainsNumber = false;
    bool lnContainsNumber = false;

    for (char ch : fn) {
        if (isdigit(ch)) {
            fnContainsNumber = true;
            break;
        }
    }

    for (char ch : ln) {
        if (isdigit(ch)) {
            lnContainsNumber = true;
            break;
        }
    }

    if (fn.empty() || ln.empty() || fnContainsNumber || lnContainsNumber) {
        cerr << "Sign up failed. First or last name is either missing or invalid." << endl;
        return false;
    }

    if (!tsu.validateDateOfBirth(dateOfBirth)) {
        cerr << "Sign up failed. Date of birth is either invalid or missing." << endl;
        return false;
    }
    
    if (gen != "Male" && gen != "Female" && gen != "male" && gen != "female") {
        cerr << "Sign up failed. Gender is either invalid or missing." << endl;
        return false;
    }

    if (mail.empty()) {
        cerr << "Sign up failed. Email is either invalid or missing." << endl;
        return false;
    }

    string timestampReturn = tsu.getRaceCalendarPeriod(time);

    if (timestampReturn == "Timestamp failed. Invalid date." || timestampReturn == "Timestamp failed to find a registration period.") {
        cerr << "Sign up failed. Timestamp is invalid." << endl;
        return false;
    }
    else if (timestampReturn == "Not Open") {
        cerr << "Sign up failed. Registration is not open." << endl;
        return false;
    }
    else if (timestampReturn == "Closed") {
        cerr << "Sign up failed. Registration is closed." << endl;
        return false;
    }

    return true;
}

void Roster::saveRosterToFile() {
    ofstream outFile(filename, ios::binary);

    if (!outFile.is_open()) {
        cout << "Error: Could not open file for saving." << endl;
        return;
    }

    size_t rosterSize = roster.size();
    outFile.write(reinterpret_cast<const char*>(&rosterSize), sizeof(rosterSize));

    for (const auto& runner : roster) {
        runner.serialize(outFile);
    }

    outFile.close();
    //cout << "Roster saved successfully to " << filename << endl;
}

void Roster::loadRosterFromFile() {
    ifstream inFile(filename, ios::binary);

    if (!inFile.is_open()) {
        cout << "Error: Could not open file for loading." << endl;
        return;
    }

    size_t rosterSize;
    inFile.read(reinterpret_cast<char*>(&rosterSize), sizeof(rosterSize));

    roster.resize(rosterSize);

    for (auto& runner : roster) {
        runner.deserialize(inFile);
    }

    inFile.close();
    //cout << "Roster loaded successfully from " << filename << endl;
}

void Roster::deleteRosterFile() {
    if (remove(filename.c_str()) != 0) {
        cerr << "Error: Could not delete the file." << endl;
    } else {
        cout << "Roster file deleted successfully." << endl;
    }
}

vector<Runner> Roster::getRoster() {
    return roster;
}

bool Roster::runnerExists(string fn, string ln, string mail) {
    for (auto runner : roster) {
        if ((runner.getFirstName() == fn && runner.getLastName() == ln) || (runner.getEmail() == mail)) {
            return true;
        }
    }

    return false;
}

bool Roster::addRunner(string fn, string ln, string dateOfBirth, string gen, string mail, string time, double amount) {
    if (!validateRunner(fn, ln, dateOfBirth, gen, mail, time)) {
        return false;
    }

    if (runnerExists(fn, ln, mail)) {
        cerr << "Sign up failed. User is already registered." << endl;
        return false;
    }

    Runner current(fn, ln, dateOfBirth, gen, mail, time, race, amount);
    roster.push_back(current);
    saveRosterToFile();
    return true;
}

void Roster::printRunner(string firstName, string lastName) {
    bool runnerFound = false;

    for (auto runner : roster) {
        if (runner.getFirstName() == firstName && runner.getLastName() == lastName) {
            cout << "User found in the " << race << " roster. Here is the information:" << endl;
            cout << "First Name: " << runner.getFirstName() << endl;
            cout << "Last Name: " << runner.getLastName() << endl;
            cout << "Age on Race Day: " << runner.getAgeOnRaceDay() << endl;
            cout << "Gender: " << runner.getGender() << endl;
            cout << "Email Address: " << runner.getEmail() << endl;
            cout << "Registration Timestamp: " << runner.getRegistrationTimestamp() << endl;
            cout << "Amount Paid: $" << runner.getAmountPaid() << endl;
            runnerFound = true; // don't break out of loop in case there are multiple users with the same name
        }
    }

    if (runnerFound == false) {
        cerr << "User was not found in the " << race << " roster." << endl;
    }
}

pair<int, Runner*> Roster::getAmountPaidAndRunner(string fn, string ln, string mail) {
    for (auto& runner : roster) { 
        if ((runner.getFirstName() == fn && runner.getLastName() == ln) || (runner.getEmail() == mail)) {
            return {runner.getAmountPaid(), &runner}; 
        }
    }

    return {0, nullptr};
}

int Roster::getRosterSize() {
    return roster.size();
}

void Roster::clearRoster() {
    roster.clear();
}

void Roster::printRoster() {
    int widthFirstName = 14;
    int widthLastName = 13;
    int widthAge = 5;
    int widthGender = 9;
    int widthEmail = 0;
    int widthRegTimestamp = 20;
    int widthAmtPaid = 10;

    for (auto runner : roster) {
        int runnerFirst = runner.getFirstName().length() + 3;
        int runnerLast = runner.getLastName().length() + 3;
        int runnerEmail = runner.getEmail().length() + 3;

        if (runnerFirst > widthFirstName) {
            widthFirstName = runnerFirst + 3;
        }

        if (runnerLast > widthLastName) {
            widthLastName = runnerLast + 3;
        }

        if (runnerEmail > widthEmail) {
            widthEmail = runnerEmail + 3;
        }
    }

    cout << "Here is the " << race << " roster:\n" << endl;
    cout << left 
         << setw(widthFirstName) << "First Name" 
         << setw(widthLastName) << "Last Name" 
         << setw(widthAge) << "Age" 
         << setw(widthGender) << "Gender" 
         << setw(widthEmail) << "Email Address" 
         << setw(widthRegTimestamp) << "Reg Timestamp" 
         << setw(widthAmtPaid) << "Amt Paid" 
         << endl;

    cout << string(widthFirstName + widthLastName + widthAge + widthGender + widthEmail + 
        widthRegTimestamp + widthAmtPaid, '-') << endl;

    for (auto runner : roster) {
        cout << left 
             << setw(widthFirstName) << runner.getFirstName()
             << setw(widthLastName) << runner.getLastName()
             << setw(widthAge) << runner.getAgeOnRaceDay()
             << setw(widthGender) << runner.getGender()
             << setw(widthEmail) << runner.getEmail()
             << setw(widthRegTimestamp) << runner.getRegistrationTimestamp()
             << "$" << setw(widthAmtPaid) << fixed << setprecision(2) << runner.getAmountPaid()
             << endl;
    }

    cout << string(widthFirstName + widthLastName + widthAge + widthGender + widthEmail + 
        widthRegTimestamp + widthAmtPaid, '-') << endl;
    cout << "There are " << getRosterSize() << " runners registered for this race" << endl;
}