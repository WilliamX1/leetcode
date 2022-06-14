#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
  public:
    string mergeAlternately(string word1, string word2)
    {
        int idx1 = 0, idx2 = 0;
        string ans;
        while (idx1 < word1.size() && idx2 < word2.size())
        {
            ans.push_back(word1[idx1++]);
            ans.push_back(word2[idx2++]);
        };
        while (idx1 < word1.size())
            ans.push_back(word1[idx1++]);
        while (idx2 < word2.size())
            ans.push_back(word2[idx2++]);
        return ans;
    }
};