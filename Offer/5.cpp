#include <bits/stdc++.h>

using namespace std;

class Solution
{
  public:
    string replaceSpace(string s)
    {
        vector<int> idxlist;
        idxlist.push_back(-1);
        for (int i = 0; i < s.size(); i++)
            if (s[i] == ' ')
                idxlist.push_back(i);
        string res = "";
        for (int i = 1; i < idxlist.size(); i++)
            res += s.substr(idxlist[i - 1] + 1, idxlist[i] - idxlist[i - 1] - 1) + "%20";
        res += s.substr(idxlist.back() + 1, s.size() - idxlist.back() - 1);
        return res;
    }
};