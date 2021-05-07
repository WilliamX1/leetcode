class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        for (int i = 0; ; i++)
        {
            char tmp;
            if (strs[0].size() > i) tmp = strs[0][i];
            else break;

            for (int j = 1; j < strs.size(); j++)
                if (strs[j].size() <= i || strs[j][i] != tmp) return ans;
            ans = ans + strs[0][i];
        }
        return ans;
    }
};