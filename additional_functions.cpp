#include "Additional_functions.h"

string trimFloatString(const string& str) {
    size_t dotPos = str.find('.');
    if (dotPos != string::npos) {
        size_t lastNonZero = str.find_last_not_of('0');
        if (lastNonZero != string::npos && lastNonZero > dotPos) {
            return str.substr(0, lastNonZero + 1);
        } else {
            return str.substr(0, dotPos);
        }
    }
    return str;
}