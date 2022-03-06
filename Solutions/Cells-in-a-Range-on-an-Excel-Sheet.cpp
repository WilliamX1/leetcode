#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        int pos = s.find(':');
        char c1 = s[0], c2 = s[pos + 1];
        int r1 =  stoi(s.substr(1, pos - 1)), r2 = stoi(s.substr(pos + 2));
        vector<string> ans;
        for (char i = c1; i <= c2; i++)
            for (int j = r1; j <= r2; j++) {
                string str;
                str.push_back(i);
                str.append(to_string(j));
                ans.push_back(str);
            };
        return ans;
    }
};