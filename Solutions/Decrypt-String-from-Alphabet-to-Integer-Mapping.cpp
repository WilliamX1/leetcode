#include <string>
#include <cstring>

using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        string ans;
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '#') {
                ans += char(((s[i - 2] - '0') * 10 + (s[i - 1] - '0') - 1) + 'a');
                i -= 2;
            } else ans += char((s[i] - '0' - 1) + 'a');
        };
        reverse(ans.begin(), ans.end());
        return ans;
    }
};