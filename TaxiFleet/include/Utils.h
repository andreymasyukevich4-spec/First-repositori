#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <string>
#include <ctime>

using namespace std;

const int MIN_YEAR = 1900;
const int MAX_YEAR_OFFSET = 1900;

inline void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

inline string readString(const string& prompt) {
    string result;
    cout << prompt;
    while (true) {
        getline(cin, result);
        if (!result.empty()) return result;
        cout << "Error: empty string. Try again: ";
    }
}

inline int getCurrentYear() {
    time_t t = time(nullptr);
    tm timeInfo{};
    
    #ifdef _WIN32
        if (localtime_s(&timeInfo, &t) != 0) return MIN_YEAR;
    #else
        if (localtime_r(&t, &timeInfo) == nullptr) return MIN_YEAR;
    #endif
    
    return timeInfo.tm_year + MAX_YEAR_OFFSET;
}

inline int readYear(const string& prompt) {
    int currentYear = getCurrentYear();
    int y;
    while (true) {
        cout << prompt;
        if (cin >> y && y >= MIN_YEAR && y <= currentYear) {
            clearInput();
            return y;
        }
        cout << "Error! Enter a valid year (" << MIN_YEAR << "-" << currentYear << "): ";
        clearInput();
    }
}

inline int readPositiveInt(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && val > 0) {
            clearInput();
            return val;
        }
        cout << "Error! Number must be greater than 0: ";
        clearInput();
    }
}

inline int readIndex(const string& prompt, int maxSize) {
    int idx;
    while (true) {
        cout << prompt;
        if (cin >> idx && idx >= 0 && idx < maxSize) {
            clearInput();
            return idx;
        }
        cout << "Error! Enter index from 0 to " << maxSize - 1 << ": ";
        clearInput();
    }
}

inline int readBool(const string& prompt) {
    int val;
    while (true) {
        cout << prompt;
        if (cin >> val && (val == 0 || val == 1)) {
            clearInput();
            return val;
        }
        cout << "Error! Enter 0 or 1: ";
        clearInput();
    }
}

#endif