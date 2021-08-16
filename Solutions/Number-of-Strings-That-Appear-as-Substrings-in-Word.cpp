class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0, _size = word.size();
        for (auto str : patterns)
        {
            int len = str.length();
            if (len <= _size) {
                int start = 0;
                while (start <= _size - len)
                {
                    while (start < _size && word[start] != str[0]) start++;
                    if (word.substr(start, len) == str) {
                        ans++;
                        break;
                    } else start++;
                };
            };
        };
        return ans;
    }
};