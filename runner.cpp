#include "runner.h"
#include "timestampUtils.h"

Runner::Runner() {
    ageOnRaceDay = 0;
}

Runner::Runner(string fn, string ln, string dateOfBirth, string gen, string mail, string time, string race, int money) {
    firstName = removeSpaces(fn);
    lastName = removeSpaces(ln);

    timestampUtils tsu;
    int yearOfRace = stoi(time.substr(0, 4));
    pair<int, int> ages = tsu.calculateAgeOnRaceDay(dateOfBirth, yearOfRace);
    ageOnRaceDay = ages.first;

    if (race == "5K" || race == "10K") {
        ageOnRaceDay = ages.first;
    }
    else {
        ageOnRaceDay = ages.second;
    }

    gender = gen; // Doesnt need to remove spaces due to validateRunner function
    email = removeSpaces(mail);
    registrationTimestamp = time;
    amountPaid = money;
}

string Runner::removeSpaces(string input) {
    string output;

    for (char ch : input) {
        if (!isspace(ch)) {
            output.push_back(ch);
        }
    }

    return output;
}

void Runner::serialize(ofstream& out) const {
    size_t len;

    len = firstName.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(firstName.c_str(), len);

    len = lastName.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(lastName.c_str(), len);

    out.write(reinterpret_cast<const char*>(&ageOnRaceDay), sizeof(ageOnRaceDay));

    len = gender.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(gender.c_str(), len);

    len = email.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(email.c_str(), len);

    len = registrationTimestamp.size();
    out.write(reinterpret_cast<const char*>(&len), sizeof(len));
    out.write(registrationTimestamp.c_str(), len);
}


void Runner::deserialize(ifstream& in) {
    size_t len;
    char* buffer;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    firstName = buffer;
    delete[] buffer;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    lastName = buffer;
    delete[] buffer;

    in.read(reinterpret_cast<char*>(&ageOnRaceDay), sizeof(ageOnRaceDay));

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    gender = buffer;
    delete[] buffer;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    email = buffer;
    delete[] buffer;

    in.read(reinterpret_cast<char*>(&len), sizeof(len));
    buffer = new char[len + 1];
    in.read(buffer, len);
    buffer[len] = '\0';
    registrationTimestamp = buffer;
    delete[] buffer;
}

string Runner::getFirstName() {
    return firstName;
}

string Runner::getLastName() {
    return lastName;
}

int Runner::getAgeOnRaceDay() {
    return ageOnRaceDay;
}

string Runner::getGender() {
    return gender;
}

string Runner::getEmail() {
    return email;
}

string Runner::getRegistrationTimestamp() {
    return registrationTimestamp;
}

int Runner::getAmountPaid() {
    return amountPaid;
}

void Runner::setAmountPaid(int amount) {
    amountPaid = amount;
}