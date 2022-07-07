#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    int countCharacters(vector<string> &words, string chars)
    {
        unordered_map<char, int> count;
        for (const char &ch : chars)
            count[ch]++;

        int ans = 0;
        for (const string &word : words)
        {
            unordered_map<char, int> tt = count;
            bool flag = true;
            for (const char &ch : word)
            {
                tt[ch]--;
                if (tt[ch] < 0)
                {
                    flag = false;
                    break;
                };
            };
            ans += flag ? word.size() : 0;
        };
        return ans;
    }
};