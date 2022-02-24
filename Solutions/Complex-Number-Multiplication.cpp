#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1 = stoi(num1.substr(0, num1.find('+'))), a2 = stoi(num2.substr(0, num2.find('+')));
        int b1 = stoi(num1.substr(num1.find('+') + 1, num1.find('i') - num1.find('+') - 1)), b2 = stoi(num2.substr(num2.find('+') + 1, num2.find('i') - num2.find('+') - 1));
        int a3 = a1 * a2 - b1 * b2, b3 = a1 * b2 + a2 * b1;
        string str = to_string(a3) + "+" + to_string(b3) + "i";
        return str; 
    }
};