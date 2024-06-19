// Підключення хедр файлу Additional_functions, де написані функції, які треба визначити, надати тіло.
#include "Additional_functions.h"

// Відкидання всіх нулів після крапки, якщо далі немає інших символів крім нуля
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