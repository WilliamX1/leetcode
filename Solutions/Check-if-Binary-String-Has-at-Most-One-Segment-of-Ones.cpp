#include <cstring>
#include <iostream>

using namespace std;

class Solution
{
  public:
    bool checkOnesSegment(string s)
    {
        bool find = false;
        int i = 0, n = s.size();
        while (i < n)
        {
            if (!find)
            {
                if (s[i] == '1')
                {
                    find = true;
                    while (i < n && s[i] == '1')
                        i++;
                };
            }
            else if (s[i] == '1')
                return false;
            else
                i++;
        };
        return true;
    }
};