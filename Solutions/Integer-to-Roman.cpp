#include <bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    string romaint_to_string(int x)
    {
        switch (x)
        {
        case 1:
            return "I";
        case 4:
            return "IV";
        case 5:
            return "V";
        case 9:
            return "IX";
        case 10:
            return "X";
        case 40:
            return "XL";
        case 50:
            return "L";
        case 90:
            return "XC";
        case 100:
            return "C";
        case 400:
            return "CD";
        case 500:
            return "D";
        case 900:
            return "CM";
        case 1000:
            return "M";
        default:
            return "";
        }
    }
    string intToRoman(int num)
    {
        string res = "";
        vector<int> arr = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int idx = 0, length = arr.size(), cnt, tmp;

        for (; idx < length; idx++)
        {
            tmp = arr[idx];
            cnt = num / tmp;
            num %= tmp;
            for (int i = 0; i < cnt; i++)
                res += this->romaint_to_string(tmp);
        };
        return res;
    }
};
