#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "", tmp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ans.append(tmp + ' ');
                tmp = "";
            } else {
                tmp = s[i] + tmp;
            };
        };
        ans.append(tmp); 
        return ans;
    }
};