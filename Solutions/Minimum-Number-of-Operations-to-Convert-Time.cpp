#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    int convertTime(string current, string correct)
    {
        int hour1 = stol(current.substr(0, 2)), minute1 = stol(current.substr(3, 2));
        int hour2 = stol(correct.substr(0, 2)), minute2 = stol(correct.substr(3, 2));
        int diff = (hour2 - hour1) * 60 + (minute2 - minute1), tot = 0;

        tot += diff / 60;
        diff %= 60;
        tot += diff / 15;
        diff %= 15;
        tot += diff / 5;
        diff %= 5;
        tot += diff / 1;
        diff %= 1;
        return tot;
    }
};