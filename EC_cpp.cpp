#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

double extractNumeric(const string& str) {
    double num = 0.0;
    double sign = 1.0;
    size_t i = 0;

    // Handle sign
    if (str[i] == '-') {
        sign = -1.0;
        i++;
    } else if (str[i] == '+') {
        i++;
    }

    // Parse integer part
    bool hasDigits = false; // Flag to ensure at least one digit exists
    while (i < str.size() && isdigit(str[i])) {
        hasDigits = true;
        num = num * 10 + (str[i] - '0');
        i++;
    }

    // Parse decimal part
    if (i < str.size() && str[i] == '.') {
        i++;
        double divisor = 10.0;

        while (i < str.size() && isdigit(str[i])) {
            hasDigits = true;
            num += (str[i] - '0') / divisor;
            divisor *= 10;
            i++;
        }
    }

    // Check for invalid characters
    if (i < str.size() || !hasDigits) {
        return -999999.99; // Invalid input
    }

    return num * sign;
}

int main() {
    cout << "C++ code" << endl;

    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                 << number << endl;
        } else {
            cout << "The input is invalid." << endl;
        }
    }

    return 0;
}
