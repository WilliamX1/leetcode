#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> _map;
        int left = 0, right = 0, len = s.length(), ans = 0;

        while (right < len)
        {
            if (_map.find(s[right]) == _map.end())
                _map[s[right]] = right;
            else {
                if (right - left > ans) ans = right - left;
                if (_map[s[right]] + 1 > left) left = _map[s[right]] + 1;
                _map[s[right]] = right;
            };
            right++;
        };
        if (right - left > ans) ans = right - left;
        return ans;
    }
};

int main()
{
    Solution S;
    S.lengthOfLongestSubstring("abba");
    return 0;
}