#include <iostream>
#include <string>
#include <algorithm>
#include<cmath>

using namespace std;

string karatsuba(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();

    // If either input is zero, the result is zero
    if (len1 == 0 || len2 == 0) {
        return "0";
    }

    // If either input is a single digit, perform standard multiplication
    if (len1 == 1 || len2 == 1) {
        return to_string(stoi(num1) * stoi(num2));
    }

    // Calculate the half size of the larger input
    int m = max(len1, len2);
    int m2 = m / 2;

    // Split each input into two parts of size m/2
    string high1 = num1.substr(0, len1 - m2);
    string low1 = num1.substr(len1 - m2, m2);
    string high2 = num2.substr(0, len2 - m2);
    string low2 = num2.substr(len2 - m2, m2);

    // Recursively compute the three products needed
    string z0 = karatsuba(low1, low2);
    string z1 = karatsuba(high1, high2);
    string z2 = karatsuba(to_string(stoi(low1) + stoi(high1)), to_string(stoi(low2) + stoi(high2)));

    // Calculate the final result using the three products
    return to_string(stoi(z0) * (int)pow(10, 2 * m2) + (stoi(z2) - stoi(z1) - stoi(z0)) * (int)pow(10, m2) + stoi(z1));
}

int main() {
    string num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    cout << "Result: " << karatsuba(num1, num2) << endl;

    return 0;
}
