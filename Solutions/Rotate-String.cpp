#include <cstring>
#include <iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        string str = s + s;
        return s.size() == goal.size() && str.find(goal.c_str()) != string::npos;
    }
};