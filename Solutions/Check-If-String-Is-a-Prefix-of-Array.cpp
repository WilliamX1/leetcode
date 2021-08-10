class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        for (auto word : words)
        {
            if (s == "") break;
            int len = word.size();
            if (len <= s.size() && s.substr(0, len) == word) s = s.substr(len);
            else return false;
        };
        return s == "";
    };
};