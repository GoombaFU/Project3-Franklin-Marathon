#pragma once
#include <string>
#include <fstream>

using namespace std;

class Runner {
    private:
        string firstName;
        string lastName;
        int ageOnRaceDay;
        string gender;
        string email;
        string registrationTimestamp;
        int amountPaid;
        string removeSpaces(string);

    public:
        Runner(); // Default constructor
        Runner(string, string, string, string, string, string, string, int);
        void serialize(ofstream&) const;
        void deserialize(ifstream&);
        string getFirstName();
        string getLastName();
        int getAgeOnRaceDay();
        string getGender();
        string getEmail();
        string getRegistrationTimestamp();
        int getAmountPaid();
        void setAmountPaid(int);
};
