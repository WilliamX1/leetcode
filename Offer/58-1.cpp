class Solution {
public:
    string reverseWords(string s) {
        s = ' ' + s + ' ';
        int left = 0, _len_ = s.size();
        while (_len_ > 0 && s[_len_ - 1] == ' ') _len_--;
        _len_++;

        while (left < _len_ && s[left] == ' ') left++;
        int right = left + 1;
        vector<string> v;
        while (right < _len_) {
            while (right < _len_ && s[right] != ' ') right++;
            if (right < _len_) v.push_back(s.substr(left, right - left));
            left = right;
            while (left < _len_ && s[left] == ' ') left++;
            right = left;
        };
        string ans = "";
        for (auto& str : v) 
            ans = str + ' ' + ans;
        ans = ans.substr(0, ans.size() - 1);
        return ans;
    }
};