class Solution {
public:
    string removeOccurrences(string s, string part) {
        int len = part.length();
        while (true) {
            int start_idx = s.find(part);
            if (start_idx == string::npos) break;
            else {
                s = s.substr(0, start_idx) + s.substr(start_idx + len);
            };
        };
        return s;
    }
};