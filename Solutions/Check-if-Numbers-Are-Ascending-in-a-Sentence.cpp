class Solution {
public:
    bool areNumbersAscending(string s) {
        int num = -1;
        string str;
        s.push_back(' ');
        for (const char ch : s) {
            if (ch != ' ')
                str.push_back(ch);
            else {
                if ('0' <= str.front() && str.front() <= '9') {
                    int c = stol(str);
                    if (c <= num) return false;
                    else num = c;
                };
                str.clear();
            };
        };
        return true;
    }
};