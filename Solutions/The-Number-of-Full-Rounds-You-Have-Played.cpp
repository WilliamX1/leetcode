#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int start_hour = stoi(startTime.substr(startTime.find_first_of('"') + 1, 2));
        int start_min = ceil(stod(startTime.substr(startTime.find_first_of(':') + 1, 2)) / 15);
        int end_hour = stoi(finishTime.substr(finishTime.find_first_of('"') + 1, 2));
        int end_min = stoi(finishTime.substr(finishTime.find_first_of(':') + 1, 2)) / 15;

        int ans = (end_hour - start_hour) * 4 + (end_min - start_min);
        return ans >= 0 ? ans : 96 + ans;
    }
};