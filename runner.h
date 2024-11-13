#pragma once
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class Runner {
    private:
        string firstName;
        string lastName;
        int ageOnRaceDay;
        string gender;
        string email;
        string registrationTimestamp;
        double amountPaid;
        string removeSpaces(string);

    public:
        Runner(); // Default constructor
        Runner(string, string, string, string, string, string, string, double);
        void serialize(ofstream&) const;
        void deserialize(ifstream&);
        string getFirstName();
        string getLastName();
        int getAgeOnRaceDay();
        string getGender();
        string getEmail();
        string getRegistrationTimestamp();
        double getAmountPaid();
        void setAmountPaid(int);
};
