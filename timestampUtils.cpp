#include "timestampUtils.h"

string timestampUtils::getCurrentTimeInEST() {
    auto now = system_clock::now();
    time_t currentTime = system_clock::to_time_t(now);

    tm* timeInfo = gmtime(&currentTime);

    if (timeInfo->tm_isdst > 0) {
        // daylight savings time is in effect
        timeInfo->tm_hour -= 4;
    } 
    else {
        timeInfo->tm_hour -= 5; 
    }

    mktime(timeInfo);  // normalizes the tm structure

    ostringstream oss;
    oss << put_time(timeInfo, "%Y%m%d %H:%M:%S");

    return oss.str();
}

string timestampUtils::getCustomTimeInEST(time_t customTime) {
    tm* timeInfo = gmtime(&customTime);

    if (timeInfo->tm_isdst > 0) {
        // daylight savings time is in effect
        timeInfo->tm_hour -= 4;
    } 
    else {
        timeInfo->tm_hour -= 5;
    }

    mktime(timeInfo); // normalizes the tm structure

    ostringstream oss;
    oss << put_time(timeInfo, "%Y%m%d %H:%M:%S");

    return oss.str();
}

void timestampUtils::testDST(string timestampDST, string timestampEST) {
    // DST timestamp
    int yearDST = stoi(timestampDST.substr(0, 4));
    int monthDST = stoi(timestampDST.substr(4, 2));
    int dayDST = stoi(timestampDST.substr(6, 2));
    int hourDST = stoi(timestampDST.substr(9, 2));
    int minuteDST = stoi(timestampDST.substr(12, 2));
    int secondDST = stoi(timestampDST.substr(15, 2));

    tm dstTime = {};
    dstTime.tm_year = yearDST - 1900; 
    dstTime.tm_mon = monthDST - 1;            
    dstTime.tm_mday = dayDST;          
    dstTime.tm_hour = hourDST;         
    dstTime.tm_min = minuteDST;
    dstTime.tm_sec = secondDST;
    time_t dstTestTime = mktime(&dstTime);
    cout << "DST timestamp: " << getCustomTimeInEST(dstTestTime) << endl;

    // EST timestamp
    int yearEST = stoi(timestampEST.substr(0, 4));
    int monthEST = stoi(timestampEST.substr(4, 2));
    int dayEST = stoi(timestampEST.substr(6, 2));
    int hourEST = stoi(timestampEST.substr(9, 2));
    int minuteEST = stoi(timestampEST.substr(12, 2));
    int secondEST = stoi(timestampEST.substr(15, 2));
    
    tm estTime = {};
    estTime.tm_year = yearEST - 1900;  
    estTime.tm_mon = monthEST - 1;            
    estTime.tm_mday = dayEST;          
    estTime.tm_hour = hourEST;          
    estTime.tm_min = minuteEST;
    estTime.tm_sec = secondEST;
    time_t estTestTime = mktime(&estTime);
    cout << "EST timestamp: " << getCustomTimeInEST(estTestTime) << endl;
}

bool timestampUtils::validateTimestamp(string timestamp) {
    int year = stoi(timestamp.substr(0, 4));
    int month = stoi(timestamp.substr(4, 2));
    int day = stoi(timestamp.substr(6, 2));
    int hour = stoi(timestamp.substr(9, 2));
    int minute = stoi(timestamp.substr(12, 2));
    int second = stoi(timestamp.substr(15, 2));

    tm timeInfo = {};
    timeInfo.tm_year = year - 1900; 
    timeInfo.tm_mon = month - 1;   
    timeInfo.tm_mday = day;
    timeInfo.tm_hour = hour;
    timeInfo.tm_min = minute;
    timeInfo.tm_sec = second;

    // disable DST by setting tm_isdst to 0 (prevents DST issues for timestamp)
    timeInfo.tm_isdst = -1;

    if (mktime(&timeInfo) == -1) {
        return false;
    }

    // for leap year
    if (timeInfo.tm_year != year - 1900 || timeInfo.tm_mon != month - 1 || timeInfo.tm_mday != day) {
        return false;
    }

    return true;
}

bool timestampUtils::validateDateOfBirth(string dateOfBirth) {
    int year = stoi(dateOfBirth.substr(0, 4));
    int month = stoi(dateOfBirth.substr(4, 2));
    int day = stoi(dateOfBirth.substr(6, 2));

    tm timeInfo = {};
    timeInfo.tm_year = year - 1900; 
    timeInfo.tm_mon = month - 1;   
    timeInfo.tm_mday = day;

    // disable DST by setting tm_isdst to 0 (prevents DST issues for timestamp)
    timeInfo.tm_isdst = -1;

    if (mktime(&timeInfo) == -1) {
        return false;
    }

    // for leap year
    if (timeInfo.tm_year != year - 1900 || timeInfo.tm_mon != month - 1 || timeInfo.tm_mday != day) {
        return false;
    }

    return true;
}

string timestampUtils::calculateTDay(int year) {
    tm tday = {};
    tday.tm_year = year - 1900;
    tday.tm_mon = 4;
    tday.tm_mday = 1;
    tday.tm_isdst = -1;      
    mktime(&tday);

    tday.tm_mday = (1 + (6 - tday.tm_wday) % 7) - 2; 
    mktime(&tday); 

    ostringstream oss;
    oss << put_time(&tday, "%Y%m%d %H:%M:%S");

    return oss.str();
}

tm timestampUtils::getTDay(int year) {
    tm tDay = {};
    tDay.tm_year = year - 1900;
    tDay.tm_mon = 4;
    tDay.tm_mday = 1;
    tDay.tm_isdst = -1;      
    mktime(&tDay);

    tDay.tm_mday = (1 + (6 - tDay.tm_wday) % 7) - 2; 
    mktime(&tDay); 

    return tDay;
}

tm timestampUtils::getSaturdayRaceDay(int year) {
    tm raceDay = {};
    raceDay.tm_year = year - 1900;
    raceDay.tm_mon = 4;
    raceDay.tm_mday = 1;
    raceDay.tm_isdst = -1;      
    mktime(&raceDay);

    raceDay.tm_mday = (1 + (6 - raceDay.tm_wday) % 7); 
    mktime(&raceDay); 

    return raceDay;
}

tm timestampUtils::getSundayRaceDay(int year) {
    tm raceDay = {};
    raceDay.tm_year = year - 1900;
    raceDay.tm_mon = 4;
    raceDay.tm_mday = 1;
    raceDay.tm_isdst = -1;      
    mktime(&raceDay);

    raceDay.tm_mday = (1 + (6 - raceDay.tm_wday) % 7) + 1; 
    mktime(&raceDay); 

    return raceDay;
}

string timestampUtils::getRaceCalendarPeriod(string timestamp) {
    if (!validateTimestamp(timestamp)) {
        return "Timestamp failed. Invalid date.";
    }

    int year = stoi(timestamp.substr(0, 4));
    int month = stoi(timestamp.substr(4, 2));
    int day = stoi(timestamp.substr(6, 2));

    tm tDay = getTDay(year);

    if (month >= 6 && month <= 9) {
        return "Not Open";
    }
    else if (month == 10) {
        return "Super Early";
    }
    else if (month == 11 || month == 12 || month <= 2) {
        return "Early";
    }
    else if (month == 3 || (month == 4 && day == 1)) {
        return "Baseline";
    }
    else if (month == 4 && day >= 2) {
        if (day < tDay.tm_mday) {
            return "Late";
        } 
        else if (day > tDay.tm_mday && month == tDay.tm_mon) { // Saying month is april, TDay month is may
            return "Late";
        }
        else {
            return "Closed";
        }
    }
    else if (month == 5 && day <= 31) {
        if (day >= tDay.tm_mday) {
            return "Closed";
        } 
        else {
            return "Late";
        }
    }
    else {
        return "Timestamp failed to find a registration period.";
    }
}

pair<int, int> timestampUtils::calculateAgeOnRaceDay(string dOB, int yearOfRace) {
    if (!validateDateOfBirth(dOB)) {
        cerr << "Error: Date of birth is not valid.";
    }

    int year = stoi(dOB.substr(0, 4));
    int month = stoi(dOB.substr(4, 2));
    int day = stoi(dOB.substr(6, 2));

    tm dateOfBirth = {};
    dateOfBirth.tm_year = year - 1900; 
    dateOfBirth.tm_mon = month - 1;   
    dateOfBirth.tm_mday = day;
    dateOfBirth.tm_hour = 0;

    tm saturdayRace = getSaturdayRaceDay(yearOfRace);
    tm sundayRace = getSundayRaceDay(yearOfRace);

    int age = yearOfRace - year;

    int ageOnSaturday = age;
    if (dateOfBirth.tm_mon > saturdayRace.tm_mon) {
        ageOnSaturday--;
    }
    else if (dateOfBirth.tm_mon == saturdayRace.tm_mon) {
        if (dateOfBirth.tm_mday > saturdayRace.tm_mday) {
            ageOnSaturday--;
        }
    }

    int ageOnSunday = age;
    if (dateOfBirth.tm_mon > sundayRace.tm_mon) {
        ageOnSunday--;
    }
    else if (dateOfBirth.tm_mon == sundayRace.tm_mon) {
        if (dateOfBirth.tm_mday > sundayRace.tm_mday) {
            ageOnSunday--;
        }
    }

    return make_pair(ageOnSaturday, ageOnSunday);
}