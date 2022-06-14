#include <bits/stdc++.h>

using namespace std;

class Solution
{

  public:
    int char_to_int(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            break;
        }
        return 0;
    }
    int romanToInt(string s)
    {
        int res = 0;
        int len = s.length(), i;
        for (i = 0; i < len - 1; i++)
        {
            if (s[i] == 'I')
            {
                i++;
                if (s[i] == 'V')
                    res += 4;
                else if (s[i] == 'X')
                    res += 9;
                else
                {
                    res += 1;
                    i--;
                }
            }
            else if (s[i] == 'V')
                res += 5;
            else if (s[i] == 'X')
            {
                i++;
                if (s[i] == 'L')
                    res += 40;
                else if (s[i] == 'C')
                    res += 90;
                else
                {
                    res += 10;
                    i--;
                }
            }
            else if (s[i] == 'L')
                res += 50;
            else if (s[i] == 'C')
            {
                i++;
                if (s[i] == 'D')
                    res += 400;
                else if (s[i] == 'M')
                    res += 900;
                else
                {
                    res += 100;
                    i--;
                }
            }
            else if (s[i] == 'D')
                res += 500;
            else if (s[i] == 'M')
                res += 1000;
        }
        if (i == len - 1)
            res += char_to_int(s[i]);
        return res;
    }
};

int main()
{
    return 0;
}