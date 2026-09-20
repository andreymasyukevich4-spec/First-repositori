#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <limits>
#include <string>

using namespace std;

const int MIN_YEAR = 2000;
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
        cout << "Oshibka: pustaya stroka. Vvedite snova: ";
    }
}

inline int getCurrentYear() {
    time_t t = time(nullptr);
    tm timeInfo;
    
    #ifdef _WIN32
        localtime_s(&timeInfo, &t);
        #else
        localtime_r(&t, &timeInfo);
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
        cout << "Oshibka! Vvedite korrektniy god (" << MIN_YEAR << "-" << currentYear << "): ";
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
        cout << "Oshibka! Chislo dolzhno byt bolshe 0: ";
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
        cout << "Oshibka! Vvedite index ot 0 do " << maxSize - 1 << ": ";
        clearInput();
    }
}

#endif